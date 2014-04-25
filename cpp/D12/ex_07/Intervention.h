#ifndef		__IINTERVENTION_H__
#define		__IINTERVENTION_H__

#include <iostream>
#include <string>
class		Nurse;
class		Intervention
{
 protected:
  Nurse			*_nurse;
 public:
  Intervention()
    {
    };
  
  virtual ~Intervention()
    {
    };
  
  virtual void		execute() = 0;
};
#endif		// __IINTERVENTION_H__
