// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/DetectorFactory.h
//! @brief     Implements module/class/test DetectorFactory
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>

#include <yaml-cpp/yaml.h>

#include "Detector.h"
#include "Factory.h"
#include "Singleton.h"

namespace nsx {

//! \brief Factory class for producing different detector geometries.
class DetectorFactory : public Factory<Detector,std::string,const YAML::Node&>, public Singleton<DetectorFactory,Constructor,Destructor> {
private:
    friend class Constructor<DetectorFactory>;
    friend class Destructor<DetectorFactory>;
    DetectorFactory();
    ~DetectorFactory();
};

} // end namespace nsx
