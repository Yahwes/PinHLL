#include "Coordinate.h"

using namespace archi;

Coordinate::Coordinate()
{
	latitude = longitude = height = 0;
}

Coordinate::Coordinate(int _latitude, int _longitude, int _height)
{
	latitude = _latitude;
	longitude = _longitude;
	height = _height;
}
std::string Coordinate::GetCoordinate()
{
	return "Latitude: " + std::to_string(latitude) + "\nLongitude: " + std::to_string(longitude) + "\nHeight: " + std::to_string(height);
}