#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readFloat(float&);
    void readStr(string&);
    void printWin(string);
};

#endif
