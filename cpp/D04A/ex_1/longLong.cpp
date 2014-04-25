//
// longLong.cpp for longlong cpp in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 12:45:50 2010 anthony1 corbacho
// Last update Thu May 13 12:51:05 2010 anthony1 corbacho
//

#include "longLong.h"

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
  LongLong		R(_value * val._value);

  if ((_value > 0 && val._value > 0) && R._value < 0)
    throw "Long Long Overflow";
  if ((_value < 0 && val._value < 0) && R._value < 0)
    throw "Long Long Overflow";
  if ((_value < 0 && val._value > 0) && R._value >= 0)
    throw "Long Long Underflow";
  if ((_value > 0 && val._value < 0) && R._value >= 0)
    throw "Long Long Underflow";
 return (R);
}

LongLong		LongLong::operator/(const LongLong& val) const
{
  if (val._value == 0)
    throw "Dividing by 0";

  LongLong		R(_value / val._value);

  /*
  **
  **/

  return (R);
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
  LongLong		R(_value + val._value);
  
  if ((_value > 0 && val._value > 0) && R._value < 0)
    throw "Long Long Overflow";
  if ((_value < 0 && val._value < 0) && R._value >= 0)
    throw "Long Long Underflow";
 return (R);  
}

LongLong		LongLong::operator-(const LongLong& val) const
{
  LongLong		R(_value - val._value);
  if ((_value > 0 && val._value < 0) && R._value < 0)
    throw "Long Long Overflow";
  if ((_value < 0 && val._value > 0) && R._value >= 0)
    throw "Long Long Underflow";
 return (R);
}
