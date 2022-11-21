#pragma once
#include <string>

namespace archi
{
	class Description
	{
	private:
		std::string description;
	public:
		Description(){}
		Description(std::string);
		void AddDescription(std::string);
		void ClearDescription();
		std::string GetDescription();
		~Description(){}
	};
}