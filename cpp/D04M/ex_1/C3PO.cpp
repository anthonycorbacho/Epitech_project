//
// C3PO.cpp for c3po in /home/corbac_b/work/piscine/cpp/D04M/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 11:40:37 2010 anthony1 corbacho
// Last update Thu May  6 12:19:42 2010 anthony1 corbacho
//

#include	<iostream>
#include	"C3PO.h"

c3po::c3po()
{
}

c3po::~c3po()
{
}

void	c3po::Identification() const
{
  Droid::Identification();
  std::cout << " I am C3 PO protocol's droid " << std::endl;
}

void	c3po::Glory() const
{
  std::cout << " The Rebel Alliance will win" << std::endl;
}
