#include "Constants.h"
#include "RotAxis.h"

namespace SX
{
RotAxis::RotAxis(const std::string& label,const V3D& axis, Rotation direction):_name(label),_axis(axis),_dir(direction)
{
}
RotAxis::~RotAxis()
{
}

std::string& RotAxis::getLabel()
{
	return _name;
}
const std::string& RotAxis::getLabel() const
{
	return _name;
}
Matrix33<double> RotAxis::getMatrix(double angle,AngleUnit unit) const
{
	Quat temp(getQuat(angle,unit));
	return temp.toMatrix();
}
Quat RotAxis::getQuat(double angle,AngleUnit unit) const
{
	if (_dir==SX::CW)
		angle*=-1;
	if (unit==SX::Degrees)
		angle*=Constants::deg2rad;
	// Create the quaternion representing this rotation
	Quat temp(angle,_axis);
	return temp;
}

} // End namespace SX

