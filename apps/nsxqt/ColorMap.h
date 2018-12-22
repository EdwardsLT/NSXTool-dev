#pragma once

#include <cmath>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include <QColor>
#include <QImage>
#include <QRect>

class ColorMap {
public:

    ColorMap();

    ColorMap(const std::string& name);

    ColorMap(const double* rgb);

    QRgb color(double v, double vmax);

    QRgb logColor(double v, double vmax);

    QImage matToImage(const Eigen::ArrayXXd& source, const QRect& rect, double colorMax, bool log=false);

    static ColorMap colorMap(const std::string& name);
    static std::vector<std::string> colorMaps();

private:
    std::vector<double> _rgb;
    std::vector<double> _log_rgb;
};
