//
// parseTools.cpp for parsing in /home/corbac_b/work/piscine/cpp/D04A/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 16:40:31 2010 anthony1 corbacho
// Last update Thu May  6 22:13:14 2010 anthony1 corbacho
//

#include	<iostream>
#include	<string>
#include	"parseTools.h"

ParseTools::ParseTools()
{
}

ParseTools::~ParseTools()
{
}

std::string	ParseTools::parseNumber(const std::string& str)
{
  int	pos = 0;

  pos = str.find_first_not_of("0123456789");
  if (pos == (int)(str.size() - 2))
    {
      if (str.compare((str.size() - 2), 2, "LL") == 0)
	return (str);
    }
  throw ("Syntax Error");
}

char		ParseTools::parseOperator(const std::string& str)
{
  int	pos = 0;
  int	pos2 = 0;

  pos = str.find_first_of("+-*/");
  if (pos >= 0)
    {
      pos2 = str.find_first_of("+-*/", pos + 1);
      if (pos2 == -1)
	return (str[pos]);
    }
  throw ("Syntax Error");
}
