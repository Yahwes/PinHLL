#include "Material.h"

using namespace archi;

Material::Material(std::string _Name) { Name = _Name; }
bool archi::operator<(const Material& a,const Material& b) { return a.Name < b.Name; }
std::string Material::GetName() { return Name; }