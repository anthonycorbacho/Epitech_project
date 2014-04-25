//
// Hopital.cpp for Hopital in /home/corbac_b/work/piscine/cpp/D01A/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 20:15:27 2010 anthony1 corbacho
// Last update Mon May  3 21:53:56 2010 anthony1 corbacho
//

#include	"Hopital.h"
#include	"Nurse.h"
#include	"Patient.h"

Hopital::Hopital()
{
  _isBed = 0;
  _medic = 0;
  _nurse = 0;
  _patient = 0;
}

Hopital::~Hopital()
{
}

void		Hopital::SetStaff(Medic *med, Nurse *nur)
{
  this->_medic = med;
  this->_nurse = nur;
}

bool		Hopital::CanAdmit()
{
  if (this->_isBed == 0 && this->_medic != 0 && this->_nurse != 0)
    return (1);
  else
    return (0);
}

bool		Hopital::AdmitPatient(Patient *pat)
{
  if (this->CanAdmit() == 1)
    {
      this->_isBed = 1;
      this->_patient = pat;
      return (1);
    }
  else
    return (0);
}

void		Hopital::Work()
{
  this->_medic->Diagnostic(this->_patient);
  this->_nurse->TakeCare(this->_patient);
  if (this->_patient->IsReadyToGo() == 1)
    {
      this->_isBed = 0;
      this->_patient = 0;
    }
}
