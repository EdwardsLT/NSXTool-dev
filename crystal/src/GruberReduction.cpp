#include "GruberReduction.h"
#include <cmath>
#include <iostream>

namespace SX
{
namespace Crystal
{

GruberReduction::GruberReduction(const Eigen::Matrix3d& g, double epsilon)
{
	_g=g;
	_epsilon=epsilon;
}

void GruberReduction::reduce(Eigen::Matrix3d& P,UnitCell::Centring& centring)
{
	double A=_g(0,0);
	double B=_g(1,1);
	double C=_g(2,2);
	double D=_g(1,2);
	double E=_g(0,2);
	double F=_g(0,1);

	bool typeI=(D*E*F>0);

	if (equal(A,B) && equal(B,C)) //A=B=C
	{
		if (typeI && equal(D,0.5*A) && equal(E,0.5*A) && equal(F,0.5*A)) // Condition 1
		{
			centring=UnitCell::Centring::F;
			P << 1, 1,-1,
				-1, 1, 1,
				 1,-1, 1;
			return;
		}
		if (typeI && equal(E,D) && equal(F,D)) // Condition 2
		{
			centring=UnitCell::Centring::R;
			P << 1,-1,-1,
				-1, 0,-1,
				 0, 1,-1;
			return;
		}
		if (!typeI && equal(D,0) && equal(E,0) && equal(F,0)) // Condition 3
		{
			centring=UnitCell::Centring::P;
			P << 1, 0, 0,
				 0, 1, 0,
				 0, 0, 1;
			return;
		}
		if (!typeI && equal(D,-A/3) && equal(E,-A/3) && equal(F,-A/3)) // Condition 5
		{
			centring=UnitCell::Centring::I;
			P << 1, 1, 0,
				 0, 1, 1,
				 1, 0, 1;
			return;
		}
		if (!typeI && equal(D,E) && equal(D,F)) // Condition 4
		{
			centring=UnitCell::Centring::R;
			P << 1,-1,-1,
				-1, 0,-1,
				 0, 1,-1;
			return;
		}
		if (!typeI && equal(D,E) && equal(A+B,2.0*std::fabs(D+E+F))) // Condition 6
		{
			centring=UnitCell::Centring::I;
			P << 0, 1, 1,
				 1, 0, 1,
				 1, 1, 0;
			return;
		}
		if (!typeI && equal(E,F) && equal(A+B,2.0*std::fabs(D+E+F))) // Condition 7
		{
			centring=UnitCell::Centring::I;
			P << 1, 1, 0,
				 0, 1, 1,
				 1, 0, 1;
			return;
		}
		if (!typeI && equal(A+B,2.0*std::fabs(D+E+F))) // Condition 8
		{
			centring=UnitCell::Centring::I;
			P << -1,-1, 0,
				 -1, 0,-1,
				  0,-1,-1;
			return;
		}
	}
	else if (equal(A,B))
	{
		if (typeI && equal(D,A/2) && equal(E,A/2) && equal(F,A/2)) // Condition 9
		{
			centring=UnitCell::Centring::R;
			P <<  1,-1,-1,
				  0, 1,-1,
				  0, 0, 3;
			return;
		}
		if (typeI && equal(D,E)) // Condition 10
		{
			centring=UnitCell::Centring::C;
			P <<  1, 1, 0,
				  1,-1, 0,
				  0, 0,-1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0) && equal(F,0.0)) // Condition 11
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0) && equal(F,-A/2)) // Condition 12
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0)) // Condition 13
		{
			centring=UnitCell::Centring::C;
			P <<  1,-1, 0,
				  1, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,-A/2) && equal(E,-A/2) && equal(F,0.0)) // Condition 15
		{
			centring=UnitCell::Centring::I;
			P <<  1, 0, 1,
				  0, 1, 1,
				  0, 0, 2;
			return;
		}
		if (!typeI && equal(D,E) && equal(A+B,2.0*std::fabs(D+E+F))) // Condition 16
		{
			centring=UnitCell::Centring::F;
			P << -1, 1, 1,
				 -1,-1, 1,
				  0, 0, 2;
			return;
		}
		if (!typeI && equal(D,E)) // Condition 14
		{
			centring=UnitCell::Centring::C;
			P <<  1,-1, 0,
				  1, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(A+B,2.0*std::fabs(D+E+F))) // Condition 17
		{
			centring=UnitCell::Centring::C;
			P <<  1, 1,-1,
				 -1, 1, 0,
				  0, 0,-1;
			return;
		}
	}
	else if (equal(B,C))
	{
		if (typeI && equal(D,A/4) && equal(E,A/2) && equal(F,A/2)) // Condition 18
		{
			centring=UnitCell::Centring::I;
			P <<  0, 1, 1,
				 -1,-1, 0,
				  1,-1, 0;
			return;
		}
		if (typeI && equal(E,A/2) && equal(F,A/2)) // Condition 19
		{
			centring=UnitCell::Centring::I;
			P << -1, 0,-1,
				  0,-1, 1,
				  0, 1, 1;
			return;
		}
		if (typeI && equal(E,F)) // Condition 20
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0,-1,
				  1, 1, 0,
				  1,-1, 0;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0) && equal(F,0.0)) // Condition 21
		{
			centring=UnitCell::Centring::P;
			P <<  0, 0, 1,
				  1, 0, 0,
				  0, 1, 0;
			return;
		}
		if (!typeI && equal(D,-B/2) && equal(E,0.0) && equal(F,0.0)) // Condition 22
		{
			centring=UnitCell::Centring::P;
			P <<  0, 0, 1,
				  1, 0, 0,
				  0, 1, 0;
			return;
		}
		if (!typeI && equal(E,0.0) && equal(F,0.0)) // Condition 23
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0, 1,
				  1,-1, 0,
				  1, 1, 0;
			return;
		}
		if (!typeI && equal(A+B,2.0*std::fabs(D+E+F)) && equal(E,-A/3) && equal(F,-A/3)) // Condition 24
		{
			centring=UnitCell::Centring::R;
			P <<  1, 0, 1,
				  2,-1, 0,
				  1, 1, 0;
			return;
		}
		if (!typeI && equal(E,F)) // Condition 25
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0, 1,
				  1,-1, 0,
				  1, 1, 0;
			return;
		}
	}
	else
	{
		if (typeI && equal(D,A/4) && equal(E,A/2) && equal(F,A/2)) // Condition 26
		{
			centring=UnitCell::Centring::F;
			P <<  1,-1,-1,
				  0, 2, 0,
				  0, 0, 2;
			return;
		}
		if (typeI && equal(E,A/2) && equal(F,A/2)) // Condition 27
		{
			centring=UnitCell::Centring::C;
			P << -1,-1, 0,
				  2, 0,-1,
				  0, 0, 1;
			return;
		}
		if (typeI && equal(E,A/2) && equal(F,2*D)) // Condition 28
		{
			centring=UnitCell::Centring::C;
			P << -1,-1, 0,
				  0, 0, 1,
				  0, 2, 0;
			return;
		}
		if (typeI && equal(E,2*D) && equal(F,A/2)) // Condition 29
		{
			centring=UnitCell::Centring::C;
			P <<  1, 1, 0,
				  0,-2, 0,
				  0, 0,-1;
			return;
		}
		if (typeI && equal(D,B/2) && equal(F,2*E)) // Condition 30
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0,-1,
				  1, 1, 0,
				  0,-2, 0;
			return;
		}
		if (typeI) // Condition 31
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0) && equal(F,0.0)) // Condition 32
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,-B/2) && equal(E,0.0) && equal(F,0.0)) // Condition 40
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0,-1,
				 -1, 1, 0,
				  0, 2, 0;
			return;
		}
		if (!typeI && equal(E,0.0) && equal(F,0.0)) // Condition 35
		{
			centring=UnitCell::Centring::P;
			P <<  0,-1, 0,
				 -1, 0, 0,
				  0, 0,-1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,-A/2) && equal(F,0.0)) // Condition 36
		{
			centring=UnitCell::Centring::C;
			P <<  1,-1, 0,
				  0, 0, 1,
				  0,-2, 0;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(F,0.0)) // Condition 33
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0) && equal(F,-A/2)) // Condition 38
		{
			centring=UnitCell::Centring::C;
			P << -1, 1, 0,
				  0, 2, 0,
				  0, 0,-1;
			return;
		}
		if (!typeI && equal(D,0.0) && equal(E,0.0)) // Condition 34
		{
			centring=UnitCell::Centring::P;
			P << -1, 0, 0,
				  0, 0,-1,
				  0,-1, 0;
			return;
		}
		if (!typeI && equal(D,-B/2) && equal(E,-A/2) && equal(F,0.0)) // Condition 42
		{
			centring=UnitCell::Centring::I;
			P << -1, 0, 1,
				  0,-1, 1,
				  0, 0, 2;
			return;
		}
		if (!typeI && equal(D,-B/2) && equal(F,0.0)) // Condition 41
		{
			centring=UnitCell::Centring::C;
			P <<  0, 0,-1,
				 -1,-1, 0,
				 -2, 0, 0;
			return;
		}
		if (!typeI && equal(E,-A/2) && equal(F,0.0)) // Condition 37
		{
			centring=UnitCell::Centring::C;
			P <<  1, 1, 0,
				  0, 0, 1,
				  2, 0, 0;
			return;
		}
		if (!typeI && equal(E,0.0) && equal(F,-A/2)) // Condition 39
		{
			centring=UnitCell::Centring::C;
			P << -1,-1, 0,
				 -2, 0, 0,
				  0, 0,-1;
			return;
		}
		if (!typeI && equal(A+B,2.0*std::fabs(D+E+F)) && equal(B,std::fabs(2*D+F))) // Condition 43
		{
			centring=UnitCell::Centring::I;
			P << -1,-1, 0,
				  0,-1,-1,
				  0,-2, 0;
			return;
		}
		if (!typeI) // Condition 44
		{
			centring=UnitCell::Centring::P;
			P <<  1, 0, 0,
				  0, 1, 0,
				  0, 0, 1;
			return;
		}
	}
}

bool GruberReduction::equal(double A, double B) const
{
	return (std::fabs(A-B)<_epsilon);
}

}
}