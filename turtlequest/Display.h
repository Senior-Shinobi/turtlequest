#ifndef DISPLAY_H
#define DISPLAY_H


#include "Hero.h"
template <class T>
class Display
{
  public:
    Display();
    ~Display();
    void updateDisplay();
    bool updateIcons(Hero*);
    void updateArray();
    T* operator[](int);
    void CombatWinner(Hero*);


  private:
    T** arr;


};
//display ctor which displays the empty map
template <class T>
Display<T>::Display()
{
  arr = new T*[5];
  for(int i =0; i<5; i++){
    arr[i] = new T[25];
  }
  cout<<"|-------------------------|"<<endl;
  for (int i = 0;i<5;i++){
    cout<<"|";
    for (int j = 0;j<25;j++){
      cout<<" ";
    }
    if (i>0&&i<4){
      if (i==2){
        cout<<"= *"<<endl;
      } else{
        cout<<"="<<endl;
      }
    } else {
      cout<<"|"<<endl;
    }
  }
  cout<<"|-------------------------|"<<endl;

}
//display dtor frees memory
template <class T>
Display<T>::~Display(){
  for (int i = 0;i<5;i++){
    delete[] arr[i];
  }
  delete[] arr;
}

//overloaded [] operator for array
template <class T>
T* Display<T>::operator[](int a){
  return arr[a];
}

//prints display with elements in arrays
template <class T>
void Display<T>::updateDisplay()
{
  cout<<"|-------------------------|"<<endl;
  for (int i = 0;i<5;i++){
    cout<<"|";
    for (int j = 0;j<25;j++){
      cout<<arr[i][j];
    }
    if (i>0&&i<4){
      if (i==2){
        cout<<"= *"<<endl;
      } else{
        cout<<"="<<endl;
      }
    } else {
      cout<<"|"<<endl;
    }
  }
  cout<<"|-------------------------|"<<endl;
}

//updates the chars wherethe hero is in array
template <class T>
bool Display<T>::updateIcons(Hero* h){
  if (arr[h->getY()][h->getX()]==' '){
    arr[h->getY()][h->getX()]=h->getIcon();
    return true;
  } else if (arr[h->getY()][h->getX()]=='+'){
    return true;
  } else {
    return false;
  }
}

//displays winner of combats char on spot in 2d array
template <class T>
void Display<T>::CombatWinner(Hero* h){
  arr[h->getY()][h->getX()]=h->getIcon();
}

//clears array so it can be filled again when needed
template <class T>
void Display<T>::updateArray()
{
  for (int i = 0;i<5;i++){

    for (int j = 0;j<25;j++){

      arr[i][j] = ' ';

    }

  }
}
#endif
