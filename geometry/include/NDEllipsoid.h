/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon Institut Laue-Langevin
	BP 156
	6, rue Jules Horowitz
	38042 Grenoble Cedex 9
	France
	chapon[at]ill.fr

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

#ifndef NSXTOOL_NDELLIPSOID_H_
#define NSXTOOL_NDELLIPSOID_H_
#include "IPShape.h"
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>

namespace SX
{
namespace Geometry
{

template<typename T,uint D>
class NDEllipsoid : public IShape<T,D>
{
	typedef Eigen::Matrix<T,D,1> vector;
	typedef Eigen::Matrix<T,D+1,1> HomVector;
	typedef Eigen::Matrix<T,D,D> matrix;
	typedef Eigen::Matrix<T,D+1,D+1> HomMatrix;
	using AABB<T,D>::_lowerBound;
	using AABB<T,D>::_upperBound;
public:
	// Construct a N-dimensional ellipsoid from its center, semi-axes, and eigenvectors ()
	NDEllipsoid(const vector& center, const vector& eigenvalues, const matrix& eigenvectors);
	// Scale the ELlipsoid by the same value along each direction.
	void scale(T value);
	// Anisotropic scale.
	void scale(const vector& scale);
	// Translate the ellipsoid
	void translate(const vector& t);
	// Check whether a point given as Homogeneous coordinate in the (D+1) dimension is Inside the Ellipsoid.
	bool isInside(const HomVector& vector) const;
	// Intersection test. Return true if the objects touch or overlap.
	bool collide(const NDEllipsoid& other) const;
	// Return the inverse of the Mapping matrix (\f$ S^{-1}.R^{-1}.T^{-1} \f$)
	const HomMatrix& getTRSInverseMatrix() const;
	// Return the semi-axes of the Ellipsoids
	const vector& getSemiAxes() const;
private:
	// Method to recalculate the closest fit AABB to the Ellipsoid
	void recalculateAABB();
	Eigen::Matrix<T,D+1,D+1> _TRSinv;
	// EigenValues
	vector _eigenVal;
};

template<typename T,uint D=2> bool collideEllipsoidEllipsoid(const NDEllipsoid<T,2>& eA, const NDEllipsoid<T,2>& eB)
{
	// Get the (TRS)^-1 matrices from object A and B
	const Eigen::Matrix<T,3,3>& trsA=eA.getTRSInverseMatrix();
	const Eigen::Matrix<T,2,1>& eigA=eA.getSemiAxes();
	const Eigen::Matrix<T,3,3>& trsB=eB.getTRSInverseMatrix();
	const Eigen::Matrix<T,2,1>& eigB=eB.getSemiAxes();

	// Reconstruct the S matrices
	Eigen::DiagonalMatrix<T,3> SA;
	SA.diagonal() << eigA(0), eigA(1),1.0;
	Eigen::DiagonalMatrix<T,3> SB;
	SB.diagonal() << eigB(0), eigB(1),1.0;
	// Recover the (TR)^-1=Minv matrices
	Eigen::Matrix<T,3,3> A=SA*trsA;
	//MA.block<0,0>(N,N).tranposeInPlace();
	Eigen::Matrix<T,3,3> B=SB*trsB;
	// A and B are  now the characteristic matrix of the ellipsoids in their frame of references.
	SA.diagonal() << 1.0/std::pow(eigA(0),2), 1.0/std::pow(eigA(1),2),-1.0;
	SB.diagonal() << 1.0/std::pow(eigB(0),2), 1.0/std::pow(eigB(1),2),-1.0;

	A=A.transpose()*SA*A;
	B=B.transpose()*SB*B;

	// Now calculates the coefficients of the characteristic polynomial f(lambda)=det|lambda*A-B|
	// The third degree term is det(A) and the constant term is det(B). The polynomial is normalized
	// by det(A) to become of the form : lambda^3+term2*lambda^2+term1*lambda+term0
	T term3=A.determinant();
	T term2=-A(0,0)*A(1,1)*B(2,2)+A(0,1)*A(1,0)*B(2,2)-A(0,0)*B(1,1)*A(2,2)-B(0,0)*A(1,1)*A(2,2)+
			 A(0,1)*B(1,0)*A(2,2)+B(0,1)*A(1,0)*A(2,2)+A(0,0)*A(1,2)*B(2,1)-A(0,2)*A(1,0)*B(2,1)+
			 A(0,0)*B(1,2)*A(2,1)+B(0,0)*A(1,2)*A(2,1)-A(0,2)*B(1,0)*A(2,1)-B(0,2)*A(1,0)*A(2,1)-
			 A(0,1)*A(1,2)*B(2,0)+A(0,2)*A(1,1)*B(2,0)-A(0,1)*B(1,2)*A(2,0)-B(0,1)*A(1,2)*A(2,0)+
			 A(0,2)*B(1,1)*A(2,0)+B(0,2)*A(1,1)*A(2,0);
	term2/=term3;
	T term1= A(0,0)*B(1,1)*B(2,2)+B(0,0)*A(1,1)*B(2,2)-A(0,1)*B(1,0)*B(2,2)-B(0,1)*A(1,0)*B(2,2)+
			 B(0,0)*B(1,1)*A(2,2)-B(0,1)*B(1,0)*A(2,2)-A(0,0)*B(1,2)*B(2,1)-B(0,0)*A(1,2)*B(2,1)+
			 A(0,2)*B(1,0)*B(2,1)+B(0,2)*A(1,0)*B(2,1)-B(0,0)*B(1,2)*A(2,1)+B(0,2)*B(1,0)*A(2,1)+
			 A(0,1)*B(1,2)*B(2,0)+B(0,1)*A(1,2)*B(2,0)-A(0,2)*B(1,1)*B(2,0)-B(0,2)*A(1,1)*B(2,0)+
			 B(0,1)*B(1,2)*A(2,0)-B(0,2)*B(1,1)*A(2,0);
	term1/=term3;
	T term0=-B.determinant()/term3;
	// Construct the companion matrix: |0 0 -term0|
	//                                 |1 0 -term1|
	//								   |0 1 -term2|
	// from which the roots of the polynomial are derived.
	Eigen::Matrix<T,3,3> companion;
	companion << 0,0,-term0,
				 1,0,-term1,
				 0,1,-term2;
	// Solve the eigenvalues problem
	Eigen::ComplexEigenSolver<Eigen::Matrix<T,3,3>> solver;
	solver.compute(companion);

	const std::complex<T>& val0=solver.eigenvalues()(0);
	const std::complex<T>& val1=solver.eigenvalues()(1);
	const std::complex<T>& val2=solver.eigenvalues()(2);

	// One of the root is always positive.
    // Check whether two of the roots are negative and distinct, in which case the Ellipse do not collide.
	int count=0;
	T sol[2];
	if (std::fabs(imag(val0))< 1e-5 && real(val0)<0)
		sol[count++]=real(val0);
	if (std::fabs(imag(val1))< 1e-5 && real(val1)<0)
		sol[count++]=real(val1);
	if (std::fabs(imag(val2))< 1e-5 && real(val2)<0)
		sol[count++]=real(val2);

	return (!(count==2 && std::fabs(sol[0]-sol[1])>1e-5));

}


template<typename T,uint D>
NDEllipsoid<T,D>::NDEllipsoid(const vector& center, const vector& eigenvalues, const matrix& eigenvectors)
:IShape<T,D>(),
 _eigenVal(eigenvalues)
{
	Eigen::DiagonalMatrix<T,D+1> Sinv;
	for (unsigned int i=0;i<D;++i)
		Sinv.diagonal()[i]=1.0/eigenvalues(i);
	Sinv.diagonal()[D]=1.0;

	_TRSinv(D,D)=1.0;
	// Now prepare the R^-1.T^-1 (rotation,translation)
	_TRSinv.block(0,D,D,1)=-center;
	for (unsigned int i=0;i<D;++i)
	{
		_TRSinv(D,i)=0.0;
		_TRSinv.block(i,0,1,D)=eigenvectors.col(i).transpose();
	}
	_TRSinv=Sinv*_TRSinv;
	recalculateAABB();
}

template<typename T,uint D>
void NDEllipsoid<T,D>::scale(T value)
{
	_eigenVal*=value;
	Eigen::DiagonalMatrix<T,D+1> Sinv;
	for (unsigned int i=0;i<D;++i)
		Sinv.diagonal()[i]=1.0/value;
	Sinv.diagonal()[D]=1.0;
	_TRSinv=Sinv*_TRSinv;
	scaleAABB(value);
}

template<typename T,uint D>
void NDEllipsoid<T,D>::scale(const vector& v)
{
	_eigenVal=_eigenVal.cwiseProduct(v);
	Eigen::DiagonalMatrix<T,D+1> Sinv;
	for (unsigned int i=0;i<D;++i)
		Sinv.diagonal()[i]=1.0/v[i];
	Sinv.diagonal()[D]=1.0;
	_TRSinv=Sinv*_TRSinv;
	scaleAABB(v);
}

template<typename T,uint D>
void NDEllipsoid<T,D>::translate(const vector& t)
{
	Eigen::Matrix<T,D+1,D+1> tinv=Eigen::Matrix<T,D+1,D+1>::Constant(0.0);
	tinv.block(0,D,D,1)=-t;
	_TRSinv=_TRSinv*tinv;
	translateAABB(t);
}

template<typename T,uint D>
bool NDEllipsoid<T,D>::isInside(const HomVector& point) const
{
	HomVector p=_TRSinv*point;
	// Is the transformed point in the bounding box of the sphere
	for (unsigned int i=0;i<D;++i)
	{
		if (p[i]<-1 || p[i]> 1)
			return false;
	}
	T value=0;
	for (unsigned int i=0;i<D;++i)
		value+=p[i]*p[i];

	return (value<=1);
}

template<typename T,uint D>
const typename NDEllipsoid<T,D>::HomMatrix& NDEllipsoid<T,D>::getTRSInverseMatrix() const
{
	return _TRSinv;
}

template<typename T,uint D>
const typename NDEllipsoid<T,D>::vector& NDEllipsoid<T,D>::getSemiAxes() const
{
	return _eigenVal;
}

template<typename T,uint D>
bool NDEllipsoid<T,D>::collide(const NDEllipsoid<T,D>& other) const
{
	return collideEllipsoidEllipsoid<T,D>(*this,other);
}

template<typename T,uint D>
void NDEllipsoid<T,D>::recalculateAABB()
{
	// Reconstruct the R^{-1}.T^{-1} matrix to obtain the eigenvectors and center
	Eigen::DiagonalMatrix<T,D+1> S; // Reconstruct S
	for (unsigned int i=0;i<D;++i)
		S.diagonal()[i]=_eigenVal[i];
	S.diagonal()[D]=1.0;

	Eigen::Matrix<T,D+1,D+1> TRinv=S*_TRSinv; // Get R^{-1}.T^{-1}

	// Calculate the width of the bounding box
	vector width=vector::Constant(0.0);
	for (int i=0;i<D;++i)
	{
		for (int j=0;j<D;++j)
		{
			width[i]+=std::pow(_eigenVal[j]*TRinv(j,i),2);
		}
		width[i]=sqrt(width[i]);
	}
	// Update the upper and lower bound of the AABB
	_lowerBound=-TRinv.block(0,D,D,1)-width;
	_upperBound=-TRinv.block(0,D,D,1)+width;

}


} // Namespace Geometry
} // Namespace SX

#endif /* NSXTOOL_NDELLIPSOID_H_ */
