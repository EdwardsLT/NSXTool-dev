// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/physics/PhysicalUnit.h
//! @brief     Implements module/class/test PhysicalUnit
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#define BOOST_SPIRIT_USE_PHOENIX_V3
#define BOOST_RESULT_OF_USE_DECLTYPE

#include <array>
#include <iostream>
#include <map>
#include <ratio>
#include <string>

#include <boost/fusion/adapted/std_pair.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_lit.hpp>
#include <boost/spirit/include/qi_int.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace nsx {

// Helper struct for defining a physical unit:
// - prefix is a unit prefix (e.g. k=kilo=1.0e-3)
// - scale is a factor that scale the unit from its SI corresponding unit (e.g. angstrom=1.e-10*m)
// - dimension is the array of the dimensions of its corresponding SI unit
struct PhysicalUnitDefinition
{
    double prefix;
    double scale;
    // Define a dimension as a 8 elements array, each element corresponding to one of the SI unit
    // The order is the following [m,s,K,kg,A,mol,cd,angle]
    std::array<int,8> dimension;
};

//! @class: PrefixOperator.
//! Apply a prefix to a given physical unit.
struct PrefixOperator {
    bool operator()(double prefix, PhysicalUnitDefinition& unit) const;
};

//! @class: PowerOperator.
//! Apply the power operator to a given physical unit.
struct PowerOperator {
    bool operator()(PhysicalUnitDefinition& unit, int power) const;
};

//! @class: MultiplyOperator.
//! Multiply a physical unit by another one.
struct MultiplyOperator {
    bool operator()(PhysicalUnitDefinition& unit1, const PhysicalUnitDefinition& unit2) const;
};

//! @class: DivideOperator.
//! Divide a physical unit by another one.
struct DivideOperator {
    bool operator()(PhysicalUnitDefinition& unit1, const PhysicalUnitDefinition& unit2) const;
};

//! @class: PhysicalUnit.
//! Defines a physical unit.
//! A physical unit is defined by setting a value, a prefix, a scale factor and a dimension.
//! When converting from one physical unit to another a dimension analysis is performed.
//! The analysis is based on https://www.cs.utexas.edu/users/novak/units95.pdf
//! For a physical unit to be convertible to another physical unit, the two units must either:
//! - have the same dimension
//! - have an equivalence registered
class PhysicalUnit {

private:
    //! Stores the prefixes defined so far
    static std::map<std::string,double> _definedPrefixes;
    //! Stores the uits defined so far
    static std::map<std::string,PhysicalUnitDefinition> _definedUnits;
    //! Stores the equivalences defined so far
    static std::map<std::array<int,8>,double> _unitEquivalences;

public:

    //! Default constructor (deleted)
    PhysicalUnit()=delete;

    //! Copy constructor
    PhysicalUnit(const PhysicalUnit& other);

    //! Construct a physical unit from a prefix, a scale and a dimension
    //! The value is set to 1.0 by default
    PhysicalUnit(double prefix, double scale, const std::array<int,8>& dimension);

    //! Construct a physical unit from a value, a prefix, a scale and a dimension
    PhysicalUnit(double value, double prefix, double scale, const std::array<int,8>& dimension);

    //! Construct a physical unit from a string encoding the unit
    //! The value is set to 1.0 by default
    //! The string encoding the unit will be parsed by the internal boost::spirit parser
    PhysicalUnit(const std::string& unit);

    //! Construct a physical unit from a value and a string encoding the unit
    //! The string encoding the unit will be parsed by the internal boost::spirit parser
    PhysicalUnit(double value, const std::string& unit);

    //! Assignment operator
    PhysicalUnit& operator=(const PhysicalUnit& other);

    //! Set the value of the physical unit
    void setValue(double value);
    //! Return the value of the physical unit
    double value() const;

    //! Return the prefix of the physical unit
    double prefix() const;

    //! Return the scale of the physical unit
    double scale() const;

    //! Return the dimension of the physical unit
    const std::array<int,8>& dimension() const;

    //! Return the value of the physical unit converted into SI unit
    double toSI() const;

    //! Add a new prefix to the prefixes defined statically so far
    void addPrefix(const std::string& name, double factor);

    //! Add a new unit to the prefixes defined statically so far
    void addUnit(const std::string& name, const PhysicalUnitDefinition& physicalUnit);

    //! Return the value of the conversion from the physical unit to another one
    double convert(const std::string& ounit) const;

    //! Return the value of the conversion from the physical unit to another one
    double convert(double oprefix, double oscale, const std::array<int,8>& odimension) const;

private:
    //! Inner class that defines the boost::spirit parser for a physical unit
    struct PhysicalUnitParser : boost::spirit::qi::grammar<std::string::const_iterator, PhysicalUnitDefinition()> {
        //! Default constructor
        PhysicalUnitParser();

        //! Copy constructor (deleted)
        PhysicalUnitParser(const PhysicalUnitParser& other)=delete;

        //! Assignment operator (deleted)
        PhysicalUnitParser& operator=(const PhysicalUnitParser& other)=delete;

    public:
        //! Update the symbols defined so far for the prefixes
        void updatePrefixParser(const std::string& name, double prefix);

        //! Update the symbols defined so far for the physical units
        void updateUnitParser(const std::string& mame, const PhysicalUnitDefinition& physicalUnit);

    private:
        //! Defines the rule for matching a prefix
        boost::spirit::qi::symbols<char,double> _prefix;
        //! Defines the rule for matching a unit
        boost::spirit::qi::symbols<char,PhysicalUnitDefinition> _unit;
        //! Defines the rule for matching a prefixed unit
        boost::spirit::qi::rule<std::string::const_iterator,PhysicalUnitDefinition(),boost::spirit::qi::locals<double>> _prefixedUnit;
        //! Defines the rule for matching a prefixed unit with an integer exponent
        boost::spirit::qi::rule<std::string::const_iterator,PhysicalUnitDefinition(),boost::spirit::qi::locals<int>> _poweredUnit;
        //! Defines the rule for matching an arithmetic expression of several physical units
        boost::spirit::qi::rule<std::string::const_iterator,PhysicalUnitDefinition(),boost::spirit::qi::locals<PhysicalUnitDefinition>> _compositeUnit;
        //! The starting rule
        boost::spirit::qi::rule<std::string::const_iterator,PhysicalUnitDefinition()> _start;
    };

private:

    PhysicalUnitParser _parser;
    double _value;
    double _prefix;
    double _scale;
    std::array<int,8> _dimension;

};

} // end namespace nsx
