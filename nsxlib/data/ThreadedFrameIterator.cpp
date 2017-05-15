#include "IFrameIterator.h"
#include "ThreadedFrameIterator.h"
#include "IData.h"

#include <future>

namespace nsx {
namespace Data {

ThreadedFrameIterator::ThreadedFrameIterator(DataSet& data, unsigned int idx)
    :IFrameIterator(data, idx),
     _currentFrame(),
     _nextFrame()
{
    // unused variable
    //std::launch policy = std::launch::async;
    unsigned int nframes = _data.getNFrames();

    if (_index < nframes) {
        _currentFrame = _data.getFrame(_index).cast<double>();
    }

    if ( _index+1 < nframes ) {
        _nextFrame = getFrameAsync(_index+1);
    }
}

Types::RealMatrix &ThreadedFrameIterator::getFrame()
{
    assert(_index < _data.getNFrames() );
    return _currentFrame;
}

void ThreadedFrameIterator::advance()
{
    unsigned int nframes = _data.getNFrames();
    ++_index;

    if (_index < nframes) {
        _currentFrame = _nextFrame.get();
    }

    if (_index+1 < nframes) {
        _nextFrame = getFrameAsync(_index+1);
    }
}

std::shared_future<nsx::Types::RealMatrix> ThreadedFrameIterator::getFrameAsync(int idx)
{
    auto get_fn = [=] () -> nsx::Types::RealMatrix {
        return _data.getFrame(idx).cast<double>();
    };
    std::launch policy = std::launch::async;
    return std::shared_future<nsx::Types::RealMatrix>(std::async(policy, get_fn));
}

/**/

} // namespace Data
} // namespace nsx
