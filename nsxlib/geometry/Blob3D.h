// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/Blob3D.h
//! @brief     Implements module/class/test Blob3D
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <iostream>

#include <Eigen/Dense>

namespace nsx {

/**
 * \class Blob3D
 * \brief Class Blob3D.
 * Blob3D are used to store region of interest in a 3D image.
 * A Blob is constructed by adding points in the image with coordinates x,y,z
 * and an associated mass that represents any scalar field such as intensity.
 * Blob objects records the total mass, the mass-weighted first and second moments
 * as new points are added to the blob. Knowledge about individual points is lost,
 * i.e Blob can only increase in size.Blobs can be merged and maintain zero, first and second momentum.
 * Blob3D can be transformed into an Ellipsoid, by diagonalizing the variance tensor.
 *
 */
class Blob3D {
public:
  
  //! Initialize an empty blob
  Blob3D() = default;

  //! Initialize a blob with a point of mass m at x,y,z
  Blob3D(double x, double y,double z, double m);

  //! Copy constructor
  Blob3D(const Blob3D&) = default;

  Blob3D(Blob3D&&) = default;

  //! Assignment
  Blob3D& operator=(const Blob3D&) = default;

  //! Move assignment
  Blob3D& operator=(Blob3D&&) = default;

  //! Add point to the Blob
  void addPoint(double x, double y, double z, double m);

  //! Merge a second blob
  void merge(const Blob3D&);

  //! Return the total mass
  double mass() const;

  //! Return the number of points
  int nPixels() const;

  //! Return the center of Mass
  Eigen::Vector3d center() const;

  //! Get the ellipsoid parameters
  void toEllipsoid(double scale, Eigen::Vector3d& center,
                   Eigen::Vector3d& eigenvalues,Eigen::Matrix3d& eigenvectors) const;

  //! Print
  void printSelf(std::ostream& os) const;
 
  //! Get covariance matrix of the blob
  Eigen::Matrix3d covariance() const;

private:
  //! Zeroth moment (total mass)
  double _m0;

  //! First moments
  Eigen::Vector3d _m1;

  //! Second moments  
  Eigen::Matrix3d _m2;

  //! Number of pixels contributing to this blob
  unsigned int _n_pixels;

  //! Minimum mass value
  double _minValue;
  
  //! Maximum mass value
   double _maxValue;
};

#ifndef SWIG
std::ostream& operator<<(std::ostream& os, const Blob3D& b);
#endif
} // end namespace nsx
