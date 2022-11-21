#include "Monument.h"
#include "Architecture.cpp"
using namespace archi;

Monument::Monument() { YeatConstruction = 0;  }

Monument::Monument(std::set<Author> _authors, Description _description, Architecture _architecture, int year)
{
	authors = _authors;
	description = _description;
	architecture = _architecture;
	YeatConstruction = year;
}

std::string Monument::GetInfo()
{
	std::string res = "";
	
	for (auto i : authors)
		res = res + i.GetInfo() + "\n";
	
	return "Info about authors: \n" + res + "Info about architecture: \n" + architecture.GetInfo() + "\n\nDescription: " + description.GetDescription();
}
