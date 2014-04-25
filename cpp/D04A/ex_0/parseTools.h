/*
** parseTools.h for parsing in /home/corbac_b/work/piscine/cpp/D04A/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 16:34:29 2010 anthony1 corbacho
** Last update Thu May  6 17:23:47 2010 anthony1 corbacho
*/

#ifndef		__PARSING_H__
#define		__PARSING_H__

#include	<iostream>
#include	<string>

class		ParseTools
{
 public:
  ParseTools();
  ~ParseTools();

  static std::string	parseNumber(const std::string& str);
  static char		parseOperator(const std::string& str);
};

#endif		//__PARSING_H__
