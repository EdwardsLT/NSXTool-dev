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

QImage Mat2QImage(int* src, int rows, int cols,int xmin, int xmax, int ymin, int ymax, int colorMax, bool log)
{
    if (xmin<0 || xmax> cols || ymin<0 || ymax>rows)
        return QImage();

    QImage dest(cols, rows, QImage::Format_RGB32);

    src += ymin*cols;

    for (int y = ymin; y <= ymax; ++y) {
        QRgb* destrow = (QRgb*)(dest.scanLine(y-ymin));
        int x;
        for (x = xmin; x <= xmax; ++x) {
            int val = *(src+x);

            if (log) {
                destrow[x-xmin] = ColorMap(std::log(val), colorMax);
            }
            else
                destrow[x-xmin] = BlueWhite(val, colorMax);
        }
        src+=cols;
    }
    return dest;
}
