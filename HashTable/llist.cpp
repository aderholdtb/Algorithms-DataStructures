#include<iostream>
#include"llist.h"
using namespace std;

Llist::Llist(){
  _Front = NULL;
  _Rear = NULL;
}

Llist::~Llist(){
}

Node* Llist::getAdjacent(){//GET THE ADJACENECY LIST OF THE HASH KEY
  return getFront();
}

void Llist::addFront(string name){//ADD NODE TO THE FRONT OF THE LIST
  Node* newNode = NULL, *curr = getFront();
  newNode = new Node();//CREATE NEW NODE
  newNode -> name = name;
  newNode -> next = NULL;

  if(isEmpty()){//IF FIRST NODE
    _Front = newNode;
    _Rear = newNode;
  }
  else{
    newNode -> next = curr;//ADD BEFORE FIRST
    _Front = newNode;
  }
}

string Llist::deleteIth(int index){//DELETE THE ITH ELEMENT IN THE LIST STARTING FROM 0
  Node* curr = getFront();
  string name = "";

  if(isEmpty()){//IF LIST IS EMPTY
    cout<<"List is Empty"<<endl;
  }
  else if(index < 0 || index > getSize()){//IF INDEX IS OUT OF RANGE
    cout<<"Out of Range"<<endl;
  }
  else if(index == 0){//IF FIRST ELEMENT
    name = deleteFront();   
  }
  else if(index == getSize()){//IF LAST ELEMENT
    name = deleteRear();
  }
  else{
    for(int i = 0; i < i - 1; i++){//FIND THE ITH ELEMENT
      curr = curr -> next;
    }

    Node* currNext = curr -> next -> next;//PREV = CURR -> NEXT
    name = curr -> next -> name;
    delete curr -> next;
    curr -> next = currNext;
  }

  return name;
}

void Llist::addRear(string name){//ADD NODE TO THE BACK OF THE LIST
  Node* newNode = NULL, *curr = getRear();

  newNode = new Node();//CREATE NEW NODE
  newNode -> name = name;
  newNode -> next = NULL;

  if(isEmpty()){//IF LIST IS EMPTY
    addFront(name);
  }
  else{//ADD AFTER REAR AND CHANGE REARS VALUE
    curr -> next = newNode;
    _Rear = newNode;
  }
}

string Llist::deleteFront(){//DELETE THE FRONT OF THE LIST
  Node* curr = getFront();
  string name = "";

  if(isEmpty()){
    cout<<"The llist is empty"<<endl;
  }
  else if(curr -> next == NULL){//IF FRONT IS THE ONLY NODE
    name = curr -> name;
    _Front = NULL;
    delete curr;
  }
  else{
    name = curr -> name;//ELSE MAKE FRON THE CURRENT -> NEXT
    curr = curr -> next;
    delete _Front;
    _Front = curr;
  }

  return name;
}

string Llist::deleteRear(){
  Node* curr = getFront();//NEED TO START FRONT FRONT BECAUSE WE DONT HAVE REARS PREVIOUS
  string name;

  if(isEmpty()){
    cout<<"The llist is empty"<<endl;
  }
  else if(curr -> next == NULL){//IF REAR = FRONT
    _Rear = NULL;
    name = deleteFront();
  }
  else{
    while(curr -> next -> next != NULL){//ELSE STOP BEFORE THE LAST NODE
      curr = curr -> next;
    }

    name = curr -> next -> name;//DELETE THE REAR NODE AND CHANGE REAR VALUE
    delete curr -> next;
    _Rear = curr;
    _Rear -> next = NULL;
  }

  return name;
}

void Llist::displayAll(){
  Node* curr = getFront();

  cout<<"[ ";

  while(curr != NULL){
    cout<<curr -> name<<" ";
    curr = curr -> next;
  }

  cout<<"] "<<endl;
}

Node* Llist::getFront(){
  return _Front;
}

Node* Llist::getRear(){
  return _Rear;
}

bool Llist::isEmpty(){
  if(getFront() == NULL)
    return true;
  else
    return false;
}

void Llist::removeAll(){//DELETE THE WHOLE LIST //FOR DESTRUCTOR 
  while(!isEmpty()){
    cout<<"REMOVING: "<<deleteFront()<<endl;
  }
}

int Llist::getSize(){//GET SIZE OF LIST STARTING FROM 1 AS THE FIRST ELEMENT
   Node* curr = getFront();
   int count = 0;

   while(curr != NULL){
     count++;
     curr = curr -> next;
   }

   return count;
 }
