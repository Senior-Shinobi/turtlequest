#include <iostream>
using namespace std;

#include "List.h"
//initializes list and sets head to null
List::List() : head(NULL) { }
//deallocates data in list
List::~List()
{

  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}
//adds a hero to the list in alphabetical order
List& List::operator+=(Hero* h)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = h;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;
  size++;
  return *this;
}
//deletes hero in list
List& List::operator-=(const int id)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// we get here if we didn't find the id or if we did find the id


  if (prevNode == NULL){
    head = currNode->next;

    }
  else{
    prevNode->next = currNode->next;
    }

  delete currNode->data;
  delete currNode;
  size--;
  return *this;


}
//finds a hero in the list

Hero* List::find(int id)
{
  Node* currNode;
  currNode = head;
  for (int i =0;i<id;i++) {
    currNode = currNode->next;
  }
  return currNode->data;

}

int List::getSize(){
  return size;
}
