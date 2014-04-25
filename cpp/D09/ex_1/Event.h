/*
** Event.h for event in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May 11 15:21:03 2010 anthony1 corbacho
** Last update Tue May 11 18:39:55 2010 anthony1 corbacho
*/

#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <string>

class		Event
{
 public:
  Event(void);
  Event(unsigned int, const std::string&);
  ~Event(void);
  Event(const Event&);
  Event&              operator=(const Event&);
  bool		      operator==(const Event &);
  bool		      operator<(const Event &);
  friend std::ostream& operator<<(std::ostream &, Event&);
  unsigned int        getTime(void) const;
  const std::string&  getEvent(void) const;
  void                setTime(unsigned int);
  void                setEvent(const std::string&);

 private:
  unsigned int		_Time;
  std::string		_Event;
};

#endif /*__EVENT_H__*/
