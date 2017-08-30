
#ifndef NSXLIB_PEAKFINDER_H
#define NSXLIB_PEAKFINDER_H

#include "../data/DataTypes.h"
#include "../imaging/ImagingTypes.h"
#include "../utils/UtilsTypes.h"

namespace nsx {

//! Class to handle peak search in datasets
class PeakFinder {

public:

    PeakFinder();

    bool find(DataList numors);

    void setHandler(const sptrProgressHandler& handler);

    void setThresholdValue(double threshold);
    double getThresholdValue();

    void setThresholdType(int type);
    int getThresholdType();

    void setIntegrationConfidence(double confidence);
    double integrationConfidence() const;

    void setSearchConfidence(double confidence);
    double searchConfidence() const;

    void setMinComponents(int minComp);
    int getMinComponents();

    void setMaxComponents(int maxComp);
    int getMaxComponents();

    void setConvolver(sptrConvolver convolver);
    sptrConvolver getConvolver();

    sptrConvolutionKernel getKernel();

    void setKernel(sptrConvolutionKernel kernel);

private:
    sptrProgressHandler _handler;
    sptrConvolver _convolver;
    sptrConvolutionKernel _kernel;

    double _thresholdValue;
    int _thresholdType;

    double _searchConfidence;
    double _integrationConfidence;
    double _median;

    int _minComp;
    int _maxComp;
};

} // end namespace nsx

#endif // NSXLIB_PEAKFINDER_H
