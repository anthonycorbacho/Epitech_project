//
// syntaxErrorException.cpp for syntax in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 13:44:25 2010 anthony1 corbacho
// Last update Thu May 13 13:45:41 2010 anthony1 corbacho
//

#include <iostream>
#include "syntaxErrorException.h"

const char* SyntaxErrorException::what() const throw()
{
  return ("Syntax Error");
}
