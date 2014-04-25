//
// longLongOverflowException.cpp for lon in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 13:33:10 2010 anthony1 corbacho
// Last update Thu May 13 13:33:12 2010 anthony1 corbacho
//

#include "longLongOverflowException.h"

const char* LongLongOverflowException::what() const throw()
{
  return ("Long Long Overflow");
}
