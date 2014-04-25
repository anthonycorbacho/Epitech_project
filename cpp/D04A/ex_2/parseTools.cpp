//
// parseTools.cpp for parse in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 13:36:40 2010 anthony1 corbacho
// Last update Thu May 13 13:44:02 2010 anthony1 corbacho
//

#include <iostream>
#include "parseTools.h"
#include "syntaxErrorException.h"

std::string	ParseTools::parseNumber(const std::string& s)
{
  unsigned int		lens = s.length();

  for (unsigned int i = 0; i < (lens - 2); i++)
    if (!(s[i] >= '0' && s[i] <= '9'))
      throw (new SyntaxErrorException());
  
  if (!((s[lens -2] == 'L') && (s[lens -1] == 'L')))
    throw (new SyntaxErrorException());
  
  return (s);
}

char ParseTools::parseOperator(const std::string& s)
{
  bool		b;
  int		flg;
  unsigned int		lens = s.length();

  flg = 0;
  b = 0;
  for (unsigned int i = 0; i < lens; i++)
    {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
	{
	  if (b == 0)
	    {
	      b = 1;
	      flg = i;
	    }
	  else
	    throw (new SyntaxErrorException());
	}
    }
  if (b == 0)
    throw (new SyntaxErrorException());
  return (s[flg]);
}
