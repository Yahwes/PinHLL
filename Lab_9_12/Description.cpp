#include "Description.h"

using namespace archi;

Description::Description(std::string _description) { description = _description; }
void Description::AddDescription(std::string _add) { description = description + "\n" + _add; }
void Description::ClearDescription() { description = ""; }
std::string Description::GetDescription() { return description; }