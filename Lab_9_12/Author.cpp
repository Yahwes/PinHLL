#include "Author.h"
using namespace archi;


Author::Author() { year = 0; }
Author::Author(std::string _Name, int _year, std::string _place)
{
	Name = _Name;
	year = _year;
	PlaceOfBirth = _place;
}
std::string Author::GetName() { return Name; }
int Author::GetíYearOfBirth() { return year; }
std::string Author::GetPlaceOfBirth() { return PlaceOfBirth; }
std::string Author::GetInfo()
{
	return "Name: " + Name + "\nYear: " + std::to_string(year) + "\nPlace of birth: " + PlaceOfBirth + "\n";
}
bool archi::operator<(const Author& a, const Author& b)
{
	return (a.Name < b.Name || a.PlaceOfBirth < b.PlaceOfBirth || a.year < b.year);
}
