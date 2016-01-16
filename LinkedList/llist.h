#ifndef LLIST_H
#define LLIST_H

class Node;//PRE DIFINE THE NODE STRUCT FOR THE TYPDEF POINTER

typedef int el_t;
typedef Node* NodePtr;//POINTER OF STRUCT NODE

struct Node{//EACH NODE IN THE LIST
  el_t Elem;//CAN BE ANY DATATYPE ELEMENT
  NodePtr Next;//SINGLY LINKED LIST, NNO PREVIOUS GIVEN
};

class llist{
 protected:
  NodePtr Front;
  NodePtr Rear;
  int Count;

 public:
  class Underflow{};//IF THE LINKED LIST IS EMPTY WHEN TRYING TO DELETE
  class OutOfRange{};//IF TRYING TO ACCESS AN ELEMENT THAT IS OUT OF RANGE

  llist();
  ~llist();

  bool isEmpty();

  void displayAll();

  void addFront(el_t NewElem);

  void deleteFront(el_t& OldElem);

  void addRear(el_t NewElem);

  void deleteRear(el_t& OldElem);

  void addBeforeIth(int I, el_t NewElem);//ADD ELEMENT BEFORE THE ITH ELEMENT

  void deleteIth(int I, el_t& OldElem);//DELETE BEFORE THE ITH ELEMENT
};

#endif