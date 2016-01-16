#include<iostream>
#include"llist.h"
using namespace std;

llist::llist(){
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist(){//DELETE EVERY ELEMENT IN THE LIST
  el_t DELETED_ELEMENT;

  cout<<"\nCALLING THE DESTRUCTOR"<<endl;
  cout<<"======================"<<endl;

  if(isEmpty())
    cout<<"[ EMPTY ]"<<endl;
  else{
    while(Front != NULL){
      deleteRear(DELETED_ELEMENT);
      cout<<"REMOVED: "<<DELETED_ELEMENT<<endl;
    }

    Front = NULL;
    Rear = NULL;
    Count = 0;
  }

  cout<<"======================\n"<<endl;
}

bool llist::isEmpty(){//CHECK IF THE LIST IS EMPTY
  if(Count == 0)
    return true;
  else
    return false;
}

void llist::displayAll(){//DISPLAY ALL ELEMENTS
  NodePtr curr = Front;

  if(isEmpty())
    cout<<"[ EMPTY ]"<<endl;
  else{
    cout<<"[";

    for(int i = 0; i < Count; i++){
      cout<<" "<<curr -> Elem;
      curr = curr -> Next;
    }

    cout<<" ]\n"<<endl;
  }
}

void llist::addFront(el_t NewElem){//ADD ELEMENT TO THE FRONT OF THE LINKED LIST
  NodePtr NewNode;
  NewNode = new Node;
  NewNode -> Elem = NewElem;

  if(isEmpty()){//CHECKS IF THE LIST IS EMPTY
    NewNode -> Next = NULL;//ADD TO THE FRONT OF THE LIST
    Front = NewNode;
    Rear = Front;
  }
  else{//MAKE ROOM FOR THE FIRST NEW ELEMENT
    NewNode -> Next = Front;
    Front = NewNode;
  }

  Count++;
}

void llist::deleteFront(el_t& OldElem){// DELETE THE FIRST ELEMENT AND MAKE THE SECOND ELEMENT THE FIRST ELEMENT
  NodePtr curr = Front;

  if(isEmpty()){
    throw Underflow();
  }
  else if(curr -> Next == NULL){//IF THERE IS ONLY ONE ELEMENT IN THE LIST
    OldElem = Front -> Elem;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  }
  else{
    curr = curr -> Next;
    OldElem = Front -> Elem;
    delete Front;
    Front = curr;
    Count--;
  }
}

void llist::addRear(el_t NewElem){//ADD ELEMENT TO THE REAR OF THE LINKED LIST
  NodePtr NewNode;
  NewNode = new Node;
  NewNode -> Elem = NewElem;

  if(isEmpty()){//IF THE LIST IS EMPTY ADD TO THE FRONT
    addFront(NewElem);
  }
  else{
    Rear -> Next = NewNode;//GO TO THE REAR AND ADD
    NewNode -> Next = NULL;
    Rear = NewNode;
    Count++;
  }
}

void llist::deleteRear(el_t& OldElem){//DELETE THE REAR ELEMENT
  NodePtr curr = Front;

  if(isEmpty()){//IF THE LIST IS EMPTY THEN RETURN UNDERFLOW
    throw Underflow();
  }
  else if(Count == 1){//DELETE THE FRONT ELEMENT IF THERE IS ONLY 1 ELEMENT
    deleteFront(OldElem);
  }
  else{
    while(curr -> Next != Rear){//GO TO THE REAR AND DELETE THE LAST ELEMENT
      curr = curr -> Next;
    }

    OldElem = Rear -> Elem;
    delete Rear;
    curr -> Next = NULL;
    Rear = curr;
    Count--;
  }
}

void llist::addBeforeIth(int I, el_t NewElem){//ADD BEFORE THE ITH ELEMENT
  NodePtr NewNode, curr, prev;
  curr = Front;
  NewNode = new Node;
  NewNode -> Elem = NewElem;

  if((I < 1) || (I > Count + 1)){//IF INDEX IS OUT OF RANGE OF THE CURRENT LIST
    throw OutOfRange();
  }
  else if(isEmpty()){//IF THE LIST IS EMPTY THEN ADD TO FRONT
    addFront(NewElem);
  }
  else if(Count == 1){//IF WANT TO ADD BEFORE THE FIRST ELEMENT
    addFront(NewElem);
  }
  else if(I == Count + 1){//IF YOU WANT TO ADD AFTER THE LAST ELEMENT
    addRear(NewElem);
  }
  else{//ELSE FIND THE ITH ELEMENT AND INSERT
    for(int i = 0; i < I; i++){
      prev = curr;
      curr = curr -> Next;
    }

    prev -> Next = NewNode;
    NewNode -> Next = curr;
    Count++; 
  }
}

void llist::deleteIth(int I, el_t& OldElem){//DELETE THE ITH ELEMENT
  NodePtr curr, prev;
  curr = Front;

  if(isEmpty()){//IF THE LIST IS EMPTY RETURN EMPTY
    throw Underflow();
  }
  else if((I < 1) || (I > Count)){//IF THE ITH ELEMENT IS OUT OF RANGE
    throw OutOfRange();
  }
  else if(Count == 1){//IF THERE IS ONLY ONE ELEMENT INT HE LIST 
    deleteFront(OldElem);
  }
  else if(I == Count){//IF WANT TO DELETE THE LAST ELEMENT
    deleteRear(OldElem);
  }
  else{//ELSE FIND THE ITH ELEMENT AND DELETE IT
    for(int i = 0; i < I; i++){
      prev = curr;
      curr = curr -> Next;
    }

    prev -> Next = curr -> Next;
    OldElem = curr -> Elem;
    delete curr;
    Count--;
  }
}
