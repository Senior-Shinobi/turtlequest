#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"
#include "Tortoise.h"
//tortoise hero player ctor
Tortoise::Tortoise(string n,int h,int s,int a, int x, int y,int t) :
 Hero( n, h, s, a,  x,  y,  t)
{

  setIcon('T');
}
//sets the tortoise in a different spawn than the hare
void Tortoise::TsetXY(int x,int y){
  setXY(x,y);
}
