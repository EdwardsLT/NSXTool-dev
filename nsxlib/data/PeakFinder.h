
#ifndef NSXTOOL_PEAKFINDER_H_
#define NSXTOOL_PEAKFINDER_H_

#include <memory>

#include "../imaging/Convolver.h"
#include "../imaging/ConvolutionKernel.h"


namespace SX
{

namespace Imaging
{
class Convolver;
}

namespace Utils
{
class ProgressHandler;
}

namespace Data
{

class DataSet;

class PeakFinder
{
public:
    PeakFinder();
    bool find(std::vector<std::shared_ptr<DataSet>> numors);

    void setHandler(const std::shared_ptr<SX::Utils::ProgressHandler>& handler);

    void setThresholdValue(double threshold);
    double getThresholdValue();

    void setThresholdType(int type);
    int getThresholdType();

    void setConfidence(double confidence);
    double getConfidence();

    void setMinComponents(int minComp);
    int getMinComponents();

    void setMaxComponents(int maxComp);
    int getMaxComponents();

    void setConvolver(const std::shared_ptr<SX::Imaging::Convolver>& convolver);
    std::shared_ptr<SX::Imaging::Convolver> getConvolver();

    void setConvolutionKernel(const std::shared_ptr<SX::Imaging::ConvolutionKernel>& kernel);

    void setKernel(const std::shared_ptr<SX::Imaging::ConvolutionKernel>& kernel);
    std::shared_ptr<SX::Imaging::ConvolutionKernel> getKernel();

private:
    std::shared_ptr<SX::Utils::ProgressHandler> _handler;
    std::shared_ptr<SX::Imaging::Convolver> _convolver;
    std::shared_ptr<SX::Imaging::ConvolutionKernel> _kernel;

    double _thresholdValue;
    int _thresholdType;

    double _confidence;
    double _median;

    int _minComp;
    int _maxComp;
};

} // namespace Data

} // namespace SX

#endif // PEAKFINDER_H
