//
// longLong.cpp for longlong in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 13:28:25 2010 anthony1 corbacho
// Last update Thu May 13 13:30:21 2010 anthony1 corbacho
//


#include "longLong.h"
#include "longLongOverflowException.h"
#include "longLongUnderflowException.h"
#include "divisionByZeroException.h"


LongLong::LongLong(long long val)
{
  _value = val;
}

LongLong::LongLong(const LongLong& val)
{
  _value = val._value;
}

LongLong::~LongLong()
{
}

const LongLong&		LongLong::operator=(const LongLong& val)
{
  _value = val._value;  
  return (*this);
}
LongLong		LongLong::operator*(const LongLong& val) const
{
  LongLong		L(_value * val._value);

  if ((_value > 0 && val._value > 0) && L._value < 0)
    throw (new LongLongOverflowException());

  if ((_value < 0 && val._value < 0) && L._value < 0)
    throw (new LongLongOverflowException());

  if ((_value < 0 && val._value > 0) && L._value >= 0)
    throw (new LongLongUnderflowException());

  if ((_value > 0 && val._value < 0) && L._value >= 0)
    throw (new LongLongUnderflowException());

 return (L);
}

LongLong		LongLong::operator/(const LongLong& val) const
{
  if (val._value == 0)
    throw (new DivisionByZeroException());

  LongLong		L(_value / val._value);

  return (L);
}

long long		LongLong::getValue() const
{
  return (this->_value);
}

void			LongLong::setValue(long long val)
{
  _value = val;
}

LongLong		LongLong::operator+(const LongLong& val) const
{
  LongLong		L(_value + val._value);

  if ((_value > 0 && val._value > 0) && L._value < 0)
    throw (new LongLongOverflowException());

  if ((_value < 0 && val._value < 0) && L._value >= 0)
    throw (new LongLongUnderflowException());

 return (L);  
}

LongLong		LongLong::operator-(const LongLong& val) const
{
  LongLong		L(_value - val._value);

  if ((_value > 0 && val._value < 0) && L._value < 0)
    throw (new LongLongOverflowException());

  if ((_value < 0 && val._value > 0) && L._value >= 0)
    throw (new LongLongUnderflowException());

 return (L);
}
