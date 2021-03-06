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

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Path.h"
#include "Resources.h"

namespace nsx {

std::map<std::pair<std::string,std::string>,resource_function> default_resources = {
};

void mergeResources(YAML::Node& node1, YAML::Node& node2) {

    if (node1.Type() != node2.Type()) {
        throw std::runtime_error("Can not merge node of different type");
    }

    if (node1.IsMap()) {
        for (auto it = node2.begin();it!=node2.end();++it) {
            std::string key = it->first.as<std::string>();
            YAML::Node temp_node1=node1[key];
            YAML::Node temp_node2=it->second;
            if (temp_node1) {
                mergeResources(temp_node1,temp_node2);
            } else {
                node1[key] = temp_node2;
            }
        }
    } else if (node1.IsSequence()) {
        for (size_t i = 0; i < node2.size();++i) {
            YAML::Node temp_node1=node1[i];
            YAML::Node temp_node2=node2[i];
            if (temp_node1) {
                mergeResources(temp_node1,temp_node2);
            } else {
                node1.push_back(temp_node2);
            }
        }
    } else if (node1.IsScalar()) {
        node1 = node2;
    }
}

YAML::Node findResource(const std::pair<std::string,std::string>& resource)
{
    YAML::Node resource_yaml;
    auto it = default_resources.find(resource);
    if (it != default_resources.end()) {
        std::stringstream ss;
        for (auto line : it->second()) {
            ss << line << std::endl;
        }
        resource_yaml = YAML::Load(ss);
    }

    auto user_resource_dir = buildPath({applicationDataPath(),resource.first});
    auto user_resource_path = buildPath({user_resource_dir,resource.second+".yml"});

    if (fileExists(user_resource_path)) {
    
        std::ifstream fin(user_resource_path);
        YAML::Node user_yaml = YAML::Load(fin);
        fin.close();

        if (resource_yaml.IsNull()) {
            return user_yaml;
        }
        
        mergeResources(resource_yaml,user_yaml);
        
    } else {
        
        if (resource_yaml.IsNull()) {
            throw std::runtime_error("Unknown resource: "+resource.first+" - "+resource.second);
        }
        
        makeDirectory(user_resource_dir);
        std::ofstream fout(user_resource_path);
        fout << resource_yaml;
        fout.close();
        
    }
    
    return resource_yaml;
}

std::set<std::string> getResourcesName(const std::string& resource_type)
{
    std::set<std::string> resources_name;
    
    for (auto p : default_resources) {
        if (p.first.first.compare(resource_type)==0) {
            resources_name.insert(p.first.second);
        }
    }

    return resources_name;
}

} // end namespace nsx
