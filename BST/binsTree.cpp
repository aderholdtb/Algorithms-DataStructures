#include<iostream>
#include"binsTree.h"
using namespace std;

BST::BST(){
  Root = NULL;
}

BST::~BST(){
  dTraverse(Root);
  Root = NULL;
}

void BST::showInOrder(){
  cout<<"\nSHOWING IN ORDER TRAVERSAL OF TREE..."<<endl;
  cout<<"====================================="<<endl;
  inOrderTraversal(Root);
  cout<<"\n";
}

void BST::inOrderTraversal(VertexPtr V){
  if(V != NULL){
    inOrderTraversal(V -> Left);
    cout<<V -> Elem<<" ";
    inOrderTraversal(V -> Right);
  }
}

void BST::showPreOrder(){
  cout<<"\nSHOWING PRE ORDER TRAVERSAL OF TREE..."<<endl;
  cout<<"======================================"<<endl;
  preOrderTraversal(Root);
  cout<<"\n";
}

void BST::preOrderTraversal(VertexPtr V){
  if(V != NULL){
    cout<<V -> Elem<<" ";//SHOW NODE AS SOON AS YOU HIT IT
    preOrderTraversal(V -> Left);
    preOrderTraversal(V -> Right);
  }
}

void BST::insertVertex(el_t Elem){//INSERT A NEW VERTEX
  VertexPtr NewNode = NULL;
  NewNode = new Vertex;
  NewNode -> Left = NULL;
  NewNode -> Right = NULL;
  NewNode -> Elem = Elem;

  if(Root == NULL){//MAKE THE NEW NODE THE ROOT
    cout<<"\nINSERTING "<<NewNode -> Elem<<" AS THE ROOT NODE"<<endl;
    Root = NewNode;
  }
  else{
    VertexPtr V = Root;
    VertexPtr Parent = NULL;
    
    while(V != NULL){//WHILE NO NODES LEFT
      if(NewNode -> Elem < V -> Elem){//GO LEFT ID LESS THAN
	Parent = V;
	V = V -> Left;
      }
      else if(NewNode -> Elem > V -> Elem){//GO RIGHT IF GREATER THAN
	Parent = V;
	V = V -> Right;
      }
      else{
	cout<<"\nTHE NODE "<<NewNode -> Elem<<" ALREADY EXISTS IN THE TREE..."<<endl;
	return;
      }
    }
    
    if(NewNode -> Elem < Parent -> Elem){//INSERT ELEMENT
      cout<<"\nINSERTING "<<NewNode -> Elem<<" TO THE LEFT OF "<<Parent -> Elem<<endl;
      Parent -> Left = NewNode;
    }
    else{
      cout<<"\nINSERTING "<<NewNode -> Elem<<" TO THE RIGHT OF "<<Parent -> Elem<<endl;
      Parent -> Right = NewNode;
    }
  }//END OF ELSE STATEMENT  
}

void BST::dTraverse(VertexPtr V){//DELETE DPS TRAVERSE
  if(V != NULL){
    dTraverse(V -> Left);
    dTraverse(V -> Right);
    delete V;
  }
}

void BST::deleteVertex(el_t Elem){//DELETE A VERTEX
  VertexPtr V = NULL;
  VertexPtr Parent = NULL;

  if((Root -> Elem == Elem) && (Root -> Left == NULL) && (Root -> Right == NULL)){//IF THE ROOT IS THE ONLY NODE
    cout<<"\nDELETING THE ROOT NODE "<<Root -> Elem<<endl;
    delete Root;
    Root = NULL;
  }
  else if((Root -> Elem == Elem) && (Root -> Left != NULL) && (Root -> Right == NULL)){//IF THE LEFT OF THE ROOT IS THE ONLY SUB TREE
    cout<<"\nREPLACING THE ROOT "<<Root -> Elem<<" WITH ITS LEFT NODE "<<Root -> Left -> Elem<<endl;
    Root = Root -> Left;
  }
  else if((Root -> Elem == Elem) && (Root -> Left == NULL) && (Root -> Right != NULL)){//IF THE RIGHT OF THE ROOT IS THE ONLY SUB TREE
    cout<<"\nREPLACING THE ROOT "<<Root -> Elem<<" WITH ITS RIGHT NODE "<<Root -> Right -> Elem<<endl;
    Root = Root -> Right;
  }
  else{
    V = Root;
    
    while(V != NULL){//WHILE THE NODE IS NOT NULL
      if(Elem < V -> Elem){//IF THE NEW NODE IS LESS THAN THE CURRENT NODE
	Parent = V;
	V = V -> Left;
      }
      else if(Elem > V -> Elem){//IF THE NEW NODE IS GREATER THAN CURRENT NODE
	Parent = V;
	V = V -> Right;
      }
      else{
	cout<<"\nREMOVING THE NODE "<<V -> Elem<<" FROM THE TREE"<<endl;
	remove(V, Parent);//REMOVE THE NODE IF YOU FOUND IT
	return;
      }
    }//END OF WHILE LOOP
    
    cout<<"\nTHE NODE "<<Elem<<" WAS NOT FOUND IN THE TREE"<<endl;
  }
}

void BST::remove(VertexPtr V, VertexPtr Parent){//REMOVE THE NODE IF FOUND IT
  if((V -> Left == NULL) && (V -> Right == NULL)){//IF LEFT AND RIGHT ARE BOTH NULL
    if(Parent -> Left == V){
      delete V;
      Parent -> Left = NULL;
    }
    else{
      delete V;
      Parent -> Right = NULL;
    }
  }
  else if((V -> Right != NULL) && (V -> Left == NULL)){//IF THE RIGHT IS NOT NULL
    if(V -> Right -> Elem > Parent -> Elem){
      Parent -> Right = V -> Right;
    }
    else{
      Parent -> Left = V -> Right;
    }
  }
  else if((V -> Left != NULL) && (V -> Right == NULL)){//IF THE LEFT IS NOT NULL
    if(V -> Left -> Elem > Parent -> Elem){
      Parent -> Right = V -> Left;
    }
    else{
      Parent -> Left = V -> Left;
    }
  }
  else{
    el_t maxElem = findMax(V);//FIND THE MAX OF THE LEFT SUB TREE
    V -> Elem = maxElem;
  }
}

el_t BST::findMax(VertexPtr V){//FIND MAX OF SUBTREE AND REPLACE WITH CURRENT NODE
  VertexPtr Parent = NULL;
  V = V -> Left;

  while(V -> Right != NULL){//FIND THE LAST RIGHT NODE
    Parent = V;
    V = V -> Right;
  }

  el_t maxElem = V -> Elem;//REPLACE WITH CURRENT ELEMENT
  remove(V, Parent);//DELETE LEAF NODE
  return maxElem;
}
