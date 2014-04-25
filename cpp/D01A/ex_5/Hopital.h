/*
** Hopital.h for Hopital in /home/corbac_b/work/piscine/cpp/D01A/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 19:10:07 2010 anthony1 corbacho
** Last update Mon May  3 21:35:28 2010 anthony1 corbacho
*/

#ifndef		__HOPITAL_H__
#define		__HOPITAL_H__

#include	"Medic.h"
#include	"Nurse.h"
#include	"Patient.h"

class		Hopital
{
 public:
  Hopital();
  ~Hopital();
  void		SetStaff(Medic *_medic, Nurse *_nurse);
  void		Work();
  bool		CanAdmit();
  bool		AdmitPatient(Patient *_patient);
 
 private:
  bool		_isBed;
  Medic		*_medic;
  Nurse		*_nurse;
  Patient	*_patient;
};

#endif		//__HOPITAL_H__
