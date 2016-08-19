#ifndef DATAITEM_H
#define DATAITEM_H

#include "TreeItem.h"

namespace SX
{
    namespace Instrument
    {
       class Experiment;
    }
}

class DataItem : public TreeItem
{
public:
    explicit DataItem(std::shared_ptr<Experiment> experiment);
};

#endif // DATAITEM_H