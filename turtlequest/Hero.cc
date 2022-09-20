#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"
//id made for keeping track
int Hero::nextId = 0;
//Hero ctor is the parent of all enemies and heros
Hero::Hero(string n,int h,int s,int a, int x, int y,int t)
{
  id = nextId;
  ++nextId;

  name = n;
  hp = h;
  strength = s;
  armor = a;
  xcoor = x;
  ycoor = y;
  team = t;
  status = true;
}

Hero::~Hero(){

}
//rgetter for name
string Hero::getName(){
  return name;
}
//getter for health
int Hero::getHealth(){
  return hp;
}
//getter for strength
int Hero::getStrength(){
  return strength;
}
//getter for armor
int Hero::getArmor(){
  return armor;
}
//getter for x coordinate
int Hero::getX(){
  return xcoor;
}
//getter for y coordinate
int Hero::getY(){
  return ycoor;
}
//getter for status whetherhero is alive or not
bool Hero::getStatus(){
  return status;
}
//changes hp for damage dealt and changes status to false if hero dies
void Hero::Damage(int d)
{
  hp-=d;
  if (hp<=0){
    status = false;
  }
}
//sets x and y coordinates
bool Hero::setXY(int x, int y)
{

  xcoor = x;
  ycoor = y;
  return true;
}
//getter for team
int Hero::getTeam(){
  return team;
}
//getter for id
int Hero::getId(){
  return id;
}
//getter for heros char
char Hero::getIcon(){
  return icon;
}
//sets heros char
void Hero::setIcon(char a){
  icon = a;
}
