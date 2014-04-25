#ifndef		__PRISEDESANG_H__
#define		__PRISEDESANG_H__

#include <iostream>
#include <string>
#include "Nurse.h"
#include "Intervention.h"

class		PriseDeSang : public Intervention
{
 public:

  PriseDeSang(Nurse *nurse);
  ~PriseDeSang();
  void		execute();
};

#endif		// __PRISEDESANG_H__
