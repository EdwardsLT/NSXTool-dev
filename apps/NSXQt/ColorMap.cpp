/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2016- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
          Jonathan Fisher, Forschungszentrum Juelich GmbH
    BP 156
    6, rue Jules Horowitz
    38042 Grenoble Cedex 9
    France
    chapon[at]ill.fr
    pellegrini[at]ill.fr
    j.fisher[at]fz-juelich.de

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include "ColorMap.h"
#include <ctime>
#include <cmath>
#include <array>

ColorMap::ColorMap(const double *rgb):
    _rgb(new double[256*3]),
    _log_rgb(new double[256*3])

{
    std::memcpy(_rgb, rgb, 256*3*sizeof(double));
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

ColorMap::ColorMap(const std::string &name):
    ColorMap(getColorMap(name))
{

}

ColorMap::ColorMap():
    ColorMap(getColorMapNames().front())
{

}

ColorMap::~ColorMap()
{
    if (_log_rgb)
        delete[] _log_rgb;

    if (_rgb)
        delete[] _rgb;
}

QImage ColorMap::matToImage(const Eigen::MatrixXi& source, const QRect& rect, int colorMax, bool log)
{
    // invalid rectangle: early return
    if (rect.left() < 0 || rect.top() < 0)
        return QImage();

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
                destrow[x-xmin] = log_color(source(y, x), colorMax);
            else
                destrow[x-xmin] = color(source(y, x), colorMax);
        }
    }

    return dest;
}


