#include "Nurse.h"

Nurse::Nurse(Patient *patient)
{
  _patient = patient;
  _curInterv = NULL;
}

Nurse::~Nurse()
{
}

bool		Nurse::etatSuivant()
{
  if (!(_pile.empty()))
    {
      _curInterv = _pile.top();
      _pile.pop();
      return (true);
    }
  _curInterv = NULL;
  return (false);
}

void		Nurse::prendreProgramme(std::stack<Intervention*> pile)
{
  _pile = pile;
  etatSuivant();
}

bool		Nurse::faireCeQuonMeDemande()
{
  if (_curInterv)
    {
      _curInterv->execute();
      return (true);
    }
  return (false);
}

