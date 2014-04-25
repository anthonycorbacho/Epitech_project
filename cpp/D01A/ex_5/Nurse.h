/*
** Nurse.h for Nurse in /home/corbac_b/work/piscine/cpp/D01A/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 20:58:46 2010 anthony1 corbacho
** Last update Mon May  3 21:33:07 2010 anthony1 corbacho
*/

#ifndef		__NURSE_H__
#define		__NURSE_H__

#include	"Patient.h"

class		Nurse
{
 public:
  Nurse();
  ~Nurse();
  void		TakeCare(Patient *pat);
  bool		HasBigBoobs();

 private:
  bool		_AsBigBoobs;
};
#endif		//__NURSE_H__
