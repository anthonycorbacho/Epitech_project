/*
** M$.h for m4 in /home/Anthony/Epitech/piscine/cpp/24h/ex_06
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 02:08:22 2010 anthony1 corbacho
** Last update Fri May  7 13:02:18 2010 anthony1 corbacho
*/


#ifndef __M4_H__
#define __M4_H__

class		M4
{
  class		LaserPointer
  {
  public:
    LaserPointer();
    void		Activate();
    void		Deactivate();
    bool		IsOn() const;
    
  private:
    bool		_isActivate;
  };
  
  class		Scope
  {
  public:
    Scope();
    void		Activate();
    void		Deactivate();
    bool		IsActive() const;
    
  private:
    bool		_isActivate;
  };
  
  class		Magazine
  {
  public:
    Magazine();
    Magazine(int Capacity);
    void		RemoveOneBullet();
    int		GetAmmo() const;
    int		GetCapacity() const;
    void		Reload();
  private:
    int		_cap;
    int		_ammo;
  };
  
  class		LCDScreen
  {
  public:
    LCDScreen(const Magazine& M, const Scope& S, const LaserPointer& lp, const M4& m4); 
    void ShowCurrentState();
  private:
    const Magazine&	m;
    const Scope&	s;
    const LaserPointer& l;
    const M4&		w;
  };
  
 public:
  M4(int cap);
  void		Take();
  void		Drop();
  bool		IsInHand() const;
  void		SetFireRate(int nbBullet);
  int		GetFireRate() const;
  void		Reload();
  void		Fire(); 
  Scope		_Scope;
 private:
  Magazine	_Mag;
 public:
  LaserPointer	_Lp;
  LCDScreen	_Lcd;
 private:
  bool		_isHand;
  int		_setFire;
};

#endif //!__M4_H__
