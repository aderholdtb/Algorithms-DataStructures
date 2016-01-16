//=======================================================//
// Your name: Brandon Aderholdt                          //
// Compiler:  g++ compiler                               //
// File type: .cpp                                       //
//=======================================================//
#include<iostream>
#include"llist.h"
#include"slist.h"
using namespace std;

//===================================================================//
// PURPOSE: checks if the ist is empty                               //
//                                                                   //
// TO CALL: provide the true/false bool variable from isEmpty list   //
//===================================================================//
void checkEmpty(bool check){
  if(check)  // checks if empty is true
    cout<<"\nThe list is Empty!!!"<<endl;
  else
    cout<<"\nThe list is not Empty!!!"<<endl;
}

//===================================================================//
// PURPOSE: Just prints a message that displays the number removed   //
//                                                                   //
// TO CALL: provide the number removed from the list                 //
//===================================================================//
void removed(int number){
  cout<<"The number removed is: "<<number<<endl;
}

//===================================================================//
// PURPOSE: Just diplays the underflow error message                 //
//                                                                   //
// TO CALL: takes no parameter, just call when you want the message  //
//===================================================================//
void under(){
  cout<<"\nError: Too few Elements in the list!!!"<<endl;
}

void copyTest(const slist& list){
  slist NewList(list);  // copy constructor

  NewList.addRear(6);   // add rear

  cout<<"copied list ";
  NewList.displayAll();
}

//===================================================================//
// PURPOSE: Just diplays the outOfRange error message                //
//                                                                   //
// TO CALL: takes no parameter, just call when you want the message  //
//===================================================================//
void range(){
  cout<<"\nError: The index entered is invalid!!!"<<endl;
}

void checkReturned(int returned){
  if(returned != 0)
    cout<<"The number was found at location "<<returned<<endl;
  else 
    cout<<"The number was not found!!!"<<endl;
}
int main(){
  int RETURNED_NUMBER; // the number returned from deletion
  llist list;          // the list object
  slist slist, L1, L2;

  cout<<"\n=============="<<endl;
  cout<<"Test #NUMBER 1"<<endl;
  cout<<"=============="<<endl;
    
  checkEmpty(list.isEmpty()); // prints whether the list empty
    
  list.displayAll();  // displays all elements if there are any

  list.addRear(1);    // adds 1 to the rear
  list.addRear(2);    // adds 2 to the rear
  list.addRear(3);    // adds 3 to the rear

  list.displayAll();

  try{
    list.deleteFront(RETURNED_NUMBER);  // deletes the front element and returns it
    removed(RETURNED_NUMBER);  // displays the returned element
  }catch(llist::Underflow){
    under();  // if there are not enough elements to remove
  }  
  
  try{
    list.deleteFront(RETURNED_NUMBER);  //deletes front
    removed(RETURNED_NUMBER);  // displays deleted number
  }catch(llist::Underflow){
    under();  // error if no elements in list
  }

  list.displayAll();
  
  checkEmpty(list.isEmpty());
  
  try{
    list.deleteFront(RETURNED_NUMBER);  //deletes front
    removed(RETURNED_NUMBER);  // displays deleted number
  }catch(llist::Underflow){
    under();  // error if no elements in list
  }
  
  checkEmpty(list.isEmpty());  



  cout<<"\n\n\n=============="<<endl;
  cout<<"Test #NUMBER 2"<<endl;
  cout<<"=============="<<endl;

  list.addFront(5);  //adds 5 to the front
  list.addFront(4);  //adds 4 to the front
  
  try{
    list.deleteFront(RETURNED_NUMBER);  //deletes front
    removed(RETURNED_NUMBER);  // displays deleted number
  }catch(llist::Underflow){
    under();  // error if no elements in list
  }
  
  list.addRear(6);  // adds 6 to the rear
  list.addRear(8);  // adds 8 to the rear
  list.addRear(9);  // adds 9 to the rear
  
  list.displayAll();
  
  try{
    list.addBeforeIth(1, 4);  // adds 4 before the 1st element 
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }
  
  try{
    list.addBeforeIth(4, 7);  // adds 7 before the 4th element
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }

  try{
    list.addBeforeIth(7, 10);  // adds 10 before the 7th element
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }

  try{
    list.addBeforeIth(9, 12);  // adds 12 before the 9th element
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }

  try{
    list.addBeforeIth(0, 0);  // adds 0 before the 0 element
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }
  
  list.displayAll();
  
  try{
    list.deleteIth(1,RETURNED_NUMBER);  // deletes the number before the first element, and returns the number
    removed(RETURNED_NUMBER);  // prints the number removed
  }catch(llist::OutOfRange){
    range();  // error message if index is invalid
  }catch(llist::Underflow){
    under();  //error message if there are no elements
  }

  try{
    list.deleteIth(6,RETURNED_NUMBER);  // deletes the number before the first element, and returns the number
    removed(RETURNED_NUMBER);  // prints the number removed
  }catch(llist::OutOfRange){
    range();  // error message if index is invalid
  }catch(llist::Underflow){
    under();  //error message if there are no elements
  }
  
  try{
    list.deleteIth(3,RETURNED_NUMBER);  // deletes the number before the first element, and returns the number
    removed(RETURNED_NUMBER);  // prints the number removed
  }catch(llist::OutOfRange){
    range();  // error message if index is invalid
  }catch(llist::Underflow){
    under();  //error message if there are no elements
  }

  try{
    list.deleteIth(5,RETURNED_NUMBER);  // deletes the number before the first element, and returns the number
    removed(RETURNED_NUMBER);  // prints the number removed
  }catch(llist::OutOfRange){
    range();  // error message if index is invalid
  }catch(llist::Underflow){
    under();  //error message if there are no elements
  }
  
  try{
    list.deleteIth(0,RETURNED_NUMBER);  // deletes the number before the first element, and returns the number
    removed(RETURNED_NUMBER);  // prints the number removed
  }catch(llist::OutOfRange){
    range();  // error message if index is invalid
  }catch(llist::Underflow){
    under();  //error message if there are no elements
  }

  list.displayAll();

  while(!list.isEmpty()){              // deletes the whole list of numbers
    list.deleteRear(RETURNED_NUMBER);  // deletes rear until finished
    removed(RETURNED_NUMBER);          // prints number removed
  }
  
  list.displayAll();
 

  
  cout<<"\n\n\n=============="<<endl;
  cout<<"Test #NUMBER 3"<<endl;
  cout<<"=============="<<endl;
  
  try{
    list.addBeforeIth(0, 10);  // add 0 before the 10th element
  }catch(llist::OutOfRange){
    range();  // if the index given is invalid
  }
  
  try{
    list.deleteFront(RETURNED_NUMBER);  // deletes the front element, and returns the element
    removed(RETURNED_NUMBER);  // prints the returned element
  }catch(llist::Underflow){
    under();  // error if there are no elements in the list
  }
  


  cout<<"\n\n\n=============="<<endl;
  cout<<"Test #NUMBER 4"<<endl;
  cout<<"=============="<<endl;

  try{
    list.deleteIth(2,RETURNED_NUMBER);  // deleted the number before the 2nd element, and returns it
    removed(RETURNED_NUMBER);  // prints the deleted number
  }catch(llist::OutOfRange){ 
    range();  // error if invalid index
  }catch(llist::Underflow){
    under();  //error if there are no elements to erase
  }

  try{
    list.deleteRear(RETURNED_NUMBER);  // deletes and returns the last element
    removed(RETURNED_NUMBER);  // prints the removed element
  }catch(llist::Underflow){
    under();  // if there are no numbers to remove
  }

  cout<<"\n\n\n=============="<<endl;
  cout<<"slist testers"<<endl;
  cout<<"=============="<<endl;

  slist.addFront(4);
  slist.addRear(6);
  slist.addRear(7);
  slist.addRear(8);

  slist.displayAll();

  RETURNED_NUMBER = slist.search(6);
  checkReturned(RETURNED_NUMBER);

  try{
    slist.replace(RETURNED_NUMBER, 0);
  }catch(slist::OutOfRange){
    range();
  }

  RETURNED_NUMBER = slist.search(8);
  checkReturned(RETURNED_NUMBER);

  try{
    slist.replace(RETURNED_NUMBER, 2);
  }catch(slist::OutOfRange){
    range();
  }

  slist.displayAll();

  slist.search(5);

  cout<<"\n======================"<<endl;
  cout<<"slist copy constructor"<<endl;
  cout<<"======================"<<endl;

  for(int i = 1; i < 6; i++)  // add 1 - 5 to the linked list
    L1.addRear(i);

  cout<<"L1 ";
  L1.displayAll();  // display all should output 1 - 5
  
  copyTest(L1);     // copy to a new temperary linked list object
  cout<<"L1 ";

  L1.displayAll();  // should output  1 - 5
  L1 = L1;

  cout<<"L1 ";
  L1.displayAll();  // should output 1 - 5

  for(int i = 7; i < 11; i++) // insert 7 - 10 in another object
    L2.addRear(i);

  cout<<"L2 ";
  L2.displayAll();  // displays 7 - 10

  L2 = L1;          // object 2 becomes object 1

  cout<<"L2 ";
  L2.displayAll();  // should display 1 - 5

  try{
    L1.deleteRear(RETURNED_NUMBER);
  }catch(slist::Underflow){
    cout<<"No elements in the list to remove"<<endl;
  }

  cout<<"L1 ";
  L1.displayAll(); // displays 1 - 4

  cout<<"L1 ";
  L1.displayAll(); // displays 1 - 4

  cout<<"L2 ";
  L2.displayAll(); // displays 1 - 5

  return 0;
}
