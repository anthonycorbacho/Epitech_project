/*
** longLong.h for longlong in /home/Anthony/Epitech/piscine/cpp/picsine_2/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 12:45:04 2010 anthony1 corbacho
** Last update Thu May 13 12:45:27 2010 anthony1 corbacho
*/

#ifndef __LONGLONG_H__
#define __LONGLONG_H__

class LongLong
{
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

 private :
  long long		_value;
};

#endif /* __LONGLONG_H__ */
