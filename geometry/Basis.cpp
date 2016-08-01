#include <stdexcept>

#include "Basis.h"

namespace SX
{

namespace Geometry
{

Basis::Basis():_A(Eigen::Matrix3d::Identity()),_B(Eigen::Matrix3d::Identity()),_reference(nullptr), _Acov(covMat::Zero()), _Bcov(covMat::Zero()), _hasSigmas(false)
{
}

Basis::Basis(const Vector3d& a, const Vector3d& b, const Vector3d& c, ptrBasis reference): _reference(reference),_Acov(covMat::Zero()),_Bcov(covMat::Zero())
{

	if (coplanar(a,b,c))
		throw std::runtime_error("The basis vectors are coplanar.");

	_A.col(0) = a;
	_A.col(1) = b;
	_A.col(2) = c;

	_B = _A.inverse();

	if (reference)
	{
		_hasSigmas = reference->_hasSigmas;
		if (_hasSigmas)
		{
			_Acov = covMat(reference->_Acov);
			_Bcov = covMat(covMat::Zero());
			propagateSigmas(_A);
		}
	}
	else
		_hasSigmas=false;
}

Basis::Basis(const Basis& other)
{

	_reference = other._reference;
	_A = other._A;
	_B = other._B;

    _hasSigmas = other._hasSigmas;

    if (_hasSigmas)
    {
        _Acov = covMat(other._Acov);
        _Bcov = covMat(other._Bcov);
    }

}

Basis& Basis::operator=(const Basis& other)
{
	if (this != &other)
	{
		_reference = other._reference;
		_A = other._A;
		_B = other._B;

        _hasSigmas = other._hasSigmas;

        if (_hasSigmas)
        {
            _Acov = covMat(other._Acov);
            _Bcov = covMat(other._Bcov);
        }

	}
	return *this;
}


Basis::~Basis()
{

}

Basis Basis::fromDirectVectors(const Vector3d& a, const Vector3d& b, const Vector3d& c, ptrBasis reference)
{
	if (coplanar(a,b,c))
		throw std::runtime_error("Class Basis: the direct vectors are coplanar.");
	return Basis(a,b,c,reference);
}

Basis Basis::fromReciprocalVectors(const Vector3d& a, const Vector3d& b, const Vector3d& c, ptrBasis reference)
{

	if (coplanar(a,b,c))
		throw std::runtime_error("Class Basis: the reciprocal basis vectors are coplanar.");

	double rVolume = std::abs(a.dot(b.cross(c)));

	Vector3d av=b.cross(c)/rVolume;
	Vector3d bv=c.cross(a)/rVolume;
	Vector3d cv=a.cross(b)/rVolume;

	return Basis(av,bv,cv,reference);
}

void Basis::setDirectVectors(const Vector3d& a, const Vector3d& b, const Vector3d& c)
{

	if (coplanar(a,b,c))
		throw std::runtime_error("Class Basis: the reciprocal basis vectors are coplanar.");

	_A.col(0) = a;
	_A.col(1) = b;
	_A.col(2) = c;
	_B = _A.inverse();

}

void Basis::setReciprocalVectors(const Vector3d& a, const Vector3d& b, const Vector3d& c)
{
	double rVolume = std::abs(a.dot(b.cross(c)));

	Vector3d av=b.cross(c)/rVolume;
	Vector3d bv=c.cross(a)/rVolume;
	Vector3d cv=a.cross(b)/rVolume;

	return setDirectVectors(av,bv,cv);
}

bool Basis::coplanar(const Vector3d& v1, const Vector3d& v2, const Vector3d& v3, double tolerance)
{
	return (std::abs(v1.dot(v2.cross(v3))) < tolerance);
}

std::ostream& operator<<(std::ostream& os,const Basis& b)
{
	os<<"Direct basis:\n"<<b._A<<std::endl<<"\nReciprocal basis:\n"<<b._B<<std::endl;

	return os;
}

double Basis::getA() const
{
	return _A.col(0).norm();
}
double Basis::getB() const
{
	return _A.col(1).norm();
}
double Basis::getC() const
{
	return _A.col(2).norm();
}
double Basis::getAlpha() const
{
	return acos(_A.col(1).dot(_A.col(2))/getB()/getC());
}
double Basis::getBeta() const
{
	return acos(_A.col(0).dot(_A.col(2))/getA()/getC());
}
double Basis::getGamma() const
{
	return acos(_A.col(0).dot(_A.col(1))/getA()/getB());
}

double Basis::getReciprocalA() const
{
	return _B.row(0).norm();
}
double Basis::getReciprocalB() const
{
	return _B.row(1).norm();
}
double Basis::getReciprocalC() const
{
	return _B.row(2).norm();
}
double Basis::getReciprocalAlpha() const
{
	return acos(_B.row(1).dot(_B.row(2))/getReciprocalB()/getReciprocalC());
}
double Basis::getReciprocalBeta() const
{
	return acos(_B.row(0).dot(_B.row(2))/getReciprocalA()/getReciprocalC());
}
double Basis::getReciprocalGamma() const
{
	return acos(_B.row(0).dot(_B.row(1))/getReciprocalA()/getReciprocalB());
}

void Basis::getParameters(double& a,double& b,double& c,double& alpha,double& beta,double& gamma) const
{
	a=getA();
	b=getB();
	c=getC();
	alpha=getAlpha();
	beta=getBeta();
	gamma=getGamma();
}

void Basis::getParametersSigmas(double& sa,double& sb ,double& sc,double& salpha, double& sbeta, double& sgamma) const
{
	if (!hasSigmas())
	{
		sa = 0;
		sb = 0;
		sc = 0;
		salpha = 0;
		sbeta = 0;
		sgamma = 0;
		return;
	}
	double norma = _A.col(0).norm();
	double normb = _A.col(1).norm();
	double normc = _A.col(2).norm();
	Eigen::Vector3d dfda =_A.col(0)/norma;
	Eigen::Matrix3d mdfda = dfda*dfda.transpose();
	sa = (mdfda.cwiseProduct(_Acov.block(0,0,3,3))).sum();
	sa = sqrt(sa);
	Eigen::Vector3d dfdb=_A.col(1)/normb;
	Eigen::Matrix3d mdfdb=dfdb*dfdb.transpose();
	sb = (mdfdb.cwiseProduct(_Acov.block(3,3,3,3))).sum();
	sb = sqrt(sb);
	Eigen::Vector3d dfdc=_A.col(2)/normc;
	Eigen::Matrix3d mdfdc=dfdc*dfdc.transpose();
	sc = (mdfdc.cwiseProduct(_Acov.block(6,6,3,3))).sum();
	sc = sqrt(sc);

	// Now errors on angles, gamma=acos(a.b/(|a||b|))
	double scalar_ab=_A.col(1).transpose()*_A.col(0);
	double scalar_ac=_A.col(2).transpose()*_A.col(0);
	double scalar_bc=_A.col(1).transpose()*_A.col(2);
	double norma2=norma*norma;
	double normb2=normb*normb;
	double normc2=normc*normc;
	double denom_ab=sqrt(norma2*normb2-scalar_ab*scalar_ab);
	double denom_ac=sqrt(norma2*normc2-scalar_ac*scalar_ac);
	double denom_bc=sqrt(normb2*normc2-scalar_bc*scalar_bc);
	const double& ax=_A(0,0);
	const double& ay=_A(1,0);
	const double& az=_A(2,0);
	const double& bx=_A(0,1);
	const double& by=_A(1,1);
	const double& bz=_A(2,1);
	const double& cx=_A(0,2);
	const double& cy=_A(1,2);
	const double& cz=_A(2,2);

	Eigen::VectorXd dalpha(6);

	dalpha(0)=(-cx+bx*scalar_bc/normb2)/denom_bc;
	dalpha(1)=(-cy+by*scalar_bc/normb2)/denom_bc;
	dalpha(2)=(-cz+bz*scalar_bc/normb2)/denom_bc;
	dalpha(3)=(-bx+cx*scalar_bc/normc2)/denom_bc;
	dalpha(4)=(-by+cy*scalar_bc/normc2)/denom_bc;
	dalpha(5)=(-bz+cz*scalar_bc/normc2)/denom_bc;

	salpha=((dalpha*dalpha.transpose()).cwiseProduct(_Acov.block(3,3,6,6))).sum();
	salpha=sqrt(salpha);

	Eigen::VectorXd dbeta(6);

	dbeta(0)=(-cx+ax*scalar_ac/norma2)/denom_ac;
	dbeta(1)=(-cy+ay*scalar_ac/norma2)/denom_ac;
	dbeta(2)=(-cz+az*scalar_ac/norma2)/denom_ac;
	dbeta(3)=(-ax+cx*scalar_ac/normc2)/denom_ac;
	dbeta(4)=(-ay+cy*scalar_ac/normc2)/denom_ac;
	dbeta(5)=(-az+cz*scalar_ac/normc2)/denom_ac;

	Eigen::Matrix<double,6,6> covBeta;
	covBeta.block(0,0,3,3)=_Acov.block(0,0,3,3);
	covBeta.block(3,0,3,3)=_Acov.block(6,0,3,3);
	covBeta.block(0,3,3,3)=_Acov.block(0,6,3,3);
	covBeta.block(3,3,3,3)=_Acov.block(6,6,3,3);

	sbeta=((dbeta*dbeta.transpose()).cwiseProduct(covBeta)).sum();
	sbeta=sqrt(sbeta);

	Eigen::VectorXd dgamma(6);

	dgamma(0)=(-bx+ax*scalar_ab/norma2)/denom_ab;
	dgamma(1)=(-by+ay*scalar_ab/norma2)/denom_ab;
	dgamma(2)=(-bz+az*scalar_ab/norma2)/denom_ab;
	dgamma(3)=(-ax+bx*scalar_ab/normb2)/denom_ab;
	dgamma(4)=(-ay+by*scalar_ab/normb2)/denom_ab;
	dgamma(5)=(-az+bz*scalar_ab/normb2)/denom_ab;

	sgamma=((dgamma*dgamma.transpose()).cwiseProduct(_Acov.block(0,0,6,6))).sum();
	sgamma=sqrt(sgamma);

}

void Basis::getReciprocalParametersSigmas(double& sas,double& sbs ,double& scs,double& salphas, double& sbetas, double& sgammas) const
{
	if (!hasSigmas())
	{
		sas = 0;
		sbs = 0;
		scs = 0;
		salphas = 0;
		sbetas = 0;
		sgammas = 0;
		return;
	}

	double normas = _B.row(0).norm();
	Eigen::RowVector3d dfdas = _B.row(0)/normas;
	Eigen::Matrix3d mdfdas=dfdas.transpose()*dfdas;
	sas = (mdfdas.cwiseProduct(_Bcov.block(0,0,3,3))).sum();
	sas = sqrt(sas);

	double normbs = _B.row(1).norm();
	Eigen::RowVector3d dfdbs=_B.row(1)/normbs;
	Eigen::Matrix3d mdfdbs=dfdbs.transpose()*dfdbs;
	sbs = (mdfdbs.cwiseProduct(_Bcov.block(3,3,3,3))).sum();
	sbs = sqrt(sbs);

	double normcs = _B.row(2).norm();
	Eigen::RowVector3d dfdcs=_B.row(2)/normcs;
	Eigen::Matrix3d mdfdcs=dfdcs.transpose()*dfdcs;
	scs = (mdfdcs.cwiseProduct(_Bcov.block(6,6,3,3))).sum();
	scs = sqrt(scs);

	// Now errors on angles, gamma=acos(a.b/(|a||b|))
	double scalar_asbs=_B.row(1)*_B.row(0).transpose();
	double scalar_ascs=_B.row(2)*_B.row(0).transpose();
	double scalar_bscs=_B.row(1)*_B.row(2).transpose();
	double normas2=normas*normas;
	double normbs2=normbs*normbs;
	double normcs2=normcs*normcs;
	double denom_asbs=sqrt(normas2*normbs2-scalar_asbs*scalar_asbs);
	double denom_ascs=sqrt(normas2*normcs2-scalar_ascs*scalar_ascs);
	double denom_bscs=sqrt(normbs2*normcs2-scalar_bscs*scalar_bscs);
	const double& asx=_B(0,0);
	const double& asy=_B(0,1);
	const double& asz=_B(0,2);
	const double& bsx=_B(1,0);
	const double& bsy=_B(1,1);
	const double& bsz=_B(1,2);
	const double& csx=_B(2,0);
	const double& csy=_B(2,1);
	const double& csz=_B(2,2);

	Eigen::VectorXd dalphas(6);

	dalphas(0)=(-csx+bsx*scalar_bscs/normbs2)/denom_bscs;
	dalphas(1)=(-csy+bsy*scalar_bscs/normbs2)/denom_bscs;
	dalphas(2)=(-csz+bsz*scalar_bscs/normbs2)/denom_bscs;
	dalphas(3)=(-bsx+csx*scalar_bscs/normcs2)/denom_bscs;
	dalphas(4)=(-bsy+csy*scalar_bscs/normcs2)/denom_bscs;
	dalphas(5)=(-bsz+csz*scalar_bscs/normcs2)/denom_bscs;

	salphas = ((dalphas*dalphas.transpose()).cwiseProduct(_Bcov.block(3,3,6,6))).sum();
	salphas = sqrt(salphas);

	Eigen::VectorXd dbetas(6);

	dbetas(0)=(-csx+asx*scalar_ascs/normas2)/denom_ascs;
	dbetas(1)=(-csy+asy*scalar_ascs/normas2)/denom_ascs;
	dbetas(2)=(-csz+asz*scalar_ascs/normas2)/denom_ascs;
	dbetas(3)=(-asx+csx*scalar_ascs/normcs2)/denom_ascs;
	dbetas(4)=(-asy+csy*scalar_ascs/normcs2)/denom_ascs;
	dbetas(5)=(-asz+csz*scalar_ascs/normcs2)/denom_ascs;

	Eigen::Matrix<double,6,6> covBeta;
	covBeta.block(0,0,3,3)=_Bcov.block(0,0,3,3);
	covBeta.block(3,0,3,3)=_Bcov.block(6,0,3,3);
	covBeta.block(0,3,3,3)=_Bcov.block(0,6,3,3);
	covBeta.block(3,3,3,3)=_Bcov.block(6,6,3,3);

	sbetas = ((dbetas*dbetas.transpose()).cwiseProduct(covBeta)).sum();
	sbetas = sqrt(sbetas);

	Eigen::VectorXd dgammas(6);

	dgammas(0)=(-bsx+asx*scalar_asbs/normas2)/denom_asbs;
	dgammas(1)=(-bsy+asy*scalar_asbs/normas2)/denom_asbs;
	dgammas(2)=(-bsz+asz*scalar_asbs/normas2)/denom_asbs;
	dgammas(3)=(-asx+bsx*scalar_asbs/normbs2)/denom_asbs;
	dgammas(4)=(-asy+bsy*scalar_asbs/normbs2)/denom_asbs;
	dgammas(5)=(-asz+bsz*scalar_asbs/normbs2)/denom_asbs;

	sgammas = ((dgammas*dgammas.transpose()).cwiseProduct(_Bcov.block(0,0,6,6))).sum();
	sgammas = sqrt(sgammas);

}

Matrix3d Basis::getMetricTensor() const
{

	if (!_reference)
		return _A.transpose()*_A;
	else
		return _A.transpose()*_reference->getMetricTensor()*_A;
}

Matrix3d Basis::getReciprocalMetricTensor() const
{
	if (!_reference)
		return _B*_B.transpose();
	else
		return _B*_reference->getReciprocalMetricTensor()*_B.transpose();
}

double Basis::getFractionalVolume() const
{
	return sqrt((_A.transpose()*_A).determinant());
}

double Basis::getFractionalReciprocalVolume() const
{
	return sqrt((_B*_B.transpose()).determinant());
}

double Basis::getVolume() const
{
	Matrix3d g=getMetricTensor();
	return sqrt(g.determinant());
}

double Basis::getReciprocalVolume() const
{
	Matrix3d gs=getReciprocalMetricTensor();
	return sqrt(gs.determinant());
}

Vector3d Basis::fromStandard(const Vector3d& v) const
{
	if (!_reference)
		return _B*v;
	else
		return _B*_reference->fromStandard(v);
}

Vector3d Basis::toStandard(const Vector3d& v) const
{
	if (!_reference)
		return _A*v;
	else
		return _reference->toStandard(_A*v);
}

Vector3d Basis::fromReference(const Vector3d& v) const
{
	return _B*v;
}

Vector3d Basis::toReference(const Vector3d& v) const
{
	return _A*v;
}

RowVector3d Basis::fromReciprocalStandard(const RowVector3d& rv) const
{
	if (!_reference)
		return rv*_A;
	else
		return _reference->fromReciprocalStandard(rv)*_A;
}

RowVector3d Basis::toReciprocalStandard(const RowVector3d& rv) const
{
	if (!_reference)
		return rv*_B;
	else
		return _reference->toReciprocalStandard(rv*_B);
}

RowVector3d Basis::fromReciprocalReference(const RowVector3d& rv) const
{
	return rv*_A;
}

RowVector3d Basis::toReciprocalReference(const RowVector3d& rv) const
{
	return rv*_B;
}

Matrix3d Basis::getStandardM() const
{

	if (!_reference)
		return _A;
	else
		return _reference->getStandardM()*_A;
}

Matrix3d Basis::getReciprocalStandardM() const
{

	return getStandardM().inverse();
}

const Matrix3d& Basis::getReferenceM() const
{
	return _A;
}

const Matrix3d& Basis::getReciprocalReferenceM() const
{

	return _B;
}

Matrix3d Basis::getM(const Basis& other) const
{
	Matrix3d A = getStandardM();
	Matrix3d Aother = other.getStandardM();
	return Aother.inverse()*A;
}

Matrix3d Basis::getReciprocalM(const Basis& other) const
{
	return getM(other).inverse();
}

void Basis::rebaseToStandard()
{
	_A = getStandardM();
	_B = _A.inverse();
	_reference.reset();
}

void Basis::rebaseTo(std::shared_ptr<Basis> other,bool sigmasFromReference)
{
	if (other != nullptr)
	{
		_A = getM(*other);
		_B = _A.inverse();
		_reference = other;

		if (_reference->hasSigmas() && sigmasFromReference)
		{
			if (!hasSigmas())
			{
				_hasSigmas = true;
				_Acov = covMat(_reference->_Acov);
				_Bcov = covMat();
			}
			propagateSigmas(_A);
		}
	}
	else
		rebaseToStandard();
}

void Basis::transform(const Matrix3d& M)
{
	_A=_A*M;
	_B=_A.inverse();

	if (hasSigmas())
		propagateSigmas(M);
}

void Basis::propagateSigmas(const Matrix3d& M)
{
	Eigen::Matrix<double,9,9> MM=Eigen::Matrix<double,9,9>::Zero();

	MM.block(0,0,3,3).diagonal() = Eigen::Vector3d::Constant(M(0,0));
	MM.block(3,0,3,3).diagonal() = Eigen::Vector3d::Constant(M(1,0));
	MM.block(6,0,3,3).diagonal() = Eigen::Vector3d::Constant(M(2,0));

	MM.block(0,3,3,3).diagonal() = Eigen::Vector3d::Constant(M(0,1));
	MM.block(3,3,3,3).diagonal() = Eigen::Vector3d::Constant(M(1,1));
	MM.block(6,3,3,3).diagonal() = Eigen::Vector3d::Constant(M(2,1));

	MM.block(0,6,3,3).diagonal() = Eigen::Vector3d::Constant(M(0,2));
	MM.block(3,6,3,3).diagonal() = Eigen::Vector3d::Constant(M(1,2));
	MM.block(6,6,3,3).diagonal() = Eigen::Vector3d::Constant(M(2,2));

	_Acov = MM*_Acov*MM.transpose();
	calculateSigmasDirectToReciprocal(true);
}

bool Basis::hasSigmas() const
{
	return _hasSigmas;
}

void Basis::calculateSigmasDirectToReciprocal(bool direction)
{

	// For uncorrelated errors, given a matrix A with inverse A-1,
	// then the uncertainty squared [sigmaA-1]^2_{alpha,beta}=[A-1]^2_{alpha,i}.[sigmaA]^2_{i,j}.[A-1]^2_{j,beta}
	// Here, use the fact that A^-1=B, or B^-1=A when converting from direct to reciprocal or reciprocal to direct
	// Explained in M. Lefebvre, R.K. Keeler, R. Sobie, J. White, Propagation of errors for matrix inversion,
	// Nuclear Instruments and Methods in Physics Research Section A: Accelerators, Spectrometers, Detectors and Associated Equipment, Volume 451, Issue 2, 1 September 2000, Pages 520-528


	Matrix3d input;
	covMat* inputS;
	covMat* outputS;
	if (direction)
	{
		input   = getReciprocalStandardM();
		inputS=&_Acov;
		outputS=&_Bcov;
	}
	else
	{
		input   = getStandardM();
		inputS  = &_Bcov;
		outputS = &_Acov;
	}

	*outputS = covMat::Zero();

	for (int alpha=0;alpha<3;++alpha)
	{
		for (int beta=0;beta<3;++beta)
		{
			int u=3*alpha+beta;
			for (int a=0;a<3;++a)
			{
				for (int b=0;b<3;++b)
				{
					int v=3*a+b;

					for (int i=0;i<3;++i)
					{
						for (int j=0;j<3;++j)
						{
							for (int k=0;k<3;++k)
							{
								for (int l=0;l<3;++l)
									(*outputS)(u,v)+=input(alpha,i)*input(j,beta)*input(a,k)*input(l,b)*(*inputS)(3*i+j,3*k+l);
							}
						}
					}

				}
			}
		}
	}
}

void Basis::setReciprocalSigmas(const Eigen::Vector3d& sas,const Eigen::Vector3d& sbs,const Eigen::Vector3d& scs)
{
	_Bcov.setZero();

	_Bcov.block(0,0,3,3).diagonal() = sas.cwiseProduct(sas);
	_Bcov.block(3,3,3,3).diagonal() = sbs.cwiseProduct(sbs);
	_Bcov.block(6,6,3,3).diagonal() = scs.cwiseProduct(scs);

	calculateSigmasDirectToReciprocal(false);

	_hasSigmas = true;
}

void Basis::setReciprocalSigmas(const Matrix3d& sigmas)
{
	_Bcov.setZero();

	const Eigen::Vector3d& r0 = sigmas.row(0);
	const Eigen::Vector3d& r1 = sigmas.row(1);
	const Eigen::Vector3d& r2 = sigmas.row(2);

	_Bcov.block(0,0,3,3).diagonal() = r0.cwiseProduct(r0);
	_Bcov.block(3,3,3,3).diagonal() = r1.cwiseProduct(r1);
	_Bcov.block(6,6,3,3).diagonal() = r2.cwiseProduct(r2);

	calculateSigmasDirectToReciprocal(false);

	_hasSigmas = true;
}

void Basis::setReciprocalCovariance(const covMat& rCov)
{
	_Bcov = rCov;

	calculateSigmasDirectToReciprocal(false);

	_hasSigmas = true;
}

void Basis::setDirectSigmas(const Eigen::Vector3d& sa,const Eigen::Vector3d& sb,const Eigen::Vector3d& sc)
{
	_Acov.setZero();

	_Acov.block(0,0,3,3).diagonal() = sa.cwiseProduct(sa);
	_Acov.block(3,3,3,3).diagonal() = sb.cwiseProduct(sb);
	_Acov.block(6,6,3,3).diagonal() = sc.cwiseProduct(sc);

	calculateSigmasDirectToReciprocal(true);

	_hasSigmas = true;

}

void Basis::setDirectSigmas(const Matrix3d& sigmas)
{
	_Acov.setZero();

	const Eigen::Vector3d& c0 = sigmas.col(0);
	const Eigen::Vector3d& c1 = sigmas.col(1);
	const Eigen::Vector3d& c2 = sigmas.col(2);

	_Acov.block(0,0,3,3).diagonal() = c0.cwiseProduct(c0);
	_Acov.block(3,3,3,3).diagonal() = c1.cwiseProduct(c1);
	_Acov.block(6,6,3,3).diagonal() = c2.cwiseProduct(c2);

	calculateSigmasDirectToReciprocal(true);

	_hasSigmas = true;
}

void Basis::setDirectCovariance(const covMat& dCov)
{
	_Acov = dCov;

	calculateSigmasDirectToReciprocal(true);

	_hasSigmas = true;
}

const Basis::covMat&  Basis::getDirectCovariance()
{
		return _Acov;
}

const Basis::covMat&  Basis::getReciprocalCovariance()
{
	return _Bcov;
}

} // end namespace Geometry

} // end namespace SX