#ifndef		__LAVER_H__
#define		__LAVER_H__

#include <iostream>
#include <string>
#include "Nurse.h"
#include "Intervention.h"

class		Laver : public Intervention
{
 public:
  Laver(Nurse *nurse);
  ~Laver();

  void		execute();
};

#endif		// __LAVER_H__
