//
// Event.cpp for Event in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May 11 15:29:42 2010 anthony1 corbacho
// Last update Tue May 11 18:41:42 2010 anthony1 corbacho
//

#include <iostream>
#include <string>
#include "Event.h"

Event::Event(void)
{
  _Time = 0;
  _Event = "";
}

Event::Event(unsigned int t, const std::string& str)
{
  _Time = t;
  _Event = str;
}

Event::~Event(void)
{
}

Event::Event(const Event& event)
{
  _Event = event._Event;
  _Time = event._Time;
}

Event&		Event::operator=(const Event& event)
{
  if (this != &event)
    {
      this->_Time = event._Time;
      this->_Event = event._Event;
    }
  return (*this);
}

unsigned int	Event::getTime(void) const
{
  return this->_Time;
}

const std::string&	Event::getEvent(void) const
{
  return (this->_Event);
}

void		Event::setTime(unsigned int time)
{
  this->_Time = time;
}

void		Event::setEvent(const std::string& str)
{
  this->_Event = str;
}

bool		Event::operator==(const Event &e){
  return (e._Time == this->_Time);
}

bool		Event::operator<(const Event &e){
  return (e._Time < this->_Time);
}

std::ostream         &operator<<(std::ostream &out, Event &e)
{
  out << e._Time << ": " << e._Event;
  return (out);
}
