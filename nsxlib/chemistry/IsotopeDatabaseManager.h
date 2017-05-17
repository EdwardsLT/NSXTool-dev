#ifndef NSXLIB_ISOTOPEDATABASEMANAGER_H_
#define NSXLIB_ISOTOPEDATABASEMANAGER_H_

#include <map>
#include <complex>
#include <ostream>
#include <stdexcept>
#include <string>

#include "yaml-cpp/yaml.h"

#include <boost/any.hpp>

#include "../kernel/Singleton.h"
#include "../utils/Types.h"

namespace nsx {

using boost::any_cast;

class IsotopeDatabaseManager : public Singleton<IsotopeDatabaseManager,Constructor,Destructor> {

public:

    enum class PropertyType {String, Int, Double, Complex, Bool};

    static std::map<std::string,PropertyType> PropertyTypes;

    class Isotope {

    public:

        Isotope()=delete;

        Isotope(const Isotope& other)=default;

        Isotope& operator=(const Isotope& other)=default;

        Isotope(const YAML::Node& isotopeNode);

        //! Destructor
        ~Isotope()=default;

        //! Returns the name of this Isotope
        const std::string& getName() const;

        template <typename T>
        T getProperty(const std::string& propertyName) const;

        bool hasProperty(const std::string& propertyName) const;

        //! Print some informations about this Isotope on a stream
        void print(std::ostream& os) const;

    private:

        //! The name of this Isotope
        std::string _name;

        std::map<std::string,boost::any> _properties;
        std::map<std::string,std::string> _units;
        std::map<std::string,std::string> _types;

    };

public:

    using isotopeDatabase = std::map<std::string,IsotopeDatabaseManager::Isotope>;

    IsotopeDatabaseManager();

    ~IsotopeDatabaseManager()=default;

    const Isotope& getIsotope(const std::string& name) const;

    const isotopeDatabase& database() const;

private:

    isotopeDatabase _database;

    static const std::string DatabasePath;

};

template <typename T>
T IsotopeDatabaseManager::Isotope::getProperty(const std::string& propertyName) const
{
    auto pit = _properties.find(propertyName);
    if (pit == _properties.end())
        throw std::runtime_error("Isotope "+_name+": unknown property name ("+propertyName+")");

    return any_cast<T>(pit->second);
}

//! Overloads the operator<< with an Isotope object
std::ostream& operator<<(std::ostream&,const IsotopeDatabaseManager::Isotope&);

} // end namespace nsx

#endif /* NSXLIB_ISOTOPEDATABASEMANAGER_H_ */
