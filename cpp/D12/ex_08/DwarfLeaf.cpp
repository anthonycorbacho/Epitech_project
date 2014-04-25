#include "DwarfLeaf.h"

DwarfLeaf::DwarfLeaf(std::string const &name)
{
  _name = name;
}

DwarfLeaf::~DwarfLeaf()
{
}

void		DwarfLeaf::raler() const
{
  std::cout
    << "<"
    << _name
    << "> Eh, vous allez m'ecouter ? Je cherche ma hache !"
    << std::endl;
}
