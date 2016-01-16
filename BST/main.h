//========================================//
//Your name: Brandon Aderholdt            //
//Complier:  g++                          //
//File type: C                            //
//========================================//
#include <iostream>
#include "binsTree.h"
using namespace std;

int main()
{
  BST MyTree;                     // my first binary search tree

  for(int i = 1; i <=9 ; i=i+2)   // inserting 1,3,5,7,9 into the tree
      MyTree.insertVertex(i);

  for(int i = 10; i >=2 ; i=i-2)  // inserting 10,8,6,4,2 into the tree
      MyTree.insertVertex(i);

  MyTree.showInOrder();           // should show in the sorted order
  
  MyTree.showPreOrder();          // should show the parent before children


  //********************************************************
  cout << "\n===  Starting a new tree with 3 nodes ===="<< endl;
  BST Nums1;               // Nums1 is the second binary search tree

   Nums1.insertVertex(1);
   Nums1.insertVertex(2);
   Nums1.insertVertex(3);
   Nums1.deleteVertex(1);  // delete the root
   Nums1.showInOrder();

  //********************************************************
  cout << "\n===  Starting a new tree with 3 nodes ===="<< endl;
  BST Nums2;               // Nums2 is another binary search tree

   Nums2.insertVertex(10);
   Nums2.insertVertex(9);
   Nums2.insertVertex(8);
   Nums2.deleteVertex(10); // delete the root
   Nums2.showInOrder();

 //**********************************************************
  cout << "\n===  Starting a new tree with 7 nodes ===="<< endl;
  BST Nums;                // Nums is the last binary search tree

                           // creates a shallowest 7 node tree (draw this)
  Nums.insertVertex(3);    // root
  Nums.insertVertex(1);    // level 1 L
  Nums.insertVertex(2);    // level 2 R
  Nums.insertVertex(0);    // level 2 L
  Nums.insertVertex(5);    // level 1 R
  Nums.insertVertex(6);    // level 2 R
  Nums.insertVertex(4);    // level 2 L
  Nums.insertVertex(4);    // should be an error

                           // and show the nodes in sorted order
  Nums.showInOrder();

                           // and then delete some nodes 
  
    //  - level 2 right most leaf
    Nums.deleteVertex(6);
  
    // - level 1 right mode node with one left child
    Nums.deleteVertex(5);
  
    // - level 0 root with two children
    Nums.deleteVertex(3);
  
    // - deleting a non-existing one
    Nums.deleteVertex(7);
  
    //and then show the remaining nodes in sorted order
    Nums.showInOrder();  
}
