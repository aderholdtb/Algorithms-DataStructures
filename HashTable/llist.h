#ifndef LLIST_H
#define LLIST_H

struct Node{
  std::string name;
  Node* next;
};

class Llist{
 private:
  Node *_Front;//FRONT OF LIST
  Node *_Rear;//BACK OF LIST

 public:
  Llist();
  ~Llist();

  Node* getAdjacent();//ADJACENCY LIST
  void addFront(std::string name);//ADD TO FRONT OF LIST
  std::string deleteIth(int index);//DELETE THE ITH ELEMENT IN THE LIST
  void addRear(std::string name);//ADD TO REAR
  std::string deleteFront();//DELETE THE FRONT ELEMENT
  std::string deleteRear();//DELETE THE BACK ELEMENT
  void displayAll();
  Node* getFront();//RETURN THE FRONT NODE POINTER
  Node* getRear();//RETURN THE REAR NODE POINTER
  bool isEmpty();//TRUE IF EMPTY
  void removeAll();
  int getSize();//GET SIZE STARTING AT 1 FOR FIRST ELEMENT
};

#endif
