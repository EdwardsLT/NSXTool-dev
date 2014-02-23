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

#ifndef NSXTOOL_ELLIPSOID_H_
#define NSXTOOL_ELLIPSOID_H_
#include "IShape.h"
#include "OBB.h"
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>

namespace SX
{
namespace Geometry
{

template<typename T,uint D>
class Ellipsoid : public IShape<T,D>
{
	typedef Eigen::Matrix<T,D,1> vector;
	typedef Eigen::Matrix<T,D+1,1> HomVector;
	typedef Eigen::Matrix<T,D,D> matrix;
	typedef Eigen::Matrix<T,D+1,D+1> HomMatrix;
	using AABB<T,D>::_lowerBound;
	using AABB<T,D>::_upperBound;
public:
	// Construct a N-dimensional ellipsoid from its center, semi-axes, and eigenvectors ()
	Ellipsoid(const vector& center, const vector& eigenvalues, const matrix& eigenvectors);
	// Scale the ELlipsoid by the same value along each direction.
	void scale(T value);
	// Anisotropic scale.
	void scale(const vector& scale);
	// Translate the ellipsoid
	void translate(const vector& t);
	// Check whether a point given as Homogeneous coordinate in the (D+1) dimension is Inside the Ellipsoid.
	bool isInside(const HomVector& vector) const;
	// Intersection test. Return true if the objects touch or overlap.
	bool collide(const Ellipsoid& other) const;
	// Return the inverse of the Mapping matrix (\f$ S^{-1}.R^{-1}.T^{-1} \f$)
	const HomMatrix& getTRSInverseMatrix() const;
	// Return the semi-axes of the Ellipsoids
	const vector& getSemiAxes() const;
	//
private:
	// Method to update the closest fit AABB to the Ellipsoid
	void updateAABB();
	Eigen::Matrix<T,D+1,D+1> _TRSinv;
	// EigenValues
	vector _eigenVal;
public:
	// Macro to ensure that Ellipsoid can be dynamically allocated.
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

// Specialization of collision detection is necessary here to avoid heavy maths.
// Collision detection in the 2D case.
template<typename T,uint D=2> bool collideEllipsoidEllipsoid(const Ellipsoid<T,2>&, const Ellipsoid<T,2>&);
// Collision detection in the 3D case.
template<typename T,uint D=3> bool collideEllipsoidEllipsoid(const Ellipsoid<T,3>&, const Ellipsoid<T,3>&);


template<typename T,uint D>
Ellipsoid<T,D>::Ellipsoid(const vector& center, const vector& eigenvalues, const matrix& eigenvectors)
:IShape<T,D>(),
 _eigenVal(eigenvalues)
{

	// Define the inverse scale matrix from the eigenvalues
	Eigen::DiagonalMatrix<T,D+1> Sinv;
	for (unsigned int i=0;i<D;++i)
		Sinv.diagonal()[i]=1.0/eigenvalues[i];
	Sinv.diagonal()[D]=1.0;

	// Now prepare the R^-1.T^-1 (rotation,translation)
	_TRSinv=Eigen::Matrix<T,D+1,D+1>::Constant(0.0);
	_TRSinv(D,D)=1.0;
	for (unsigned int i=0;i<D;++i)
		_TRSinv.block(i,0,1,D)=eigenvectors.col(i).transpose().normalized();
	_TRSinv.block(0,D,D,1)=-_TRSinv.block(0,0,D,D)*center;

	// Finally compute (TRS)^-1 by left-multiplying (TR)^-1 by S^-1
	_TRSinv=Sinv*_TRSinv;
	updateAABB();
}

template<typename T,uint D>
void Ellipsoid<T,D>::scale(T value)
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
void Ellipsoid<T,D>::scale(const vector& v)
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
void Ellipsoid<T,D>::translate(const vector& t)
{
	Eigen::Matrix<T,D+1,D+1> tinv=Eigen::Matrix<T,D+1,D+1>::Constant(0.0);
	tinv.block(0,D,D,1)=-t;
	for (uint i=0;i<D+1;++i)
		tinv(i,i)=1.0;
	tinv(D,D)=1.0;
	_TRSinv=_TRSinv*tinv;
	translateAABB(t);
}

template<typename T,uint D>
bool Ellipsoid<T,D>::isInside(const HomVector& point) const
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
const typename Ellipsoid<T,D>::HomMatrix& Ellipsoid<T,D>::getTRSInverseMatrix() const
{
	return _TRSinv;
}

template<typename T,uint D>
const typename Ellipsoid<T,D>::vector& Ellipsoid<T,D>::getSemiAxes() const
{
	return _eigenVal;
}

template<typename T,uint D>
bool Ellipsoid<T,D>::collide(const Ellipsoid<T,D>& other) const
{
	return collideEllipsoidEllipsoid<T,D>(*this,other);
}

template<typename T,uint D>
void Ellipsoid<T,D>::updateAABB()
{
	Eigen::Matrix<T,D+1,D+1> TRS=getTRSInverseMatrix().inverse();

	vector width=vector::Constant(0.0);
	for (unsigned int i=0;i<D;++i)
	{
		for (unsigned int j=0;j<D;++j)
		{
			width[i]+=std::pow(TRS(i,j),2);
		}
		width[i]=sqrt(width[i]);
	}
	Eigen::DiagonalMatrix<T,D+1> Sinv;
	for (unsigned int i=0;i<D;++i)
		Sinv.diagonal()[i]=1.0/_eigenVal[i];
	Sinv.diagonal()[D]=1.0;
	TRS=TRS*Sinv;
	// Update the upper and lower bound of the AABB
	_lowerBound=TRS.block(0,D,D,1)-width;
	_upperBound=TRS.block(0,D,D,1)+width;

}

/** Based on the method describe in:
 "Continuous collision detection for elliptic disks"
  by Yi-king Choi , Wenping Wang , Yang Liu , Myung-soo Kim
  IEEE Transactions on Robotics, (2006).
  However, resolving the roots of the characteristic polynomial is
  done here using the diagonalization of the companion matrix, rather
  than using the Sturm's sequence
  */

template<typename T,uint D=2> bool collideEllipsoidEllipsoid(const Ellipsoid<T,2>& eA, const Ellipsoid<T,2>& eB)
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
	T term3=A.determinant(); //det(A) must be negative by definition of the ellipsoid equation

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

/** Based on the method described in:
 *  "Continuous Collision Detection for Ellipsoids"
 *	Choi, Yi-King; Jung-Woo Chang; Wenping Wang; Myung-Soo Kim; Elber, G.,
 *	Visualization and Computer Graphics, IEEE Transactions on , vol.15, no.2, pp.311,325, March-April 2009
 *  However, resolving the roots of the characteristic polynomial is
 *  done here using the diagonalization of the companion matrix, rather
 *  than using the Sturm's sequence
 */

template<typename T,uint D=3> bool collideEllipsoidEllipsoid(const Ellipsoid<T,3>& eA, const Ellipsoid<T,3>& eB)
{
	//
	const Eigen::Matrix<T,4,4>& trsA=eA.getTRSInverseMatrix();
	const Eigen::Matrix<T,3,1>& eigA=eA.getSemiAxes();
	const Eigen::Matrix<T,4,4>& trsB=eB.getTRSInverseMatrix();
	const Eigen::Matrix<T,3,1>& eigB=eB.getSemiAxes();
	Eigen::DiagonalMatrix<T,4> SA;
	SA.diagonal() << eigA(0), eigA(1), eigA(2), 1.0;
	Eigen::DiagonalMatrix<T,4> SB;
	SB.diagonal() << eigB(0), eigB(1), eigB(2), 1.0;
	// Recover the MA matrix
	Eigen::Matrix<T,4,4> MA=SA*trsA;
	MA.block(0,0,D,D).transposeInPlace();
	MA.block(0,D,D,1)=-MA.block(0,0,D,D)*MA.block(0,D,D,1);
	// Recover the MB^-1 matrix
	Eigen::Matrix<T,4,4> B=SB*trsB;
	// Define the characteristic matrix of B in its frame of reference.
	SA.diagonal() << 1.0/std::pow(eigA(0),2), 1.0/std::pow(eigA(1),2), 1.0/std::pow(eigA(2),2), -1.0;
	SB.diagonal() << 1.0/std::pow(eigB(0),2), 1.0/std::pow(eigB(1),2), 1.0/std::pow(eigB(2),2), -1.0;
	// Calculate the [bij] matrix (reference to publication).
	B=MA.transpose()*B.transpose()*SB*B*MA;
	//
	T ea=SA.diagonal()[0],eb=SA.diagonal()[1],ec=SA.diagonal()[2];
	T ab=ea*eb, ac=ea*ec, bc= eb*ec;
	T abc=ea*eb*ec;
	T b12s=B(0,1)*B(0,1);
	T b13s=B(0,2)*B(0,2);
	T b14s=B(0,3)*B(0,3);
	T b23s=B(1,2)*B(1,2);
	T b24s=B(1,3)*B(1,3);
	T b34s=B(2,3)*B(2,3);
	T b2233=B(1,1)*B(2,2);
	T termA=B(0,0)*bc+B(1,1)*ac+B(2,2)*ab;
	T termB=(b2233-b23s)*ea+(B(0,0)*B(2,2)-b13s)*eb+(B(0,0)*B(1,1)-b12s)*ec;
	T T4=-abc;
	T T3=termA-B(3,3)*abc;
	T T2 = termA*B(3,3)-termB-b34s*ab-b14s*bc-b24s*ac;
	T tmp1=termB*B(3,3);
	T tmp2=B(0,0)*(b2233+eb*b34s+ec*b24s-b23s);
	T tmp3=B(1,1)*(ea*b34s+ec*b14s-b13s);
	T tmp4=B(2,2)*(ea*b24s+eb*b14s-b12s);
	T tmp5=B(2,3)*(ea*B(1,2)*B(1,3)+eb*B(0,2)*B(0,3))
	+ B(0,1)*(ec*B(0,3)*B(1,3)-B(0,2)*B(1,2));
	tmp5+= tmp5;
	T T1=-tmp1+tmp2+tmp3+tmp4-tmp5;
	T T0 = (-B).determinant();
	// Normalize the polynomial coeffs.
	T3/=T4;T2/=T4;T1/=T4;T0/=T4;T4=1.0;
	// Solve roots of the polynomial equation
	Eigen::Matrix<T,4,4> companion;
	companion << 0,0,0,-T0,
				 1,0,0,-T1,
				 0,1,0,-T2,
				 0,0,1,-T3;
	// Solve the eigenvalues problem
	Eigen::ComplexEigenSolver<Eigen::Matrix<T,4,4>> solver;
	solver.compute(companion);

	const std::complex<T>& val0=solver.eigenvalues()(0);
	const std::complex<T>& val1=solver.eigenvalues()(1);
	const std::complex<T>& val2=solver.eigenvalues()(2);
	const std::complex<T>& val3=solver.eigenvalues()(3);

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
	if (std::fabs(imag(val3))< 1e-5 && real(val3)<0)
		sol[count++]=real(val3);
	return (!(count==2 && std::fabs(sol[0]-sol[1])>1e-5));

}


} // Namespace Geometry
} // Namespace SX

#endif /* NSXTOOL_ELLIPSOID_H_ */
