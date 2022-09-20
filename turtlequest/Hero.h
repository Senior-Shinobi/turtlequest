#ifndef HERO_H
#define HERO_H


class Hero
{
  public:
    Hero(string="",int=0,int=0,int=0,int=0,int=0,int=0);
    ~Hero();
    string getName();
    int getHealth();
    int getStrength();
    int getArmor();
    int getX();
    int getY();
    int getTeam();
    bool setXY(int,int);
    void Damage(int);
    bool getStatus();
    int getId();
    char getIcon();
    void setIcon(char);

  private:
    static int nextId;
    int id;
    string name;
    int hp;
    int strength;
    int armor;
    int xcoor;
    int ycoor;
    int team;
    bool status;
    char icon;

};

#endif
