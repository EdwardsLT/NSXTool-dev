#pragma once

#include <iostream>

#include <Eigen/Dense>

namespace nsx {

//! \brief Class to define a vector defined in reciprocal space.
//!
//! This class allows to enforce dimensional and C++-type consistency when
//! dealing with vectors in algorithms dedicated to crystallographic data.
class ReciprocalVector
{
public:

    //! Default constructor
    ReciprocalVector()=default;

    //! Copy constructor
    ReciprocalVector(const ReciprocalVector& other)=default;

    //! Construct a ReciprocalVector from an Eigen row vector
    explicit ReciprocalVector(const Eigen::RowVector3d& rvector);

    //! Assignment operator
    ReciprocalVector& operator=(const ReciprocalVector& other)=default;

    //! Destructor
    ~ReciprocalVector()=default;

    //! Cast operator to an Eigen row vector
    explicit operator const Eigen::RowVector3d& () const;

    //! Return a reference to an element of the vector
    double& operator[](unsigned int index);

    //! Return a reference to an element of the vector
    double& operator()(unsigned int index);

    //! Print information about a ReciprocalVector to a stream
    void print(std::ostream& os) const;

    void getGammaNu(double& gamma, double& nu) const;
    
    double getLorentzFactor() const;

    static double get2Theta(const ReciprocalVector& q, const ReciprocalVector& ki);

private:
    Eigen::RowVector3d _rvector;
};

//! Overload operator<< with ReciprocalVector type
std::ostream& operator<<(std::ostream& os, const ReciprocalVector& rvector);

} // end namespace nsx
