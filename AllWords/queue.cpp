//=====================================================//
//Your name: Brandon Aderholdt                         //
//Complier:  g++ compilier                             //
//File type: .cpp                                      //
//=====================================================//
#include<iostream>
#include<cstdlib>
#include "queue.h" 
using namespace std;

queue::queue() // constructor
{
  count = 0;
  back = -1;
}

queue::~queue() //destructor
{}

//===============================================================//
// PURPOSE: returns the current size to make it                  //
//          accessible to the client caller                      //
//===============================================================//
int queue::getSize(){
  return count;
}

//===============================================================//
// PURPOSE: returns true if queue is empty, otherwise false      //
//===============================================================//
bool queue::isEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}

//======================================================================//
// PURPOSE: if full, throws an exception Overflow                       //
//          if not full, enters an element at the back, increment count // 
// TO CALL: provide the element to be added                             //
//======================================================================//
void queue::add(el_t elem){
  char temp;

    count++;         // adding an element
    back += 1;       // one more index is opened up
    el.push_back(elem);
}

//===================================================================//
// PURPOSE: if empty, calls an emergency exit routine                //
//          if not empty, removes the front element and returns it   //
// TO CALL: provide a holder for the element removed (pass by ref)   //
//===================================================================//
void queue::remove(el_t& elem){
  if(isEmpty()){
    throw Underflow();
    exit(1);
  }
  else{
    elem = el[0];
    for(int i = 0; i < back; i++)
      el[i] = el[i+1];

    count--;  // remove an element
    back--;
  }
}

//====================================================================//
// PURPOSE: if empty, throws an exception Underflow                   //                  
//          if not empty, give back the front element                 //
//          (but does not remove it)                                  //
// TO CALL: provide a holder for the element (pass by ref)            //
//====================================================================//
void queue::frontElem(el_t& elem){
  if (isEmpty())
    throw Underflow();
  else
    elem = el[0];      // gives back the first element
}

//===============================================================//
// PURPOSE: display everything in the queue from front to back   //
//          enclosed in [], if empty, displays [ empty ]         //
//===============================================================//
void queue::displayAll(){
  if (isEmpty())
    cout <<" [ empty ] "<< endl;
  else{
    cout<<"\n\n[ ";

    for (int i = 0 ; i < count; i++)
      cout<<el[i]<<" ";  // prints out all of the elements

    cout<<"]\n";
  }
}
//===============================================================//
// PURPOSE: if empty, throws an exception Underflow              //
//          if queue has just 1 element, does nothing            //
//          if queue has more than 1 element, moves              //
//          the front one to the back                            //
//===============================================================//
void queue::goToBack(){
  string temp;

  if(isEmpty())
    throw Underflow();
  else if(getSize() > 1){
    temp = el[0];         // variable stores the first element
    el[0] = el[back];     // the first element equals the last one
    el[back] = temp;      // the back element equals the first one
  }
}