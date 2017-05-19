#include <initializer_list>
#include <stdexcept>

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "../instrument/Diffractometer.h"
#include "../instrument/DiffractometerStore.h"
#include "../utils/Path.h"

namespace nsx {

namespace fs=boost::filesystem;
namespace pt=boost::property_tree;
namespace xml=boost::property_tree::xml_parser;

DiffractometerStore::DiffractometerStore() : Singleton<DiffractometerStore,Constructor,Destructor>()
{
}

sptrDiffractometer DiffractometerStore::buildDiffractometer(const std::string& name) const
{
    fs::path diffractometersPath(Path::getDiffractometersPath());
    diffractometersPath/=name;
    diffractometersPath+=".xml";

    property_tree::ptree root;
    try {
        xml::read_xml(diffractometersPath.string(),root);
    }
    catch (const std::runtime_error& error)	{
        throw std::runtime_error(error.what());
    }

    const property_tree::ptree& instrumentNode=root.get_child("instrument");
    sptrDiffractometer diffractometer(new Diffractometer(instrumentNode));
    return diffractometer;
}

diffractometersList DiffractometerStore::getDiffractometersList() const
{

    diffractometersList diffractometers;

    fs::path diffractometersPath(Path::getDiffractometersPath());

    for (const auto& p : boost::make_iterator_range(fs::directory_iterator(diffractometersPath),fs::directory_iterator()))
    {
        if (!fs::is_regular_file(p) || p.path().extension() != ".xml")
            continue;
        diffractometers.insert(p.path().stem().string());
    }

    return diffractometers;
}

} // end namespace nsx

