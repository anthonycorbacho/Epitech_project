/*
** R2D2.h for r2d2 in /home/corbac_b/work/piscine/cpp/D04M/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 11:40:02 2010 anthony1 corbacho
** Last update Thu May  6 14:48:58 2010 anthony1 corbacho
*/

#ifndef		__R_H__
#define		__R_H__

#include	<iostream>
#include	"droid.h"

class		r2d2 : virtual public Droid
{
 public:
  r2d2();
  ~r2d2();
  void    Identification() const;
  void		Glory() const;
};

#endif		//__R_H__
