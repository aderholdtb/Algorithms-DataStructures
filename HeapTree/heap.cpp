#include<iostream>
#include<cmath>
#include"heap.h"

HeapTree::HeapTree(){
  memset(heap, 0, sizeof(heap));
  size = 0;
}

HeapTree::~HeapTree(){
}

int HeapTree::parent(int index){//PARENT IN ARRAY
  return (index - 1)/2;
}

int HeapTree::childRight(int index){//RIGHT CHILD INDEX IN ARRAY
  return (2 * index) + 2;
}

int HeapTree::childLeft(int index){//LEFT CHILD INDEX IN ARRAY
  return (2 * index) + 1;
}

void HeapTree::push(int priority){
  Node newNode(priority);

  //if the heap is empty
  if(isEmpty()){
    heap[0] = newNode;
    size++;
  }
  else if(isFull()){//could have popped the highest priority node
    std::cout<<"The heap Tree is full"<<std::endl;
  }
  else{//add the new node
    heap[size] = newNode;
    siftLow(size++);
  }
}

void HeapTree::siftLow(int index){
  int parentIndex = parent(index);

  if(heap[index].getPriority() > heap[parentIndex].getPriority()){
    int temp = heap[index].getPriority();

    //swap parent and child
    heap[index].setPriority(heap[parentIndex].getPriority());
    heap[parentIndex].setPriority(temp);

    //heapify again
    if(parentIndex != 0)
      siftLow(parentIndex);
  }
}

void HeapTree::siftHigh(int index){
  int left = childLeft(index);
  int right = childRight(index);

  if(size == 1){
    return;
  }
  else if(heap[left].getPriority() > heap[right].getPriority() && left < MAX_SIZE && heap[left].getPriority() != 0){
    int temp = heap[index].getPriority();

    //swap parent and child
    heap[index].setPriority(heap[left].getPriority());
    heap[left].setPriority(temp);
    siftHigh(left);
  }
  else if(heap[left].getPriority() < heap[right].getPriority() && right < MAX_SIZE && heap[right].getPriority() != 0){
    int temp = heap[index].getPriority();

    //swap parent and child
    heap[index].setPriority(heap[right].getPriority());
    heap[right].setPriority(temp);
    siftHigh(right);
  }
}

int HeapTree::popHigh(){//POP HIGH ELEMENT
  if(isEmpty()){
    std::cout<<"The heap tree is empty"<<std::endl;
    return -1;
  }
  else{
    int high = heap[0].getPriority();
    size--;

    heap[0].setPriority(heap[size].getPriority());
    heap[size].setPriority(0);

    siftHigh(0);
    return high;
  }
}

int HeapTree::popLow(){//POP LOW ELEMENT
  int low = heap[--size].getPriority();
  heap[size].setPriority(0);
  return low;
}

void HeapTree::displayAll(){//DISPLAY TREE
  int nextSlot = 0;
  const int depth = (int)ceil(sqrt(size + 1));

  for(int i = 0; i < depth; i++){
    std::cout<<"[ ";

    for(int slot = 0; slot < pow(2, i); slot++){
      nextSlot = (int)pow(2, i) - 1 + slot;
      std::cout<<heap[nextSlot].getPriority()<<" ";
    }
    std::cout<<"]\n";

  }
}

bool HeapTree::isEmpty(){
  return size == 0;
}

bool HeapTree::isFull(){
  return size == MAX_SIZE;
}
