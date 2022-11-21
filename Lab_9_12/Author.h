#pragma once
#include <string>

namespace archi
{
	class Author
	{
	private:
		std::string Name;
		int year;
		std::string PlaceOfBirth;
	public:
		Author();
		Author(std::string, int, std::string);
		std::string GetName();
		int GetíYearOfBirth();
		std::string GetPlaceOfBirth();
		std::string GetInfo();
		friend bool operator<(const Author& a,const Author& b);
		~Author(){}
	};
}
