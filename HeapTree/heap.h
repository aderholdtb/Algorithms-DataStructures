#ifndef HEAP_H
#define HEAP_H

const int MAX_SIZE = 20;

struct Node{
  private:
  int priority;//NODE PRORITY

  public:
  Node(int);
  Node();
  ~Node();

  void setPriority(int);
  int getPriority();
};

class HeapTree{
 private:
  int size;//SIZE OF TREE
  Node heap[MAX_SIZE];//ARRAY AS THE HEAP TREE

 public:
  HeapTree();
  ~HeapTree();

  int parent(int);//RETURN THE PARETN OF THE NODE
  int childRight(int);//RIGHT CHILD
  int childLeft(int);//LEFT CHILD
  void replace(int);//REPLACE NODE
  void push(int);//PUSH NODE
  int popLow();//POP THE LOW ELEMENT
  int popHigh();//POP THE HIGH ELEMENT
  void siftHigh(int);//REORDER
  void siftLow(int);//REORDER
  void displayAll();
  bool isEmpty();
  bool isFull();
};

#endif