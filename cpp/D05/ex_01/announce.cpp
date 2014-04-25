//
// annouce.cpp for annouce in /home/Anthony/Epitech/piscine/cpp/24h/ex_01
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 02:03:03 2010 anthony1 corbacho
// Last update Fri May  7 14:06:06 2010 anthony1 corbacho
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include	"announce.h"

announce::announce()
{

}

announce::~announce()
{

}

int	announce::voiceover(int val)
{
  std::cout << "the following take place between "<< val << " and ";
  return (val + 1);
}
