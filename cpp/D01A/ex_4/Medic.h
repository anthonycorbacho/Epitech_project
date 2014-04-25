/*
** Medic.h for Medic in /home/corbac_b/work/piscine/cpp/D01A/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 20:35:57 2010 anthony1 corbacho
** Last update Mon May  3 21:35:05 2010 anthony1 corbacho
*/

#ifndef		__MEDIC_H__
#define		__MEDIC_H__

#include	"Patient.h"

class		Medic
{
 public:
  Medic();
  ~Medic();
  void	Diagnostic(Patient *pat);
};

#endif		//__MEDIC_H__
