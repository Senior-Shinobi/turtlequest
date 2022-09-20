#ifndef LIST_H
#define LIST_H

#include "Hero.h"
class List
{
  class Node
  {
    public:
      Hero* data;
      Node* next;

  };

  public:
    List();
    ~List();
    List& operator+=(Hero*);
    List& operator-=(const int);
    Hero* find(int);
    int getSize();
    

  private:
    int size = 0;
    Node* head;

};
#endif
