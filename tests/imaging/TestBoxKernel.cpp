#define BOOST_TEST_MODULE "Test Box Kernel"
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <map>
#include <string>

#include <Eigen/Dense>

#include "BoxKernel.h"

BOOST_AUTO_TEST_CASE(Test_Box_kernel)
{

	SX::Imaging::BoxKernel boxk(5,{});

	Eigen::MatrixXd data=Eigen::MatrixXd::Ones(10,10);

	std::cout<<boxk<<std::endl;

	std::cout<<boxk(data)<<std::endl;
}

