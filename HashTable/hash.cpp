#include<iostream>
#include"hash.h"
using namespace std;

Hash::Hash() : Llist(){
}

Hash::~Hash(){//DELETE TABLE
  for(int i = 0; i < originalMax; i++){
    _table[i].removeAll();
  }
}

//USED VERY SIMPLE HASH KEY FOR DEMONSTRATION PURPOSES

int Hash::getHashKey(string elem){//RETURN INDEX FOR HASH KEY
  int hashKey = 0;

  for(int i = 0; i < elem.size() - 1; i++){
    hashKey += elem[i];
  }

  return hashKey%originalMax;
}

void Hash::addElement(string elem){
  _table[getHashKey(elem)].addFront(elem);
}

Llist Hash::getElement(int index){//RETURN WHOLE LIST
  return _table[index];
}

void Hash::displayAll(){
  for(int i = 0; i < originalMax; i++){
    _table[i].displayAll();
  }
}

void Hash::setElement(int index, Llist l){
  _table[index] = l;
}
