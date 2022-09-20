#ifndef CONTROL_H
#define CONTROL_H


#include "Hero.h"
#include "Hare.h"
#include "Tortoise.h"
#include "List.h"
#include "Display.h"
#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"
#include "Dragon.h"
#include "View.h"

int random(int);

class Control
{
  public:
    Control();
    ~Control();
    void launch();
    void initPlayers();
    int nextTurn(int,int,int);
    void genDorc();
    void genBorc();
    void genPorc();
    void Combat(Hero*,Hero*);
    void updateD();
    void playerMoves(Hero*);
    void enemyMoves(Hero*);
    int dragonMoves(Hero*,int);
    bool winCondition();


  private:
    Display<char> display;
    List list;
    View view;

};

#endif
