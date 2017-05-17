// author: Jonathan Fisher
// j.fisher@fz-juelich.de

#ifndef NSXTOOL_THREADEDFRAMEITERATOR_H_
#define NSXTOOL_THREADEDFRAMEITERATOR_H_

#include "IData.h"
#include "IFrameIterator.h"
#include "../utils/Types.h"

#include <future>

namespace nsx {

class ThreadedFrameIterator final: public IFrameIterator {
public:
    ThreadedFrameIterator(DataSet& data, unsigned int idx);
    ~ThreadedFrameIterator() = default;
    RealMatrix& getFrame() override;
    void advance() override;

private:
    RealMatrix _currentFrame;
    std::shared_future<RealMatrix> _nextFrame;
    std::shared_future<RealMatrix> getFrameAsync(int idx);
};

} // end namespace nsx

#endif // NSXTOOL_THREADEDFRAMEITERATOR_H_
