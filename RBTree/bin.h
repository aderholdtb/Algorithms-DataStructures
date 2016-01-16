#ifndef BIN_H
#define BIN_h

struct Node{
  enum{red, black}color;//COLOR FOR BALANCE
  Node* right;
  Node* left;
  Node* parent;
  int id;
};

class Tree{
 private:
  Node* root;

 public:
  Tree();
  ~Tree();

  void insertNodeReg(Node*);//INSERT NODE THE REGULAR WAY
  void insertNodeRB(int);//ROTATE UNTIL LEVEL
  void inOrderDisplay(Node*);//RECURSIVE CALL OF IN ORDER DISPLAY
  void rotateLeft(Node*);//ROTATE LEFT FROM UNCLE
  void rotateRight(Node*);//ROTATE RIGHT FROM UNCLE
  int deleteNode(int);//DELETE NODE
  void removeNode(Node*);//RPLACES NODE WITH NEXT HIGHEST
  void findMax(Node*);//FIND THE MAX OF LEFT SUBTREE
  Node* getRoot();//GET PRIVATE ROOT
};

#endif