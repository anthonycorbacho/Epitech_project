/*
** longLong.h for longlon in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 13:31:04 2010 anthony1 corbacho
** Last update Thu May 13 13:31:57 2010 anthony1 corbacho
*/


#ifndef __LL_H__
#define __LL_H__

class LongLong
{
 private :
  long long		_value;

 public :
  LongLong(long long l = 0);
  LongLong(const LongLong&);
  ~LongLong();
  const LongLong&	operator=(const LongLong&);

  LongLong		operator+(const LongLong&) const;
  LongLong		operator-(const LongLong&) const;
  LongLong		operator*(const LongLong&) const;
  LongLong		operator/(const LongLong&) const;
  
  long long		getValue() const;
  void			setValue(long long val);

};

#endif // __LL_H__
