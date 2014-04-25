#include "PriseDeSang.h"

PriseDeSang::PriseDeSang(Nurse *nurse)
{
  _nurse = nurse;
}

PriseDeSang::~PriseDeSang()
{
}

void		PriseDeSang::execute()
{
  std::cout
    << "Detendez vous, vous ne sentirez  rien"
    << std::endl;
  _nurse->etatSuivant();
}
