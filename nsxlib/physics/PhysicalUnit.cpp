#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
#include <stdexcept>

#include "PhysicalUnit.h"

namespace nsx {

bool PrefixOperator::operator()(double prefix, PhysicalUnitDefinition& unit) const
{
    auto& current_prefix = unit.prefix;
    current_prefix *= prefix;
    return true;
}

bool PowerOperator::operator()(PhysicalUnitDefinition& unit, int power) const
{
    auto& current_prefix = unit.prefix;
    current_prefix = std::pow(current_prefix,power);

    auto& current_scale = unit.scale;
    current_scale = std::pow(current_scale,power);

    auto& dimension = unit.dimension;
    std::for_each(dimension.begin(),dimension.end(), [power](int &element){ element*=power;});

    return true;
}

bool MultiplyOperator::operator()(PhysicalUnitDefinition& unit1, const PhysicalUnitDefinition& unit2) const
{
    auto& current_prefix = unit1.prefix;
    current_prefix *= unit2.prefix;

    auto& current_scale = unit1.scale;
    current_scale *= unit2.scale;

    auto& dimension1 = unit1.dimension;
    auto& dimension2 = unit2.dimension;
    std::transform(dimension1.begin(),dimension1.end(),dimension2.begin(),dimension1.begin(),std::plus<int>());

    return true;
}

bool DivideOperator::operator()(PhysicalUnitDefinition& unit1, const PhysicalUnitDefinition& unit2) const
{
    auto& current_prefix = unit1.prefix;
    current_prefix *= unit2.prefix;

    auto& current_scale = unit1.scale;
    current_scale *= unit2.scale;

    auto& dimension1 = unit1.dimension;
    auto& dimension2 = unit2.dimension;
    std::transform(dimension1.begin(),dimension1.end(),dimension2.begin(),dimension1.begin(),std::minus<int>());

    return true;
}

std::map<std::string,PhysicalUnitDefinition> PhysicalUnit::_definedUnits = {
    {"m"  , {1.0, 1.0, {{ 1, 0, 0, 0, 0, 0, 0, 0}}}}, // meter [length]
    {"s"  , {1.0, 1.0, {{ 0, 1, 0, 0, 0, 0, 0, 0}}}}, // second [time]
    {"K"  , {1.0, 1.0, {{ 0, 0, 1, 0, 0, 0, 0, 0}}}}, // kelvin [temperature]
    {"kg" , {1.0, 1.0, {{ 0, 0, 0, 1, 0, 0, 0, 0}}}}, // kilogram [mass]
    {"A"  , {1.0, 1.0, {{ 0, 0, 0, 0, 1, 0, 0, 0}}}}, // ampere [current]
    {"mol", {1.0, 1.0, {{ 0, 0, 0, 0, 0, 1, 0, 0}}}}, // mole [substance]
    {"cd" , {1.0, 1.0, {{ 0, 0, 0, 0, 0, 0, 1, 0}}}}, // candela [luminosity]
    {"rad" ,{1.0, 1.0, {{ 0, 0, 0, 0, 0, 0, 0, 1}}}}, // candela [luminosity]

    {"b"  , {1.0e-28,               1.0, {{ 2, 0, 0, 0, 0, 0, 0, 0}}}}, // barn [length^2]
    {"ang", {1.0e-10,               1.0, {{ 1, 0, 0, 0, 0, 0, 0, 0}}}}, // angstrom [length]
    {"J"  , {1.0    ,               1.0, {{ 2,-2, 0, 1, 0, 0, 0, 0}}}}, // joule [energy]
    {"eV" , {1.0    ,   1.602176565e-19, {{ 2,-2, 0, 1, 0, 0, 0, 0}}}}, // electron-volt [energy]
    {"min", {1.0    ,              60.0, {{ 0, 1, 0, 0, 0, 0, 0, 0}}}}, // minute [time]
    {"h"  , {1.0    ,            3600.0, {{ 0, 1, 0, 0, 0, 0, 0, 0}}}}, // hour [time]
    {"g"  , {1.0e-3 ,               1.0, {{ 0, 0, 0, 1, 0, 0, 0, 0}}}}, // gram [mass]
    {"y"  , {1.0    ,        31536000.0, {{ 0, 1, 0, 0, 0, 0, 0, 0}}}}, // year [time]
    {"%"  , {1.0    ,            1.0e-2, {{ 0, 0, 0, 0, 0, 0, 0, 0}}}}, // percentage [no unit]
    {"au" , {1.0    ,               1.0, {{ 0, 0, 0, 0, 0, 0, 0, 0}}}}, // arbitrary unit [no unit]
    {"Da" , {1.0    ,1.0-3/6.0221367e23, {{ 0, 0, 0, 0, 0,-1, 0, 0}}}}, // arbitrary unit [no unit]
    {"uma" ,{1.0    ,1.0-3/6.0221367e23, {{ 0, 0, 0, 0, 0,-1, 0, 0}}}}, // arbitrary unit [no unit]
    {"Na" , {1.0    ,      6.0221367e23, {{ 0, 0, 0, 0, 0,-1, 0, 0}}}}, // arbitrary unit [no unit]
    {"deg" ,{1.0    ,        M_PI/180.0, {{ 0, 0, 0, 0, 0, 0, 0, 1}}}}, // trigonometric degree [rad]
};

std::map<std::string,double> PhysicalUnit::_definedPrefixes = {
    {"y" ,1.0e-24}, // yocto
    {"z" ,1.0e-21}, // zepto
    {"a" ,1.0e-18}, // atto
    {"f" ,1.0e-15}, // femto
    {"p" ,1.0e-12}, // pico
    {"n" ,1.0e-09}, // nano
    {"u" ,1.0e-06}, // micro
    {"m" ,1.0e-03}, // milli
    {"c" ,1.0e-02}, // centi
    {"d" ,1.0e-01}, // deci
    {"da",1.0e+01}, // deca
    {"h" ,1.0e+02}, // hecto
    {"k" ,1.0e+03}, // kilo
    {"M" ,1.0e+06}, // mega
    {"G" ,1.0e+09}, // giga
    {"T" ,1.0e+12}, // tera
    {"P" ,1.0e+15}, // peta
    {"E" ,1.0e+18}, // exa
    {"Z" ,1.0e+21}, // zeta
    {"Y" ,1.0e+24}  // yotta
};

std::map<std::array<int,8>,double> PhysicalUnit::_unitEquivalences = {
    {{{ 2,-2, 0, 0, 0, 0, 0, 0}},1.1126500948414508e-17}, // energy to mass (J <--> kg)
    {{{ 2,-2,-1, 1, 0, 0, 0, 0}},7.242971666667e+22},     // energy to temperature (J <--> K)
    {{{ 2,-3, 0, 1, 0, 0, 0, 0}},4108.235723695035},      // energy to time (J <--> s)
    {{{ 1,-2, 0, 1, 0, 0, 0, 0}},1.2316183141775015e12},  // energy to distance (J <--> m)
};

PhysicalUnit::PhysicalUnit(const PhysicalUnit& other)
: _value(other._value),
  _prefix(other._prefix),
  _scale(other._scale),
  _dimension(other._dimension)
{
}

PhysicalUnit::PhysicalUnit(double value, const std::string& unit) : _value(value)
{
    PhysicalUnitDefinition u;
    auto f = unit.begin();
    auto l = unit.end();
    bool unit_parsing_ok = boost::spirit::qi::phrase_parse(f,l,_parser,boost::spirit::qi::space,u);
    if (unit_parsing_ok) {
        _prefix = u.prefix;
        _scale = u.scale;
        _dimension = u.dimension;
    } else {
        throw std::runtime_error("Invalid input unit: "+unit);
    }
}

PhysicalUnit::PhysicalUnit(const std::string& unit) : _value(1.0)
{
    PhysicalUnitDefinition u;
    auto f = unit.begin();
    auto l = unit.end();
    bool unit_parsing_ok = boost::spirit::qi::phrase_parse(f,l,_parser,boost::spirit::qi::space,u);
    if (unit_parsing_ok) {
        _prefix = u.prefix;
        _scale = u.scale;
        _dimension = u.dimension;
    } else {
        throw std::runtime_error("Invalid input unit");
    }

}

PhysicalUnit::PhysicalUnit(double value, double prefix, double scale, const std::array<int,8>& dimension)
: _value(value),
  _prefix(prefix),
  _scale(scale),
  _dimension(dimension)
{
}

PhysicalUnit::PhysicalUnit(double prefix, double scale, const std::array<int,8>& dimension)
: _value(1.0),
  _prefix(prefix),
  _scale(scale),
  _dimension(dimension)
{
}

PhysicalUnit& PhysicalUnit::operator=(const PhysicalUnit& other)
{
    if (this!=&other)
    {
        _value = other._value;
        _prefix = other._prefix;
        _scale = other._scale;
        _dimension = other._dimension;
    }
    return *this;
}

void PhysicalUnit::addPrefix(const std::string& name, double factor)
{
    _definedPrefixes.emplace(name,factor);
    _parser.updatePrefixParser(name,factor);
}

void PhysicalUnit::addUnit(const std::string& name, const PhysicalUnitDefinition& physicalUnit)
{
    _definedUnits.insert(std::make_pair(name,physicalUnit));
    _parser.updateUnitParser(name,physicalUnit);
}

double PhysicalUnit::convert(const std::string& ounit) const
{
    PhysicalUnitDefinition u;
    auto f = ounit.begin();
    auto l = ounit.end();
    bool ok = boost::spirit::qi::phrase_parse(f,l,_parser,boost::spirit::qi::space,u);
    if (ok) {
        return convert(u.prefix,u.scale,u.dimension);
    } else {
        throw std::runtime_error("Invalid output unit");
    }
}

double PhysicalUnit::convert(double oprefix, double oscale, const std::array<int,8>& odimension) const
{
    bool check_dimension_euqlaity = std::equal(_dimension.begin(),_dimension.end(),odimension.begin());
    if (check_dimension_euqlaity)
    {
        double conversionFactor(_value*_prefix*_scale/(oprefix*oscale));
        return conversionFactor;
    } else {
        std::array<int,8> dimDifference;

        std::transform(_dimension.begin(),_dimension.end(),odimension.begin(),dimDifference.begin(), std::minus<int>());

        for (const auto& p : _unitEquivalences)
        {
            auto it1=dimDifference.begin();
            bool proportional=true;
            for (auto it2=p.first.begin();it2!=p.first.end();++it1,++it2)
            {
                if (((*it1)!=0) ^ ((*it2)!=0))
                {
                    proportional=false;
                    break;
                }
            }

            if (!proportional)
                continue;

            int prod=std::inner_product(dimDifference.begin(),dimDifference.end(),p.first.begin(),0);
            int norm2=std::inner_product(p.first.begin(),p.first.end(),p.first.begin(),0);
            double ratio=static_cast<double>(prod)/static_cast<double>(norm2);
            double intpart;
            if (std::abs(std::modf(ratio,&intpart))<1.0e-9)
            {
                double conversionFactor(_value*std::pow(p.second,ratio)*_prefix*_scale/(oprefix*oscale));
                return conversionFactor;
            }
        }

        throw std::runtime_error("Invalid output unit");
    }
}

double PhysicalUnit::prefix() const
{
    return _prefix;
}

double PhysicalUnit::scale() const
{
    return _scale;
}

const std::array<int,8>& PhysicalUnit::dimension() const
{
    return _dimension;
}

void PhysicalUnit::setValue(double value)
{
    _value = value;
}

double PhysicalUnit::value() const
{
    return _value;
}

double PhysicalUnit::toSI() const
{
    return _prefix*_scale*_value;
}

PhysicalUnit::PhysicalUnitParser::PhysicalUnitParser() : PhysicalUnitParser::base_type(_start)
{

    using boost::spirit::qi::_1;
    using boost::spirit::qi::_a;
    using boost::spirit::qi::_pass;
    using boost::spirit::qi::_val;
    using boost::spirit::qi::attr;
    using boost::spirit::qi::int_;
    using boost::spirit::qi::lit;

    boost::phoenix::function<PrefixOperator> const update_prefix = PrefixOperator();
    boost::phoenix::function<PowerOperator> const powerize_unit = PowerOperator();
    boost::phoenix::function<MultiplyOperator> const multiply_unit = MultiplyOperator();
    boost::phoenix::function<DivideOperator> const divide_unit = DivideOperator();

    for (const auto& prefix : _definedPrefixes)
        _prefix.add(prefix.first,prefix.second);

    for (const auto& dim : _definedUnits)
        _unit.add(dim.first,dim.second);

    _prefixedUnit = ((_prefix[_a=_1] >> _unit[_val=_1]) | (attr(1.0)[_a=_1] >> _unit[_val=_1]))[_pass=update_prefix(_a,_val)];

    _poweredUnit = (_prefixedUnit[_val=_1,_a=1] >> -(lit("**") >> int_[_a=_1]))[_pass=powerize_unit(_val,_a)];

    _compositeUnit = (_poweredUnit[_val=_1] >> -((lit("/") >> _poweredUnit[_a=_1])[_pass=divide_unit(_val,_a)] |
                                                         (lit("*") >> _poweredUnit[_a=_1])[_pass=multiply_unit(_val,_a)]));

    _start = _compositeUnit[_val=_1];

}

void PhysicalUnit::PhysicalUnitParser::updatePrefixParser(const std::string& name, double prefix)
{
    _prefix.add(name,prefix);
}

void PhysicalUnit::PhysicalUnitParser::updateUnitParser(const std::string& name, const PhysicalUnitDefinition& physicalUnit)
{
    _unit.add(name,physicalUnit);
}

} // end namespace nsx

