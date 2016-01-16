#ifndef SLIST_H
#define SLIST_H

#include"llist.h"

class slist : public llist{
 public:
  slist& operator= (const slist& L1);//OPERATOR OVERLOAD FOR = OF OBJECT
  bool operator== (const slist& L1);//OPERATOR OVERLOAD == OF OBJECT

  slist();
  slist(const slist& Original);

  int search(el_t Key);//SEARCH FOR A KEY INT HE LINKED LIST

  void replace(int I, el_t Elem);//REPLACE ITH ELEMENT WITH NEW ELEMENT

  void copy(const NodePtr& L1, NodePtr& L2);//COPY CONSTRUCTOR
};

#endif