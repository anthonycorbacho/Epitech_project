/*
** Patient.h for Patient in /home/corbac_b/work/piscine/cpp/D01A/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 21:12:59 2010 anthony1 corbacho
** Last update Mon May  3 21:47:47 2010 anthony1 corbacho
*/

#ifndef		__PATIENT_H__
#define		__PATIENT_H__

class		Patient
{
 public:
  Patient(char *name = "Pat");
  ~Patient();
  bool	IsReadyToGo();
  void	Give(char *medoc);
  const char	*GetName();

 private:
  char	const	*_Name;
  bool		_Go;
};

#endif		//__PATIENT_H__
