#include <cmath>

#include <QImage>

#include "ColorMap.h"

ColorMap::ColorMap(const double *rgb) : _rgb(256*3, 0), _log_rgb(256*3, 0)
{
    std::memcpy(&_rgb[0], rgb, 256*3*sizeof(double)); // warning: this might be dangerous
    const double ilog2 = 1.0 / std::log(2.0);

    for (unsigned int i = 0; i < 256; ++i) {
        const double t = (1.0 + i / 256.0);
        const double x = std::log(t) * ilog2 * 255.0;
        const unsigned int a = static_cast<unsigned int>(x);
        const unsigned int b = std::min(a+1, 255u);
        const double eps = t-a;

        for (unsigned int j = 0; j < 3; ++j) {
            _log_rgb[3*i+j] = (1-eps)*_rgb[3*a+j] + eps*_rgb[3*b+j];
        }
    }
}

ColorMap::ColorMap(const std::string &name) : ColorMap(colorMap(name))
{
}

ColorMap::ColorMap() : ColorMap("blue white")
{
}

QRgb ColorMap::color(double v, double vmax)
{
    int i = int(v/vmax*255.0);
    i = std::max(0, i);
    i = std::min(255, i);

    return qRgb(_rgb[3*i+0], _rgb[3*i+1], _rgb[3*i+2]);
}

QRgb ColorMap::logColor(double v, double vmax)
{
    double t = std::max(v/vmax*255.0, 0.0);
    int i = std::min(255, int(t+0.5));

    return qRgb(_log_rgb[3*i+0], _log_rgb[3*i+1], _log_rgb[3*i+2]);
}


QImage ColorMap::matToImage(const Eigen::ArrayXXd &source, const QRect &rect, double colorMax, bool log)
{
    // invalid rectangle: early return
    if (rect.left() < 0 || rect.top() < 0) {
        return QImage();
    }

    if (std::abs(colorMax) < 1.0e-9) {
        return QImage();
    }

    const int rows = int(source.rows());
    const int cols = int(source.cols());

    const int xmin = rect.left();
    const int xmax = rect.right();
    const int ymin = rect.top();
    const int ymax = rect.bottom();

    // invalid rectangle: early return
    if (xmax > cols || ymax > rows)
        return QImage();

    QImage dest(cols, rows, QImage::Format_RGB32);

    for (int y = ymin; y <= ymax; ++y) {
        QRgb* destrow = reinterpret_cast<QRgb*>(dest.scanLine(y-rect.top()));

        for (int x = xmin; x <= xmax; ++x) {
            if (log)
                destrow[x-xmin] = logColor(source(y, x), colorMax);
            else
                destrow[x-xmin] = color(source(y, x), colorMax);
        }
    }

    return dest;
}
