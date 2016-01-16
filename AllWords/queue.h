//=======================================================//
// Your name: Brandon Aderholdt                          //
// Compiler:  g++ compiler                               //
// File type: queue header file queue.h                  //
//=======================================================//
#include<string>
#include<vector>
using namespace std;

 typedef string el_t;      // el_t is an alias for the data type

class queue{

  private:
    // Data members are:

    vector<el_t> el;     // an array called el.
                          
    int  count;            // how many elements do we have right now?

    int  back;             // where the back element of the queue is.

  public:    // prototypes to be used by the client

    class Overflow{};      // too many elements in the queue
    class Underflow{};     // too few elements in the queue

    queue();  // constructor

    ~queue(); // destructor

   //===================================================================//
   //PURPOSE: returns true if queue is empty, otherwise false           //
   //===================================================================//
   bool isEmpty();

   //===================================================================//
   // PURPOSE: if full, throws an exception Overflow                    //
   //          if not full, enters an element at the rear               //
   // TO CALL: provide the element to be added                          //
   //===================================================================//
   void add(el_t);

   //===================================================================//
   // PURPOSE: if empty, calls an emergency exit routine                //
   //          if not empty, removes the front element to give it back  //
   // TO CALL: provide a holder for the element removed                 //
   //          (pass by ref)                                            //
   //===================================================================//
   void remove(el_t&);

   //===================================================================//
   // PURPOSE: if empty, throws an exception Underflow                  //
   //          if not empty, give back the front element                //
   //          (but does not remove it)                                 //
   // TO CALL: provide a holder for the element (pass by ref)           //
   //===================================================================//
   void frontElem(el_t&);

   //===================================================================//
   // PURPOSE: returns the current size to make it                      //
   //          accessible to the client caller                          //
   //===================================================================//
   int getSize();

   //===================================================================//
   // PURPOSE: display everything in the queue from front to rear       //
   //          enclosed in [], if empty, displays [ empty ]             //
   //===================================================================//
   void displayAll();

   //===================================================================//
   // PURPOSE: if empty, throws an exception Underflow                  //
   //          if queue has just 1 element, does nothing                //
   //          if queue has more than 1 element, moves the front        //
   //          one to the rear                                          //
   //===================================================================//
   void goToBack();
};           

