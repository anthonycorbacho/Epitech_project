//
// R2D2.cpp for r2d2 in /home/corbac_b/work/piscine/cpp/D04M/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 11:39:48 2010 anthony1 corbacho
// Last update Thu May  6 13:42:35 2010 anthony1 corbacho
//

#include	<iostream>
#include	"R2D2.h"

r2d2::r2d2()
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
  Droid::Identification();
  std::cout << " bip bip bip "<< std::endl;
}
