#ifndef CLUEDO_H_
#define CLUEDO_H_

namespace	Cluedo
{
  class		Card
  {
  public:
    enum Type
    {
      WEAPON,
      SUSPECT,
      ROOM
    };

  protected:
    Card(Card::Type cardType);
    ~Card();
    
  public:
    bool	IsPartOfTheCrime() const;
    Type	CardType() const;

  protected:
    bool	_isPartOfTheCrime;

  private:
    Type	_cardType;

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
    static bool CaseSolved(Card* c[]);
  };
}

#endif // CLUEDO_H_
