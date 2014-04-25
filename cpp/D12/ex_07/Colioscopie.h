#ifndef		__COLIOSCOPIE_H__
#define		__COLIOSCOPIE_H__

#include <iostream>
#include <string>

#include "Nurse.h"
#include "Intervention.h"

class		Colioscopie : public Intervention
{
 public:
  Colioscopie(Nurse *nurse);
  ~Colioscopie();

  void		execute();
};

#endif		// __COLIOSCOPIE_H__
