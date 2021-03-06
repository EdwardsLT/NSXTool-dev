// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/SymOp.h
//! @brief     Implements module/class/test SymOp
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <ostream>

#include <Eigen/Dense>

#include "CrystalTypes.h"

namespace nsx {

//! \class SymOp
//! \brief Class to represent a symmetry operation of a spacegroup.
class SymOp {

public:
	//! Default constructor should not be used but is needed for swig.
	SymOp()=default;
	//! Construct a symmetry operation by parsing a generator.
	SymOp(std::string generator);
	//! Construct symmetry operation from an Eigen affine transformatiion
	SymOp(const affineTransformation& symmetryOperation);
	//! Copy constructor
	SymOp(const SymOp& other);
	//! Destructor
	~SymOp();
	//! Assignment
	SymOp& operator=(const SymOp& other);
	//! Comparison
	bool operator==(const SymOp& other) const;
	//! Compose symmetry operations
	SymOp operator*(const SymOp& other) const;
	//! Return 4x4 homogeneous matrix representation of the operation
	const affineTransformation& getMatrix() const;
	//! Pretty print
	void print(std::ostream& os) const;
	//! Returns the axis order
	int getAxisOrder() const;
	//! Returns the Jones symbol
	std::string getJonesSymbol() const;
	//! True if has translational part non zero
	bool hasTranslation() const;
	//! Return true if operation is pure translation
	bool isPureTranslation() const;
	//! Return the translation part of the symmetry operator
	Eigen::Vector3d getTranslationPart() const;
	//! Return the rotational part of the symmetry operator
	Eigen::Matrix3d getRotationPart() const;
    //! Return whether the translation part of 'other' is an integral multiple
    //! of the translation part of 'this'. Note: returns false if either is pure rotation.
    //! The return value, if non-zero, is the number n such that
    //! n * this->getTranslationPart() == other.getTranslationPart()
    int translationIsIntegralMultiple(const SymOp& other) const;

private:
	affineTransformation _matrix;
};

std::ostream& operator<<(std::ostream& os, const SymOp& sym);

} // end namespace nsx
