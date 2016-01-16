// =========================================================
//Your name: Brandon Aderholdt
//Complier:  g++ compiler
//File type: .cpp
//================================================================
#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.h"
using namespace std;

int main()
{
  queue Q;
  string el_value;
  string temp;

  for(int i = 65; i < 90; i++){
    temp = i;
    Q.add(temp);
    cout<<temp<<endl;
  }

  Q.displayAll();

  while(Q.getSize() < 100){
    //--------------------------------------------------------------//
    try{
    Q.remove(el_value);
    cout<<el_value<<endl;

    for(int i = 65; i < 90; i++){
      temp = i;
      Q.add(el_value + temp);
    }

    Q.displayAll();
    }
    //--------------------------------------------------------------//
    // Catch exceptions and report problems and quit the program now.
    catch (queue::Underflow){
      cout<<"\nError: Too few elements in queue to remove!!!"<<endl;
      exit(1);
    }
  }

  return 0;
}
