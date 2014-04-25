/*
** AirbusPlane.h for airbus in /home/corbac_b/work/piscine/cpp/D01A/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 14:43:32 2010 anthony1 corbacho
** Last update Mon May  3 15:43:51 2010 anthony1 corbacho
*/

#ifndef		__AIRBUS_PLANE_H__
#define		__AIRBUS_PLANE_H__

class		Plane
{
 public:
		Plane();
		~Plane();
  void		Create(char const *constructor_name, int Id);
  void		Fly();
  void		Land();
  bool		IsCreated();
  bool		IsFlying();
  int		GetId();
  const	char	*GetConstructorName();

 private:
  int		_Id;
  char		*_ConstructorName;
  bool		_Flying;
  bool		_isCreated;
};		

#endif		//__AIRBUS_PLANE_H__
