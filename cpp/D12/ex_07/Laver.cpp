#include "Laver.h"

Laver::Laver(Nurse *nurse)
{
  _nurse = nurse;
}

Laver::~Laver()
{
}

void		Laver::execute()
{
  std::cout
    << "Deshabillez vous"
    << std::endl;
  _nurse->etatSuivant();
}
