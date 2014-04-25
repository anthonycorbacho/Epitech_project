/*
** divisionByZeroException.h for div in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:25:27 2010 anthony1 corbacho
** Last update Thu May 13 13:26:17 2010 anthony1 corbacho
*/

#ifndef __D_H__
#define __D_H__

#include <iostream>
#include <string>
#include <exception>

class DivisionByZeroException : public std::exception
{

 public :
  virtual const char* what() const throw();

};

#endif // __D_H__
