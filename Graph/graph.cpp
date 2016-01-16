#include<iostream>
#include<string>
#include<fstream>
#include"graph.h"
using namespace std;

Gvertex::Gvertex(){
  name = ' ';
  visitNum = 0;
}

Gvertex::~Gvertex(){

}

void Gvertex::displayGraph(){
  for(int slot = 0; slot < sizeOfArray; slot++){
    cout<<"Name: "<<Gtable[slot].name<<endl;
    cout<<"Out Number: "<<Gtable[slot].Out<<endl;
    cout<<"Visit Number: "<<Gtable[slot].visitNum<<endl;
    cout<<"AdjacentOnes: ";
    Gtable[slot].AdjacentOnes.displayAll();
  }
}

void Gvertex::fillTable(string filename){
  ifstream inFile;
  char Name = ' ';
  int slot = 0;

  inFile.open(filename.data());

  while(inFile>>Gtable[slot].name){
    inFile>>Gtable[slot].Out;

    for(int i = 0; i < Gtable[slot].Out; i++){
      inFile>>Name;
      Gtable[slot].AdjacentOnes.addRear(Name);
    }

    slot++;
    sizeOfArray++;
  }
}

int Gvertex::findOutDegree(char Name){
  for(int slot = 0; slot < sizeOfArray; slot++){
    if(Name == Gtable[slot].name)
      return Gtable[slot].Out;
  }

  return -1;
}

slist Gvertex::findAdjacency(char Name){
  for(int slot = 0; slot < sizeOfArray; slot++){
    if(Name == Gtable[slot].name)
      return Gtable[slot].AdjacentOnes;
  }
}

void Gvertex::visit(int visitNumber, char Name){
  for(int slot = 0; slot < sizeOfArray; slot++){
    if(Name == Gtable[slot].name)
      Gtable[slot].visitNum = visitNumber;
  }
}

bool Gvertex::isMarked(char Name){
  for(int slot = 0; slot < sizeOfArray; slot++){
    if(Name == Gtable[slot].name){
      if(Gtable[slot].visitNum != 0){
	cout<<"The Element is Marked"<<endl;
	return true;
      }
      else{
	cout<<"The Element has not been Marked"<<endl;
	return false;
      }
    }
  }
}