#ifndef CLUEDO_H_
#define CLUEDO_H_

namespace	Cluedo
{
  class		Card
  {
  protected:
    Card();
    ~Card();
    
  public:
    bool	IsPartOfTheCrime() const;
    
  protected:
    bool	_isPartOfTheCrime;
  };
  
  class		Weapon: public Card
  {
  public:
    enum Name
    {
      Corde,
      Matraque,
      Poignard,
      Cle_Anglaise,
      Chandelier,
      Revolver
    };
    static const Name PartOfTheCrime;

  private:
    bool		_emp;
    
  public:
    Weapon(Weapon::Name name, bool bearsFingerprints);
    ~Weapon();
    
    bool	BearsFingerprints() const;
  };
  
  class		Suspect: public Card
  {
  public:
    enum Name
    {
      Mlle_Rose,
      Pr_Violet,
      Col_Moutarde,
      Dr_Olive,
      Mme_Leblanc,
      Mme_Pervenche
    };
    static const Name PartOfTheCrime;
    
  private:
    bool	_lying;

  public:
    Suspect(Suspect::Name name, bool isLying);
    ~Suspect();
    
    bool	IsLying() const;
  };
  
  class		Room : public Card
  {
  public:
    enum Name
    {
      Cuisine,
      Grand_Salon,
      Veranda,
      Petit_Salon,
      Salle_a_Manger,
      Billard,
      Bibliotheque,
      Bureau,
      Hall
    };
    static const Name PartOfTheCrime;
    
  private:
    bool	_pass;
    
  public:
    Room(Room::Name name, bool hasSecretPassage);
    ~Room();
    
    bool	HasSecretPassage() const;
  };
  
  class		Game
  {
  public:
    static bool CaseSolved(Weapon* w[], Suspect* s[], Room* r[]);
  };
}

#endif // CLUEDO_H_
