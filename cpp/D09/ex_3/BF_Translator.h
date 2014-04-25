/*
** BF_Translator.h for BF_Translator.h in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May 11 21:35:14 2010 anthony1 corbacho
** Last update Tue May 11 22:57:25 2010 anthony1 corbacho
*/

#ifndef __BF_TRANSLATOR_H__
#define __BF_TRANSLATOR_H__

#include	<iostream>
#include	<string>
#include	<map>

class		BF_Translator
{
 public:
  BF_Translator();
  int     translate(std::string in, std::string out);
 private:
  std::map<char, char *> _Map;
};

#endif /*__BF_TRANSLATOR_H__*/
