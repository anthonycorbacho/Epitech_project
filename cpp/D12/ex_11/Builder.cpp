#include "Builder.h"

Builder::Builder(std::string const &type)
{
  _type = type;
}

Builder::~Builder()
{
}

void		Builder::BuildCar(int model)
{
  if (model == 42)
    {
      std::cout
	<< _type
	<< " Building a Porsche"
	<< std::endl;
    }
  else
    {
      std::cout << _type
		<< " Building a twingo"
		<< std::endl;
    }
}


