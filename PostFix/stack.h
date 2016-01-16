#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  static const int maxSize = 20;//MAX SIZE OF POSTFIX EXPRESSION
  int stk[maxSize];//STACK USING ARRAY
  int numOfElements;//NUMBER OF ELEMENTS IN STACK

  Stack();
  ~Stack();
  int pop();
  void push(int);
  int size();
  void print(); 
  bool empty();
  bool full(); 
};

#endif