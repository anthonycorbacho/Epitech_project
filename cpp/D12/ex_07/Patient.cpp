#include "Patient.h"

Patient::Patient(std::string const &name)
{
  _name = name;
}

Patient::~Patient()
{
}

std::string		Patient::getName()
{
  return (_name);
}
