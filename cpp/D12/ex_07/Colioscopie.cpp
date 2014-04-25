#include "Colioscopie.h"

Colioscopie::Colioscopie(Nurse *nurse)
{
  _nurse = nurse;
}

Colioscopie::~Colioscopie()
{
}

void		Colioscopie::execute()
{
  std::cout
    << "Tournez vous s'il vous plait"
    << std::endl;
  _nurse->etatSuivant();
}
