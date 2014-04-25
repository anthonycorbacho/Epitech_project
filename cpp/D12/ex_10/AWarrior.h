#ifndef		__AWARRIOR_H__
#define		__AWARRIOR_H__
class			AWarrior
{
 public:
  AWarrior();
  virtual ~AWarrior();

  virtual void		move() = 0;
  virtual void		shoot() = 0;
  virtual void		charge() = 0;

  void			playTurn();
};

#endif		// __AWARRIOR_H__
