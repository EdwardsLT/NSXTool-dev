#define BOOST_TEST_MODULE "Test Peak3D"
#define BOOST_TEST_DYN_LINK
#include "FlatDetector.h"
#include "Peak3D.h"
#include "Sample.h"
#include <boost/test/unit_test.hpp>
#include "Units.h"
#include <Eigen/Dense>
#include <vector>
#include "Gonio.h"
#include "Component.h"
#include "ComponentState.h"
#include "Source.h"
#include "Monochromator.h"

#include <memory>

using SX::Crystal::Peak3D;
using SX::Instrument::DetectorEvent;
using SX::Instrument::FlatDetector;
using SX::Instrument::Gonio;
using SX::Instrument::RotAxis;
using SX::Instrument::Sample;
using SX::Instrument::ComponentState;
using SX::Instrument::Source;

using namespace SX::Units;
const double tolerance=1e-6;

BOOST_AUTO_TEST_CASE(Test_Peak3D)
{
	FlatDetector d("D10-detector");
	d.setDistance(380*mm);
	d.setDimensions(80*mm,80*mm);
	d.setNPixels(32,32);

	DetectorEvent event=d.createDetectorEvent(15.5,15.5);
    std::shared_ptr<Source> source(new Source);

	SX::Instrument::Monochromator mono("mono");

    source->addMonochromator(&mono);
    source->setSelectedMonochromator(0);

	Peak3D peak;
	peak.setDetectorEvent(&event);
    peak.setSource(source);
	Eigen::Vector3d Q=peak.getQ();
	BOOST_CHECK_SMALL(Q[0],tolerance);
	BOOST_CHECK_SMALL(Q[1],tolerance);
	BOOST_CHECK_SMALL(Q[2],tolerance);

	std::shared_ptr<Gonio> g(new Gonio("Gamma"));
	g->addRotation("Gamma",Vector3d(0,0,1),RotAxis::CW);
	d.setGonio(g);

	DetectorEvent event2=d.createDetectorEvent(15.5,15.5,{90.0*deg});
	peak.setDetectorEvent(&event2);
	Q=peak.getQ();
	BOOST_CHECK_CLOSE(Q[0],1,tolerance);
	BOOST_CHECK_CLOSE(Q[1],-1,tolerance);
	BOOST_CHECK_SMALL(Q[2],tolerance);

	Sample sample("sample");
	std::shared_ptr<Gonio> bl(new Gonio("Busing Levy convention"));
	bl->addRotation("omega",Vector3d(0,0,1),RotAxis::CW);
	bl->addRotation("chi",Vector3d(0,1,0),RotAxis::CCW);
	bl->addRotation("phi",Vector3d(0,0,1),RotAxis::CW);
	sample.setGonio(bl);

	ComponentState state=sample.createState({90.0*deg,0.0,0.0});

	peak.setSampleState(&state);
	Q=peak.getQ();
	BOOST_CHECK_CLOSE(Q[0],1,tolerance);
	BOOST_CHECK_CLOSE(Q[1],1,tolerance);
	BOOST_CHECK_SMALL(Q[2],tolerance);

	sample.setRestPosition(Eigen::Vector3d(0,0,0.01*m));
	Q=peak.getQ();
}
