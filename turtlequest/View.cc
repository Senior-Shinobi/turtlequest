#include <iostream>
using namespace std;
#include <string>

#include "View.h"
//gives menu for user in control launch
void View::showMenu(int& choice)
{
  cout << endl << endl;
  cout << "Select an option:"<< endl;
  cout << "  (1) Next turn" << endl;
  cout << "  (2) Easy Mode" << endl;
  cout << "  (3) Hard Mode" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 3) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}
//prints a string
void View::printStr(string str)
{
  cout << str<<endl;
}
//takes user inputed int
void View::readInt(int& n)
{
  cin >> n;
}
//takes user inputed float
void View::readFloat(float& f)
{
  cin >> f;
}
//takes user inputed string
void View::readStr(string& str)
{
  cin >> str;
}
//prints winner name and message
void View::printWin(string str)
{
  cout<<str<<" CLAIMS THE EMERALD!!!"<<endl;
}
