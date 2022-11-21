#pragma once
#include "Author.h"
#include "Architecture.h"
#include "Description.h"
#include <string>
#include <set>

namespace archi
{
	class Monument
	{
	private:
		Description description;
		std::set<Author> authors;
		Architecture architecture;
		int YeatConstruction;
	public:
		Monument();
		Monument(std::set<Author>, Description, Architecture, int);
		std::string GetInfo();
		~Monument() {}
	};

}