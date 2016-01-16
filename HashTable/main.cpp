#include<iostream>
#include"hash.h"
using namespace std;

int main(){
  Hash h;

  h.addElement("Brandon");
  h.addElement("Sarah");
  h.addElement("David");
  h.addElement("Karen");
  h.addElement("Brandon");
  h.addElement("A");
  h.addElement("B");
  h.addElement("C");
  h.addElement("House");
  h.addElement("Car");
  h.addElement("Race");
  h.addElement("Google");
  h.addElement("Bar");

  h.displayAll();

  Llist l = h.getElement(0);

  l.deleteIth(0);
  h.setElement(0, l);
  h.displayAll();

  return 0;
}