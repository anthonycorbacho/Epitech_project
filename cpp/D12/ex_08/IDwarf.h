#ifndef		__IDWARF_H__
#define		__IDWARF_H__

#include <iostream>
#include <string>

class		IDwarf
{
 public:
  IDwarf()
    {
    };

  virtual ~IDwarf()
    {
    };
  
  virtual void raler() const = 0;
};

#endif		// __IDWARF_H__
