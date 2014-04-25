/*
** parseTools.h for parse in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:37:05 2010 anthony1 corbacho
** Last update Thu May 13 13:37:29 2010 anthony1 corbacho
*/


#ifndef __PARSE_T_H__
#define __PARSE_T_H__

#include <iostream>
#include <string>

class ParseTools
{

 public :
  static std::string parseNumber(const std::string& str);
  static char parseOperator(const std::string& str);

};

#endif // __PARSE_T_H__
