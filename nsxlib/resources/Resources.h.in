// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/chemistry/IsotopeDatabaseManager.h
//! @brief     Implements module/class/test IsotopeDatabaseManager
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <yaml-cpp/yaml.h>

namespace nsx {

using resource_function=std::function<const std::vector<std::string>&()>;

YAML::Node findResource(const std::pair<std::string,std::string>& resource);

void mergeResources(YAML::Node& node1, YAML::Node& node2);

std::set<std::string> getResourcesName(const std::string& resource_type);

} // end namespace nsx
