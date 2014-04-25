#ifndef		__PATIENT_H__
#define		__PATIENT_H__

#include <iostream>
#include <string>

class		Patient
{
 private:
  std::string	_name;

 public:
  Patient(std::string const &name);
  ~Patient();
  std::string	getName();
};

#endif		// __PATIENT_H__
