#pragma once
#include <string>

namespace archi
{
	class Material
	{
	private:
		std::string Name;
	public:
		Material(){}
		Material(std::string);
		std::string GetName();
		friend bool operator<(const Material& a,const Material& b);
		~Material(){}
	};
}