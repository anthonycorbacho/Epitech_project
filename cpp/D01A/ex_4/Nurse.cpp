//
// Nurse.cpp for nurse in /home/corbac_b/work/piscine/cpp/D01A/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 21:04:06 2010 anthony1 corbacho
// Last update Mon May  3 21:15:32 2010 anthony1 corbacho
//

#include        <string.h>

#include        <iostream>
#include        <fstream>

#include	"Nurse.h"
#include	"Patient.h"

Nurse::Nurse()
{
  _AsBigBoobs = 1;
}

Nurse::~Nurse()
{
}

bool		Nurse::HasBigBoobs()
{
  return (_AsBigBoobs);
}

void		Nurse::TakeCare(Patient *pat)
{
  char		buff[512];
  char		medoc[256];
  std::ifstream	fic;

  memset(buff, 0, 512);
  memset(medoc, 0, 256);
  strcpy(buff, (char *)pat->GetName());
  strcat(buff, ".diag");
  fic.open(buff);
  if (fic.good())
    {
      while (!fic.eof())
	fic >> medoc;
    }
  fic.close();
  pat->Give(medoc);
}
