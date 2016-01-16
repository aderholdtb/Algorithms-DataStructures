#ifndef HASH_H
#define HASH_H
#include"llist.h"

const int originalMax = 23;

class Hash : public Llist{
 private:
  Llist _table[originalMax];

 public:
  Hash();
  ~Hash();

  int getHashKey(std::string elem); 
  void addElement(std::string);
  Llist getElement(int);
  void displayAll();
  void setElement(int, Llist);
};

#endif