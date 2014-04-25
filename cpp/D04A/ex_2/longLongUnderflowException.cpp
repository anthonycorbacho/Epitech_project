//
// longLongUnderflowException.cpp for long in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 13:35:06 2010 anthony1 corbacho
// Last update Thu May 13 13:35:16 2010 anthony1 corbacho
//

#include <iostream>
#include "longLongUnderflowException.h"

const char* LongLongUnderflowException::what() const throw()
{
  return ("Long Long Underflow");
}
