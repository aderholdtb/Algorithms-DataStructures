#include<iostream>
#include"slist.h"
using namespace std;

slist::slist(){
}

slist::slist(const slist& Original){//COPY CONSTRUCTO FOR THE LINK LIST
  Front = NULL;
  Rear = NULL;
  Count = 0;

  copy(Original.Front, Front);
}

slist& slist::operator= (const slist& L1){//OPERATOR =
  NodePtr curr_1 = L1.Front, curr_2 = Front;
  int DELETED_ELEMENT;

  if(&L1 != this){//IF THEY ARE NOT EQUAL ALREADY
    while(!this -> isEmpty())//DELETE THE PREVIOUS LIST
      this -> deleteRear(DELETED_ELEMENT);

    while(curr_1 != NULL){//WHILE THERE ARE NO ELEMENTS IN THE LIST
      this -> addRear(curr_1 -> Elem);
      curr_1 = curr_1 -> Next;
    }
  }

  return *this;
}

bool slist::operator== (const slist& L1){//OPERATOR ==
  NodePtr curr_1 = L1.Front, curr_2 = Front;

  while((curr_1 != NULL) && (curr_2 != NULL)){//IF THE LISTS ARE NOT EMPTY
    if(curr_1 -> Elem != curr_2 -> Elem)//CHECKS IF THEY ARE EQUAL
      return false;

    curr_1 = curr_1 -> Next;
    curr_2 = curr_2 -> Next;
  }

  if((curr_1 == NULL) && (curr_2 == NULL))//CHECKS IF THE LAST ELEMENT IS NULL
    return true;
  else//IF ONE IS NOT NULL THEN THEY ARE NOT EQUAL
    return false;
}

int slist::search(el_t Key){//SEARCH FOR AN ELEMENT IN THE LIST
  NodePtr curr = Front;

  for(int index = 1; index < Count + 1; index++){//ITERATE THEROUGH THE LIST
    if(curr -> Elem == Key)
      return index;

    curr = curr -> Next;
  }

  return 0;
}

void slist::replace(int I, el_t Elem){//REPLACE ITH ELEMENT WITH NEW ELEMENT
  NodePtr curr = Front;

  if((I < 1) || (I > Count)){//IF INDEX IS OUT OF RANGE
    throw OutOfRange();
  }
  else{
    for(int i = 1; i < I; i++){//FIND THE ITH ELEMENT AND REPLACE
      curr = curr -> Next;
    }
    
    curr -> Elem = Elem;

    cout<<"\nReplaced "<<curr -> Elem<<" with "<<Elem<<"\n"<<endl; 
  }
}

void slist::copy(const NodePtr& L1, NodePtr& L2){//COPY CONSTRUCTOR
  NodePtr curr_1 = L1, curr_2 = NULL;

  if(curr_1 != NULL){//IF THE LIST IS NOT EMPTY
    L2 = new Node;//L2 IS NEW LIST
    curr_2 = L2;

    while(curr_1 -> Next != NULL){//WHILE NOT REACH THE END OF THE LIST
      curr_2 -> Next = new Node;//COPY ALL ELEMENTS
      curr_2 -> Elem = curr_1 -> Elem;

      curr_1 = curr_1 -> Next;
      curr_2 = curr_2 -> Next;

      Count++;//INCREMENT COUNT
    }

    curr_2 -> Elem = curr_1 -> Elem;//ADD LAST ELEMENT
    Count++;

    curr_2 -> Next = NULL;//REAR IS THE LAST ELEMENT
    Rear = curr_2;
  }
}