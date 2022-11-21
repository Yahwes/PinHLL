#pragma once
#include <string>
namespace archi
{
	class Coordinate
	{
	public:
		Coordinate();
		Coordinate(int, int, int);
		std::string GetCoordinate();
		~Coordinate(){}
	private:
		int latitude;
		int longitude;
		int height;
	};
}