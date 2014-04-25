/*
** c3po.h for c3po in /home/corbac_b/work/piscine/cpp/D04M/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 15:19:03 2010 anthony1 corbacho
** Last update Thu May  6 15:52:58 2010 anthony1 corbacho
*/

#ifndef		__C3PO_H__
#define		__C3PO_H__

#include	<iostream>
#include	"droid.h"

class		C3PO : virtual public Droid
{
 public:
  C3PO();
  ~C3PO()
  {
    std::cout << "It's the end of my short c3po's life." << std::endl;
  }
  void	Start() const;
  void	Stop() const;

  void	Speak() const;
};

#endif		//__C3PO_H__
