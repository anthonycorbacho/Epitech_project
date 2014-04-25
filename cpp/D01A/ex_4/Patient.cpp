//
// Patient.cpp for Patient in /home/corbac_b/work/piscine/cpp/D01A/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 21:19:44 2010 anthony1 corbacho
// Last update Mon May  3 21:48:27 2010 anthony1 corbacho
//

#include	"Patient.h"
#include	<string.h>
#include        <iostream>
#include        <fstream>

Patient::Patient(char *name)
{
  _Name = name;
  _Go = 0;
}

Patient::~Patient()
{
}

bool		Patient::IsReadyToGo()
{
  return (this->_Go);
}

void		Patient::Give(char *medoc)
{
  if (strcmp(medoc, "Buronzand") == 0)
    {
      std::cout << "Et la fatigue a fait son temps !" << std::endl;
      this->_Go = 1;
    }
}

const	char*	Patient::GetName()
{
  return(this->_Name);
}
