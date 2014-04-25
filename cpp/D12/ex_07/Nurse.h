#ifndef		__NURSE_H__
#define		__NURSE_H__

#include <iostream>
#include <string>
#include <stack>

#include "Patient.h"
#include "Laver.h"
#include "Colioscopie.h"
#include "PriseDeSang.h"

class		Nurse
{
 private:
  std::stack<Intervention *>	_pile;
  Patient			*_patient;
  Intervention			*_curInterv;

 public:
  Nurse(Patient *patient);
  ~Nurse();

  void				prendreProgramme(std::stack<Intervention*>);
  bool				faireCeQuonMeDemande();
  bool				etatSuivant();
};

#endif		// __NURSE_H__
