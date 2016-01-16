#include<iostream>
#include"bin.h"
using namespace std;

Tree::Tree(){
  root = NULL;
}

Tree::~Tree(){

}

void Tree::insertNodeReg(Node* newNode){//INSERTS A NODE THE REGULAR WAY
  Node* curr = getRoot();

  if(curr == NULL){//IF EMPTY
    root = newNode;
  }
  else{
    Node* parent = NULL;

    while(curr != NULL){//WHILE NOT AT A LEAF
      if(curr -> id < newNode -> id){//BRANCH RIGHT IF LESS THEN
	parent = curr;
	curr = curr -> right;
      }
      else if(curr -> id > newNode -> id){//BRANCH RIGHT IF GREATER THAN
	parent = curr;
	curr = curr -> left;
      }
      else{//IF THE NODE ALREADY EXISTS
	cout<<"That Node exists already!"<<endl;
	return;
      }
    }

    if(parent -> id > newNode -> id){//INSERT NODE ONCE AT LEAF
      cout<<"Inserting "<<newNode -> id<<" to the left of "<<parent -> id<<endl;
      newNode -> parent = parent;
      parent -> left = newNode;
    }
    else{
      cout<<"Inserting "<<newNode -> id<<" to the right of "<<parent -> id<<endl;

      newNode -> parent = parent;
      parent -> right = newNode;
    }
  }

}

void Tree::insertNodeRB(int newNum){//BALANCE THE TREE WITH NEW NODE
  Node* y = NULL, *x = NULL;

  x = new Node();//CREATE NEW NODE
  x -> left = NULL;
  x -> right = NULL;
  x -> id = newNum;
  x -> parent = NULL;
  x -> color = x -> red;

  insertNodeReg(x);//INSERT THE NODE REGULARLY

  while(x != getRoot() && x -> parent -> color == x -> red){//IF NOT LEVEL
    if(x -> parent -> parent -> left == x -> parent){//IF LEFT UNCLE IS PARENT OF X
      y = x -> parent -> parent -> right;
      
      if(y != NULL && y -> color == y -> red){//IF UNCLE IS RED, MEANS ITS LEVEL
	y -> color = y -> black;//CHANGE CURRENT LEVEL COLORS AND UPPER LEVEL COLORS
	y -> parent -> color = y -> red;
	x -> parent -> color = x -> parent -> black;
	x = x -> parent -> parent;
      }
      else{//NOT LEVEL
	if(x -> parent -> right == x){//IF X IS THE RIGHT CHILD
	  x = x -> parent;
	  rotateLeft(x);//ROTATE LEFT TO BALANCE
	}

	x -> parent -> color = x -> black;//CHANGE THE COLORS OR THE PARENT AND GRANDPARENT LEVEL
	x -> parent -> parent -> color = x -> red;

	rotateRight(x -> parent -> parent);//ROTATE RIGHT FROM GRANDPARENT
      }
    }
    else{//IF UNCLE RIGHT IS X PARENT
      y = x -> parent -> parent -> left;//GET THE SIBLING OF PARENT

      if(y != NULL && y -> color == y -> red){//IF IN ORDER CHANGE COLORS
        y -> color = y -> black;
        y -> parent -> color = y -> red;
        x -> parent -> color = x -> parent -> black;
        x = x -> parent -> parent;
      }
      else{//IF NOT LEVEL
        if(x -> parent -> left == x){//IF X IS PARENT LEFT
          x = x -> parent;
          rotateRight(x);//ROTATE RIGHT FROM PARENT
        }

        x -> parent -> color = x -> black;//CHANGE THE COLORS OR THE PARENT AND GRANDPARENT LEVEL
        x -> parent -> parent -> color = x -> red;

        rotateLeft(x -> parent -> parent);//ROTATE RIGHT FROM GRANDPARENT
      }
    }
  }

  root -> color = root -> black;
}

void Tree::inOrderDisplay(Node* root){
  if(root != NULL){
    inOrderDisplay(root -> left);
    cout<<root -> id<<" ";
    inOrderDisplay(root -> right);
  }
}

void Tree::rotateRight(Node* x){//ROATE RIGHT FROM UNCLE
  Node* y = x -> left;//LEFT OF X
  
  x -> left = y -> right;//X = RIGHT CHILD OF Y

  if(y -> right != NULL){//REASSIGN THE PARENT OF RIGHT CHILD
    y -> right -> parent = x;
  }

  y -> parent = x -> parent;//LET X AND Y POINT TO SAME PARENT

  if(x -> parent == NULL){//IF PARENT = NULL X WAS ROOT
    root = y;
  }
  else if(x -> parent -> left == x){//REASSIGN PARENTS CHILDREN
    x -> parent -> left = y;
  }
  else{
    x -> parent -> right = y;
  }

  y -> right = x;//ROTATE
  x -> parent = y;
}

void Tree::rotateLeft(Node* x){//ROATE LEFT FROM UNCLE
  Node* y = x -> right;//RIGHT CHILD OF X

  x -> right = y -> left;//X POINTS TO LEFT CHILD OF LEFT

  if(y -> left != NULL){//REASSIGN PARENT OF LEFT CHILD
    y -> left -> parent = x;
  }

  y -> parent = x -> parent;//POINT TO THE SAME PARENT FOR ROATATION

  if(x -> parent == NULL){//IF X WAS ROOT
    root = y;
  }
  else if(x -> parent -> left == x){//REASSIGN CHILDREN OF PARENT
    x -> parent -> left = y;
  }
  else{
    x -> parent -> right = y;
  }

  y -> left = x;//ROTATE
  x -> parent = y;
}

int Tree::deleteNode(int oldNum){//DELETE NODE, NO BALANCE NEEDED
  Node* curr = getRoot();

  if(curr == NULL){//IF NO NODES IN TREE
    cout<<"There are no nodes int he tree"<<endl;
    return -1;
  }
  else if(curr -> id == oldNum){//IF WANT TO DELETE ROOT NODE
    if(curr -> left == NULL && curr -> right == NULL){//IF NODE CHILDREN
      delete curr;
      root = NULL;
    }
    else if(curr -> left == NULL && curr -> right != NULL){//IF ONLY RIGHT CHILD 
      root = curr -> right;//RIGHT CHILD IS NEW ROOT
      root -> parent = NULL;
      delete curr;
    }
    else if(curr -> left != NULL && curr -> right == NULL){//IF ONLY LEFT CHILD
      root = curr -> left;//LEFT CHILD IS NEW ROOT
      root -> parent = NULL;
      delete curr;
    }
    else{
      removeNode(curr);//ELSE BOTH LEFT ANF RIGHT ARE NOT NULL
    }
  }
  else{
    while(curr -> id != oldNum){//ELSE FIND THE NODE THAT NEEDS DELETION
      if(curr -> id < oldNum){//GO RIGHT
	curr = curr -> right;
      }
      else if(curr -> id > oldNum){//GO LEFT
	curr = curr -> left;
      }
      else if(curr == NULL){//IF NOT FOUND
	cout<<"That node was node found"<<endl;
	return oldNum;
      }
    }

    removeNode(curr);//REMOVE THE NODE
  }
}


void Tree::removeNode(Node* curr){//FOUND THE NODE THAT NEEDS DELETION, NOW DELETE IT
  if(curr -> right == NULL && curr -> left == NULL){//DELETE LEAF NODE
    if(curr -> parent -> id < curr -> id){
      curr -> parent -> right = NULL;
      delete curr;
    }
    else{
      curr -> parent -> left = NULL;
      delete curr;
    }
  }
  else if(curr -> right != NULL && curr -> left == NULL){//REPLACE NODE WITH RIGHT NODE 
    if(curr -> parent -> id < curr -> id){
      curr -> parent -> right = curr -> right;
      delete curr;
    }
    else{
      curr -> parent -> left = curr -> right;
      delete curr;
    }
  }
  else{
    findMax(curr);//DELETE NODE AND REPLACE WITH NEXT HIGHEST NODE
  }
}

void Tree::findMax(Node* curr_1){//FIND MAX OF LEFT SUBTREE
  Node* curr = curr_1;
  curr = curr -> left;//LEFT SUBTREE OF CURRENT

  while(curr -> right != NULL){//GO RIGHT UNTIL FIND MAX
    curr = curr -> right;
  }

  curr_1 -> id = curr -> id;//REPLACE DELETION NODE WITH NEXT HIGHEST

  removeNode(curr);//DELETE THE OLD NODE OF NEXT HIGHEST
}

Node* Tree::getRoot(){//GET PRIVATE ROOT VARIABLE
  return root;
}
