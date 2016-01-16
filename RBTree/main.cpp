#include<iostream>
#include"bin.h"
using namespace std;

int main(){
  Tree t;

  for(int i = 0; i < 10; i++){
    t.insertNodeRB(i);
  }

  cout<<"Root: "<<t.getRoot() -> id<<endl;

  t.inOrderDisplay(t.getRoot());

  cout<<"\n";

  return 0;
}