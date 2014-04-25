/*
** syntaxErrorException.h for syn in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:44:59 2010 anthony1 corbacho
** Last update Thu May 13 13:45:16 2010 anthony1 corbacho
*/

#ifndef __S_H__
#define __S_H__

#include <exception>

class SyntaxErrorException : public std::exception
{
 public :
  virtual const char* what() const throw();
};

#endif // __S_H__
