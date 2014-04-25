/*
** Zaz.h for Zaz in /home/Anthony/Epitech/piscine/cpp/12h/ex_03
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 15:17:41 2010 anthony1 corbacho
** Last update Fri May 14 15:18:18 2010 anthony1 corbacho
*/

#ifndef __ZAZ_H__
#define __ZAZ_H__

#include <string>
#include <iostream>

class		Zaz
{
 public:
  static Zaz	*getInstance();
  static void	deleteInstance();
  void		porterUnToast();

 private:
  static	Zaz *_Zaz;
  Zaz();
  ~Zaz();
};

#endif //__ZAZ_H__
