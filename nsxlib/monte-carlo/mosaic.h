/*
 * mosaic.h
 *
 *  Created on: Feb 10, 2016
 *      Author: pellegrini
 */

#ifndef MOSAIC_H_
#define MOSAIC_H_

#include <memory>
#include <string>
#include <vector>

#include "InstrumentTypes.h"
#include "Ellipsoid.h"
#include "ConvexHull.h"
#include "Sample.h"

namespace nsx {

class Mosaic
{

public:

	Mosaic(const std::string& instr, double l, double dl, double dMonSam, double mu);

	bool run(const std::vector<std::string>& numors, unsigned int n, double& overlap);

	void setSample(Sample* sample);

	void setMosaicity(double mosaicity);

	virtual ~Mosaic();

private:

	std::shared_ptr<Diffractometer> _diffractometer;

	Sample* _sample;

	double _l;
	double _dl;
	double _dMonSam;
	double _mu;
};

double ellipsoids_overlap(const Ellipsoid& ell1, const Ellipsoid& ell2);

} // namespace nsx
#endif /* MOSAIC_H_ */
