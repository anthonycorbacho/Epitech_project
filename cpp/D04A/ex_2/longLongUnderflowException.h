/*
** longLongUnderflowException.h for long in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:35:30 2010 anthony1 corbacho
** Last update Thu May 13 13:35:51 2010 anthony1 corbacho
*/


#ifndef __LONGL_H__
#define __LONGL_H__

#include <exception>

class LongLongUnderflowException : public std::exception
{
 public :
  virtual const char* what() const throw();
};

#endif //__LONGL_H__
