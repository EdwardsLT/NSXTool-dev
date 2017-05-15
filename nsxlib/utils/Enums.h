#ifndef NSXLIB_KERNEL_ENUMS_H_
#define NSXLIB_KERNEL_ENUMS_H_

namespace nsx {

enum class DataOrder : size_t {TopLeftColMajor=0,
                               TopLeftRowMajor=1,
                               TopRightColMajor=2,
                               TopRightRowMajor=3,
                               BottomLeftColMajor=4,
                               BottomLeftRowMajor=5,
                               BottomRightColMajor=6,
                               BottomRightRowMajor=7};

} // end namespace nsx

#endif // NSXLIB_KERNEL_ENUMS_H_
