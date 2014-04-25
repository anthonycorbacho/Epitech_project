#ifndef _VADORKOALA_H_
#define _VADORKOALA_H_

#include <iostream>
#include "darkoala.h"

class	VadorKoala : public Darkoala
{	
 public:
  VadorKoala();
  ~VadorKoala();
  virtual	void	UseForce() const;
  virtual	void	Breath() const;
  virtual	void    TakeLightSaber() const;
};

#endif /*_VADORKOALA_H_*/
