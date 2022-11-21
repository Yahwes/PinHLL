#include "Architecture.h"

using namespace archi;
Architecture::Architecture(std::set<Material> _material, Coordinate _coordinate) 
{
	material = _material;
	coordinate = _coordinate;
}
std::string Architecture::GetInfo()
{
	std::string res = "";
	for (auto i : material)
		res = res + i.GetName() + "\n";
	return ("Materials:\n" +  res + "\n" + coordinate.GetCoordinate());
}