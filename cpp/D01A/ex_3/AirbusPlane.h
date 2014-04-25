/*
** AirbusPlane.h for airbus in /home/corbac_b/work/piscine/cpp/D01A/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 14:43:32 2010 anthony1 corbacho
** Last update Mon May  3 18:36:54 2010 anthony1 corbacho
*/

#ifndef		__AIRBUS_PLANE_H__
#define		__AIRBUS_PLANE_H__

#include	"AirbusPieces.h"

namespace	Airbus
{
  class		Plane
  {
  public:
    Plane(char const * constructor_name, int Id, Airbus::Pieces *piece = 0);
    ~Plane();
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
}
#endif		//__AIRBUS_PLANE_H__
