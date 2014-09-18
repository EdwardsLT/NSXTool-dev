#define BOOST_TEST_MODULE "Test Lattice Finder"
#define BOOST_TEST_DYN_LINK
#include "UnitCell.h"
#include "LatticeFinder.h"
#include <boost/test/unit_test.hpp>
#include "Units.h"
#include <Eigen/Dense>
#include <vector>
#include <iostream>

using namespace SX::Crystal;
using namespace SX::Units;
const double tolerance=1e-6;
BOOST_AUTO_TEST_CASE(Test_Lattice_Finder)
{
	UnitCell cell(5,5,9,90,90,90);
	SX::Crystal::LatticeFinder finder(1e-3,1e-3);
	for (int h=-3;h<4;++h)
	{
		for (int k=-3;k<4;++k)
			{
			for (int l=-3;l<4;++l)
				{
					finder.addPoint(cell.toReciprocalStandard(Eigen::RowVector3d(h,k,l)));
				}
			}
	}
	finder.run(3.0);
	std::vector<SX::Crystal::LatticeSolution> solutions=finder.determineLattice(30,30);
	for (auto& solution : solutions)
	{
		std::cout << SX::Crystal::UnitCell::fromReciprocalVectors(std::get<0>(solution),std::get<1>(solution),std::get<2>(solution)).getVolume() <<std::endl;
	}
}