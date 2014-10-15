#include "Sample.h"

namespace SX
{
namespace Instrument
{

Sample::Sample() : Component()
{
}

Sample::Sample(const Sample& other) : Component(other)
{
}

Sample::Sample(const std::string& name) : Component(name)
{
}

Sample::~Sample()
{
}

Sample& Sample::operator=(const Sample& other)
{
	if (this != &other)
	{
		Component::operator=(other);
	}
	return *this;
}

}
} /* namespace SX */
