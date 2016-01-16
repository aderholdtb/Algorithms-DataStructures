#include<iostream>
#include"heap.h"

int main(){
  HeapTree tree;
  tree.push(20);//INSERT ELEMENTS
  tree.push(15);
  tree.push(9);
  tree.push(8);
  tree.push(5);
  tree.push(3);
  tree.push(7);
  tree.push(6);
  tree.push(2);
  tree.push(1);
  tree.push(100);
  tree.push(12);

  tree.displayAll();//DISPLAY ALL ELEMENTS

  std::cout<<"Popped: "<<tree.popHigh()<<std::endl;
  std::cout<<"Popped: "<<tree.popHigh()<<std::endl;

  tree.displayAll();
  return 0;
}