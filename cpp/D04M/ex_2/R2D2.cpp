//
// R2D2.cpp for r2d2 in /home/corbac_b/work/piscine/cpp/D04M/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 11:39:48 2010 anthony1 corbacho
// Last update Thu May  6 15:02:22 2010 anthony1 corbacho
//

#include	<iostream>
#include	<iomanip>
#include	"R2D2.h"

r2d2::r2d2() : _unitPower(200)
{
}

r2d2::~r2d2()
{
}

void	r2d2::Glory() const
{
  std::cout <<" The Rebel Alliance will win"<< std::endl;
}

void	r2d2::Identification() const
{
  std::cout << " bip bip bip "<< std::endl;
}

void	r2d2::PowerLevel() const
{
  float	power;

  power = this->_unitPower * 100 / 200;
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

bool	r2d2::LoadPowerCell(int upPower)
{
  this->_unitPower += upPower;
  if (this->_unitPower >= 200)
    {
      this->_unitPower = 200;
      return (1);
    }
  return (0);
}

void	r2d2::Repare()
{
  if (((this->_unitPower * 100) / 200) >= 5)
    {
      std::cout << "Repairing something" << std::endl;
      this->_unitPower -= (5 * 200) / 100;
    }
}

void	r2d2::Fly()
{
  if ( ((this->_unitPower * 100) / 200) >= 15)
    {
      std::cout << "Fly to a new battle area" << std::endl;
      this->_unitPower -= (15 * 200) / 100;
    }
}
