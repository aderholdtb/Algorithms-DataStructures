#include <iostream>
#include"stack.h"
using namespace std;

Stack::Stack(){
  numOfElements = -1;//NUMBER OF ELEMENTS IS USED AS INDEX FOR ARRAY
}

Stack::~Stack(){
}

int Stack::pop(){
  print();//PRINT CURRENT STACK BEFORE POPPING
 
  int poppedElement;

  poppedElement = stk[numOfElements];//POP THE LAST ELEMENT IN THE STACK
  stk[numOfElements] = 0;
  numOfElements--;

  cout<<"Popping "<<poppedElement<<" from the stack."<<endl;
  return poppedElement;
}

void Stack::push(int value){
  if(full()){//PUSH VALUE ONTO THE STACK
    cout<<"Overflow Exception"<<endl;
    exit(1);
  }

  cout<<"Pushing "<<value<<" into the stack."<<endl;

  numOfElements++;
  stk[numOfElements] = value;
}

bool Stack::full(){//CEHCKS IF FULL
  if(numOfElements == maxSize - 1)
    return true;
  else
    return false;
}

bool Stack::empty(){//CHECKS IF EMPTY
  if(numOfElements == -1)
    return true;
  else
    return false;
}

int Stack::size(){//RETURNS SIZE
  return numOfElements + 1;
}

void Stack::print(){//PRINTS THE ARRAY
  cout<<"\nCurrent Stack"<<endl;
  cout<<"============="<<endl;

  for(int i = 0; i < size(); i++){
    cout<<stk[i]<<endl;
  }
  cout<<"\n";
}
