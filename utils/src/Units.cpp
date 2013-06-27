#include "Units.h"
#include <stdexcept>

namespace SX
{
namespace Units
{

// Needs c++0x features enabled to be able to initialize the map in the following way
std::unordered_map<std::string,double> UnitsManager::_unitsMap =
{
		{"m",m   },
		{"cm",cm  },
		{"mm",mm  },
		{"um",um  },
		{"nm",nm  },
		{"pm",pm  },
		{"fm",fm  },
		{"am",am  },
		{"m2",m2  },
		{"cm2",cm2 },
		{"mm2",mm2 },
		{"um2",um2 },
		{"nm2",nm2 },
		{"pm2",pm2 },
		{"am2",am2 },
		{"barn",barn},
		{"m3",m3  },
		{"cm3",cm3 },
		{"mm3",mm3 },
		{"um3",um3 },
		{"nm3",nm3 },
		{"pm3",pm3 },
		{"fm3",fm3 },
		{"am3",am3 },
		{"rad",rad },
		{"deg",deg },
		{"mrad",mrad},
		{"str",str },
		{"s",s   },
		{"ms",ms  },
		{"us",us  },
		{"min",min },
		{"hour",hour},
		{"day",day },
		{"year",year},
		{"perCent", perCent},
		{"%", perCent}
};

double UnitsManager::get(const std::string& key)
{
	auto it=_unitsMap.find(key);
	if (it==_unitsMap.end())
		throw std::invalid_argument("Unit "+key+" not registered in the database");
	return (*it).second;
}

} // End namespace Units
} // End namespace SX
