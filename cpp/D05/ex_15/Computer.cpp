//
// Computer.cpp for computer in /home/Anthony/Epitech/piscine/cpp/24h/ex_15
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 15:48:01 2010 anthony1 corbacho
// Last update Fri May  7 16:38:39 2010 anthony1 corbacho
//

#include        <iostream>
#include        <string>
#include        <algorithm>

#include	"Computer.h"

std::string	Computer::getbuffer()
{
    std::string	s;
  
  s = buffer;
  std::reverse(s.begin(), s.end());

  return (s);
}

void		Computer::operator<<(std::string buff)
{
  this->buffer += buff;
}

std::ostream&	operator<<(std::ostream& o, Computer c)
{
  o << c.buffer;
  return (o);
}
