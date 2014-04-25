/*
** AbsSujet.h for DP in /home/Anthony/Epitech/piscine/cpp/12h/ex_04
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 13:49:40 2010 anthony1 corbacho
** Last update Fri May 14 14:04:03 2010 anthony1 corbacho
*/

#ifndef __H_ABSSUJET__
#define __H_ABSSUJET__

#include <string>

class AbsSujet
{
 protected:
  std::string	_name;
  
 public:
  std::string getName()
    { 
      return (this->_name); 
    }

  virtual AbsSujet *copy() = 0;

  virtual ~AbsSujet() { }
};

#endif
