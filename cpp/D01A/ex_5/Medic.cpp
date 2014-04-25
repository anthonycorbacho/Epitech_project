//
// Medic.cpp for Medic in /home/corbac_b/work/piscine/cpp/D01A/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 20:39:34 2010 anthony1 corbacho
// Last update Mon May  3 21:43:27 2010 anthony1 corbacho
//

#include	<string.h>

#include	<iostream>
#include	<fstream>

#include	"Medic.h"
#include	"Patient.h"

Medic::Medic()
{
}

Medic::~Medic()
{
}

void		Medic::Diagnostic(Patient *pat)
{
  std::ofstream	fic;
  char		fic_name[512];

  memset(fic_name, 0, 512);
  strcat(fic_name, pat->GetName());
  strcat(fic_name, ".diag");
  fic.open(fic_name, std::fstream::out);
  fic << "Donnez lui du Buronzand" << std::endl;
  fic.close();
}
