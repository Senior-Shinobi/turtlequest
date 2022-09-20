#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"
#include "Porc.h"
//porc enemy hero ctor
Porc::Porc(string n,int h,int s,int a, int x, int y,int t) :
 Hero( n, h, s, a,  x,  y,  t)
{
  setIcon('p');
}
