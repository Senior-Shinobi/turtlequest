#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"
#include "Dragon.h"
//ctor of dragon enemy
Dragon::Dragon(string n,int h,int s,int a, int x, int y,int t) :
 Hero( n, h, s, a,  x,  y,  t)
{
  setIcon('D');
}
