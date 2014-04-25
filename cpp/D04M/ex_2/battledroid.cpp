//
// battledroid.cpp for battledroid in /home/corbac_b/work/piscine/cpp/D04M/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 14:09:09 2010 anthony1 corbacho
// Last update Thu May  6 15:03:47 2010 anthony1 corbacho
//

#include	<iostream>
#include	<iomanip>

#include	"battledroid.h"

battledroid::battledroid() : _unitPower(1000)
{
}

battledroid::~battledroid()
{
}

void    battledroid::Glory() const
{
  std::cout <<" Hell, it's about time"<< std::endl;
}

void    battledroid::Identification() const
{
  std::cout << " Zog Zog "<< std::endl;
}

void    battledroid::PowerLevel() const
{
  float power;

  power = this->_unitPower * 100 / 1000;
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

bool    battledroid::LoadPowerCell(int upPower)
{
  this->_unitPower += upPower;
  if (this->_unitPower >= 1000)
    {
      this->_unitPower = 1000;
      return (1);
    }
  return (0);
}

void	battledroid::Shield()
{
  if (((this->_unitPower * 100) / 1000) >= 10)
    {
      std::cout << "Shield protection activated!" << std::endl;
      this->_unitPower -= (10 * 1000) / 100;
    }
}

void	battledroid::Blast()
{
  if (((this->_unitPower * 100) / 1000) >= 5)
    {
      std::cout << "tiou tiou tiou!" << std::endl;
      this->_unitPower -= (5 * 200) / 100;
    }
}
