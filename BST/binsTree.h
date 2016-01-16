#ifndef BINSTREE_H
#define BINSTREE_H

class Vertex;

typedef int el_t;
typedef Vertex* VertexPtr;//VERTEX OR NODE OF THE LIST

struct Vertex{
  VertexPtr Right;//RIGHT OF NODE
  VertexPtr Left;//LEFT OF NODE
  el_t Elem;//ELEMENT OF THE NODE
};

class BST{
 private:
  VertexPtr Root;//ROOT 

 public:
  BST();
  ~BST();

  void showInOrder();//DEPTH FIRST SEARCH IN ORDER

  void inOrderTraversal(VertexPtr V);//DEPTH FIRST SEARCH IN ORDER

  void showPreOrder();//SHOW PRE ORDER

  void preOrderTraversal(VertexPtr V);//PRE ORDER TRAVERSAL DEPTH FIRST SEARCH

  void insertVertex(el_t Elem);//INSERT A NEW VERTEX

  void deleteVertex(el_t Elem);//DELETE A VERTEX

 protected:
  void dTraverse(VertexPtr V);

  void remove(VertexPtr V, VertexPtr Parent);//PART OF THE DELETE METHOD

  el_t findMax(VertexPtr V);//FIND MAX OF THE LEFT SUB TREE
};

#endif