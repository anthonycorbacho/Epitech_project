//
// C3PO.cpp for c3po in /home/corbac_b/work/piscine/cpp/D04M/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 11:40:37 2010 anthony1 corbacho
// Last update Thu May  6 15:03:18 2010 anthony1 corbacho
//

#include	<iostream>
#include	<iomanip>
#include	"C3PO.h"

c3po::c3po() : _unitPower(400)
{
}

c3po::~c3po()
{
}

void	c3po::Identification() const
{
  std::cout << " I am C3 PO protocol's droid " << std::endl;
}

void	c3po::Glory() const
{
  std::cout << " The Rebel Alliance will win" << std::endl;
}

void	c3po::PowerLevel() const
{
  float power;

  power = this->_unitPower * 100 / 400;
  std::cout.precision(2);
  std::cout
    <<
    "PowerCell : "
    <<
    std::fixed << power
    <<
    "%"
    << std::endl;
}

bool	c3po::LoadPowerCell(int upPower)
{
  this->_unitPower += upPower;
  if (this->_unitPower >= 400)
    {
      this->_unitPower = 400;
      return (1);
    }
  return (0);

}

void	c3po::Speak()
{
  if (((this->_unitPower * 100) / 400) >= 1)
    {
      std::cout << "You must listen our master r2!" << std::endl;
      this->_unitPower -= (1 * 200) / 100;
    }
}

void	c3po::Escape()
{
  if (((this->_unitPower * 100) / 400) >= 20)
    {
      std::cout << "Runaway R2 quickly!" << std::endl;
      this->_unitPower -= (20 * 400) / 100;
    }
}
