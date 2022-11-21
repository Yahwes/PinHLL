#include <iostream>
#include <set>
#include <string>
#include "Monument.h"
#include "Architecture.h"
using namespace archi;

int main()
{
	int x, y, z;
	std::cout << "Enter the coordinate of the architectural structure\nLatitude: ";
	std::cin >> x;
	std::cout << "Longitude: ";
	std::cin >> y;
	std::cout << "Height: ";
	std::cin >> z;
	Coordinate xyz(x % 90, y % 180, z);
	
	int countmaterials;
	std::cout << "\nEnter the number of types of materials that the architectural object consist of: ";
	std::cin >> countmaterials;
	std::cout << "Enter materials: ";
	std::set<Material> materials;
	while (countmaterials--)
	{
		std::string temp;
		std::cin >> temp;
		Material a(temp);
		materials.insert(a);
	}

	std::cout << "\nEnter description of the monument: ";
	std::string desc;
	rewind(stdin);
	std::getline(std::cin, desc);
	Description description(desc);

	std::cout << "\nEnter the number of monument authors: ";
	int countauthors;
	std::cin >> countauthors;
	std::set<Author> authors;
	while (countauthors--)
	{
		std::string name;
		std::cout << "\nEnter author name: ";
		std::cin >> name;
		int year;
		std::cout << "Enter year of birth of the author: ";
		std::cin >> year;
		std::string place;
		std::cout << "Enter thr place of birth of the author: ";
		std::cin >> place;

		Author temp(name, year, place);
		authors.insert(temp);
	}

	int yearconstruction;
	std::cout << "\nEnter the year the monument was built: ";
	std::cin >> yearconstruction;

	Architecture architecture(materials, xyz);

	Monument result(authors, description, architecture, yearconstruction);
	std::cout << "\n\n\nMonument.GetInfo():\n";
	std::cout << result.GetInfo();
	return 1;
}