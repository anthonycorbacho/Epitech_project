/*
** longLongOverflowException.h for lonh in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:33:35 2010 anthony1 corbacho
** Last update Thu May 13 13:39:19 2010 anthony1 corbacho
*/

#ifndef __LONGLONGOVERFLOWEXCEPTION_H__
#define __LONGLONGOVERFLOWEXCEPTION_H__

#include <iostream>
#include <exception>

class LongLongOverflowException : public std::exception
{
 public :
  virtual const char* what() const throw();
};

#endif /* __LONGLONGOVERFLOWEXCEPTION_H__ */
