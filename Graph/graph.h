#ifndef GRAPH_H
#define GRAPH_H

const int maxSize = 20;

struct Gvertex{
  char name;
  int Out;
  int visitNum;
  slist adjacentOnes;

  Gvertex();
  ~Gvertex();

  void displayGraph();

  void filleTable(string filename);

  int findOutDegree(char Name);

  slist findAdjacency(char Name);

  void visit(int visitNumber, char Name);

  bool isMarked(char Name);
};

Gvertex Gtable[maxSize];
int sizeOfArray;

#endif