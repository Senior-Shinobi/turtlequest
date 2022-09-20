#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"
#include "Hare.h"
#include "Tortoise.h"
#include "List.h"
#include "Display.h"
#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"
#include "Dragon.h"


int random(int);
//control constructor
Control::Control(){}

Control::~Control(){}
//function that acts as a main function that uses the view object to give user choices
void Control::launch()
{
  int    choice, rgen;
  int  dragdir = 1;
  initPlayers();
  display.updateArray();
  updateD();
  display.updateDisplay();


  while (dragdir!=0) {
    view.showMenu(choice);

    if (choice == 0)
      break;

    if (choice == 1) {
      dragdir = nextTurn(1,0,dragdir);

    }
    else if (choice == 2) {
      dragdir = nextTurn(2,0,dragdir);

    }
    else if (choice == 3) {
      dragdir = nextTurn(3,0,dragdir);
    }
  }


}
//iterates through the turns allowing the user to set the difficulty of each turn
int Control::nextTurn(int difficulty,int rgen,int dragdir){
  //if both heros are dead ends the game
  if (list.find(0)->getStatus()==false&&list.find(1)->getStatus()==false){
    view.printStr("Both Heros have perished. please try again.");
    return 0;
  }
  //if a hero is at the end a winner message is printed
  if (winCondition()){
    return 0;
  }
  //moves all enemies in list other than dragon
  if (list.getSize()>3){
    for (int i = 3;i<list.getSize();i++){
       list.find(i);
       enemyMoves(list.find(i));
      }
    }

    //spawns enemies varying with difficulty
    if (difficulty!=3){
      int spawnrate;
      if (difficulty==1){
          spawnrate = 1;
      } else {
          spawnrate =4;
      }
      if (random(5)>=spawnrate){

        rgen = random(3);
        if (rgen==0){
          genBorc();
        }else if (rgen==1){
          genDorc();
        }else{
          genPorc();
        }

      }
    } else {
      for (int j = 0;j<2;j++){
        rgen = random(3);
        if (rgen==0){
          genBorc();
        }else if (rgen==1){
          genDorc();
        }else{
          genPorc();
        }
      }
    }
//moves players if they are alive
  if (list.find(0)->getStatus()){
    playerMoves(list.find(0));
  }
  if (list.find(1)->getStatus()){
    playerMoves(list.find(1));
  }
//moves dragon
  dragdir = dragonMoves(list.find(2),dragdir);
//updates the display to show the current turn
  display.updateArray();
  updateD();
  display.updateDisplay();

  return dragdir;
}
//function to tell if the heros have won
bool Control::winCondition()
{
  if (list.find(0)->getStatus()==true){
    if (list.find(0)->getX()==24){
      if (list.find(0)->getY()!=0&&list.find(0)->getY()!=4){
        view.printWin(list.find(0)->getName());
        return true;
      }
    }
  }
  if (list.find(1)->getStatus()==true){
    if (list.find(1)->getX()==24){
      if (list.find(1)->getY()!=0&&list.find(1)->getY()!=4){
        view.printWin(list.find(1)->getName());
        return true;
      }
    }
  }
  return false;
}
//moves players to the right
void Control::playerMoves(Hero* h){
  int a;

  if (h->getX()<24){
    if (h->getY()==0){

      h->setXY(h->getX()+1,h->getY()+random(2));
    } else if (h->getY()==4){

      h->setXY(h->getX()+1,h->getY()-random(2));
    } else{

      a = random(3);
      if (a==0){
        h->setXY(h->getX()+1,h->getY()+1);
      } else if(a==1){
        h->setXY(h->getX()+1,h->getY());
      } else {
        h->setXY(h->getX()+1,h->getY()-1);
      }

    }
  } else {
    if (h->getY()==0){
      h->setXY(h->getX(),h->getY()+1);
    } else if (h->getY()==4){
      h->setXY(h->getX(),h->getY()-1);
    }
  }
}
//moves enemies to the left
void Control::enemyMoves(Hero* h){
  int a;

  if (h->getX()>0){
    if (h->getY()==0){

      h->setXY(h->getX()-1,h->getY()+random(2));
    } else if (h->getY()==4){

      h->setXY(h->getX()-1,h->getY()-random(2));
    } else{

      a = random(3);
      if (a==0){
        h->setXY(h->getX()-1,h->getY()+1);
      } else if(a==1){
        h->setXY(h->getX()-1,h->getY());
      } else {
        h->setXY(h->getX()-1,h->getY()-1);
      }

    }
  } else {
    list-=h->getId();
  }
}
//moves dragon up and down
int Control::dragonMoves(Hero* h, int direction){

  if (direction==1){
    h->setXY(h->getX(),h->getY()+1);
    if (h->getY()==4){
      return 2;
    }
  }else {
    h->setXY(h->getX(),h->getY()-1);
    if (h->getY()==0){
      return 1;
    }
  }
  return direction;
}
//creates heros and dragon and adds them to the list
void Control::initPlayers()
{

  Hare* h = new Hare("Harold",15,5,1,0,random(5),1);

  Tortoise* t = new Tortoise("Timmy",15,3,3,0,random(5),1);
  while  (t->getY() == h->getY()){
    t->TsetXY(0,random(5));
  }
  Dragon* d = new Dragon("Dragon",20,20,20,24,2,2);

  list+=h;
  list+=t;
  list+=d;

}
//creates a dorc and adds it to the list
void Control::genDorc()
{

  int s = random(8);
  while (s<6){

    s = random(8);
  }

  Dorc* d = new Dorc("Dorc",5,s,0,23,random(5),2);
  list+=d;
}
//creates a borc and adds it to the list
void Control::genBorc()
{

  int s = random(11);
  while (s<8){

    s = random(11);
  }

  Borc* b = new Borc("Borc",5,s,0,23,random(5),2);
  list+=b;
}
//creates a porc and adds it to the list
void Control::genPorc()
{

  int s = random(5);
  while (s<4){

    s = random(5);
  }

  Porc* p = new Porc("Porc",5,s,0,23,random(5),2);
  list+=p;
}
//allows 2 heros to fight eachother and if a player hero dies they are marked with +
void Control::Combat(Hero* a, Hero* b){

  while (a->getStatus()&&b->getStatus()){
    a->Damage(b->getStrength()-a->getArmor());
    b->Damage(a->getStrength()-b->getArmor());
  }
  if (a->getStatus()!=true){
    if (a->getTeam()==1){
      a->setIcon('+');
    } else {
      list-=a->getId();
    }
    display.CombatWinner(b);
  }
  if (b->getStatus()!=true){
    if (b->getTeam()==1){
      b->setIcon('+');
    } else {
      list-=b->getId();
    }
    display.CombatWinner(a);
  }

}
//updates display on the moves that were made each turn
void Control::updateD(){
  Hero* a;
  Hero* b;
  for (int i = 0;i<list.getSize();i++){
    a=list.find(i);
    if (a!=NULL){
      if (display.updateIcons(a)==false){

        for (int j = 0;j<list.getSize();j++){
          b = list.find(j);

          if ((b->getX() == a->getX())&&(b->getY() == a->getY())){
            if (b->getTeam()!=a->getTeam()){
              Combat(a,b);

            }
          }

        }


      }
    }
  }

}
