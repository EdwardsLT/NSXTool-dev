/*
 * HDF5Data.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: chapon
 */

#include "HDF5Data.h"

namespace SX
{
namespace Data
{

HDF5Data::HDF5Data(const std::string& filename, std::shared_ptr<Diffractometer> instrument, bool inMemory)
:IData(filename,instrument,inMemory)
{

}

HDF5Data::~HDF5Data()
{
}

} // Namespace Data
} // Namespace SX
