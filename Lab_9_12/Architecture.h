#pragma once
#include <string>
#include "Coordinate.h"
#include "Material.h"
#include <set>

namespace archi
{
	class Architecture
	{
	public:
		Architecture() {}
		Architecture(std::set<Material> , Coordinate);
		std::string GetInfo();
		~Architecture(){}
	private:
		std::set<Material> material;
		Coordinate coordinate;
	};
}