//
// bomber.cpp for bomber in /home/Anthony/Epitech/piscine/cpp/24h/ex_17
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 17:31:13 2010 anthony1 corbacho
// Last update Fri May  7 17:27:42 2010 anthony1 corbacho
//


#include        <iostream>
#include        <string>
#include        "terrorist.h"
#include	"bomber.h"

void    Bomber::setBomb()
{
  this->_bomb = 1;
}

void    Bomber::kaboom()
{
  if (this->_bomb != 1)
    std::cout << "KABOOM!" << std::endl;
}
