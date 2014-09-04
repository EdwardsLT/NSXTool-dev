/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Eric Pellegrini
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

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
#ifndef NSXTOOL_BASIS_H_
#define NSXTOOL_BASIS_H_

#include <iostream>
#include <memory>

#include <Eigen/Dense>

namespace SX
{

namespace Geometry
{

using Eigen::RowVector3d;
using Eigen::Vector3d;
using Eigen::Matrix3d;

/** @brief Class to define a Basis in 3D Euclidean space.
 *
 * Provide functionalities to define a Basis in 3-dimensional Euclidian space
 * from a set of 3 non-coplanar vectors. The Basis can be define with respect to a
 * reference basis, in which case a pointer to the reference is kept. If not, it is assumed
 * that the parent is the Standard orthonormal basis of a right-handed system.
 *
 */
class Basis {

typedef std::shared_ptr<Basis> ptrBasis;

public:

	//! Constructor from a set of three non coplanar vectors.
	//! These vectors will be used column-wised for building the transformation matrix from the reference basis to the current one.
	Basis(const Vector3d& e1, const Vector3d& e2, const Vector3d& e3, ptrBasis reference=nullptr);

	//! Copy constructor.
	Basis(const Basis& other);

	//! Assignment operator.
	Basis& operator=(const Basis& other);

	//! Destructor.
	virtual ~Basis();

	//! Build a basis from a set of three direct vectors.
	static Basis fromDirectVectors(const Vector3d& e1, const Vector3d& e2, const Vector3d& e3, ptrBasis reference=nullptr);
	//! Build a basis from a set of three reciprocal vectors.
	static Basis fromReciprocalVectors(const Vector3d& e1, const Vector3d& e2, const Vector3d& e3, ptrBasis reference=nullptr);

	//! Returns the transformation matrix that relates the current basis to another one.
	Matrix3d getTransformationMatrix(const Basis& other) const;

	//! Returns the current basis' metric tensor.
	Matrix3d getMetricTensor() const;
	//! Returns the current reciprocal basis' metric tensor.
	Matrix3d getReciprocalMetricTensor() const;

	//! Returns the direct volume fraction with respect to the reference volume.
	double getFractionalVolume() const;
	//! Returns the reciprocal volume fraction with respect to the reference volume.
	double getFractionalReciprocalVolume() const;

	//! Returns the direct volume.
	double getVolume() const;
	//! Returns the reciprocal volume.
	double getReciprocalVolume() const;

	//! Returns the coordinates in the current basis of a column vector v defined in the standard basis.
	Vector3d fromStandardBasis(const Vector3d& v) const;
	//! Returns the coordinates in the standard basis of a column vector v defined in the current basis.
	Vector3d toStandardBasis(const Vector3d& v) const;
	//! Returns the coordinates in the current basis of a column vector v defined in the reference basis.
	Vector3d fromReferenceBasis(const Vector3d& v) const;
	//! Returns the coordinates in the reference basis of a column vector v defined in the current basis.
	Vector3d toReferenceBasis(const Vector3d& v) const;
	RowVector3d fromReciprocalStandardBasis(const RowVector3d& rv) const;
	RowVector3d toReciprocalStandardBasis(const RowVector3d& rv) const;
	RowVector3d fromReciprocalReferenceBasis(const RowVector3d& rv) const;
	RowVector3d toReciprocalReferenceBasis(const RowVector3d& rv) const;

	friend std::ostream& operator<<(std::ostream& os,const Basis& b);

private:

	//! Returns true if three vectors are coplanar within a given tolerance.
	static bool coplanar(const Vector3d& v1, const Vector3d& v2, const Vector3d& v3, double tolerance=1.0e-6);
	//! A shared pointer to the reference basis. If null assume that the reference is the standard basis.
	ptrBasis _reference;
	//! The transformation matrix form the direct reference basis to the current one.
	Matrix3d _A;
	//! The transformation matrix form the reciprocal reference basis to the current one.
	Matrix3d _B;
};

} // end namespace Geometry

} // end namespace SX

#endif /* NSXTOOL_BASIS_H_ */
