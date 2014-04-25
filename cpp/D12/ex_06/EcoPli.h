#ifndef		__ECOPLI_H__
#define		__ECOPLI_H__

#include <iostream>
#include <string>

#include "IPli.h"

class EcoPli : public IPli
{
 public:
  EcoPli();
  ~EcoPli();
  
  void		pli();
};

#endif		// __ECOPLI_H__
