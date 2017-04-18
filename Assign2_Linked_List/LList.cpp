//--- LList.cpp -------------------------------------------------

#include <new>
#include <assert.h>
using namespace std;

#include "LList.h"

//--- Definition of LList constructor
LList::LList()
: start(0)
{}

//--- Definition of LList explicit value constructor
LList::LList(NodePointer nPtr)
: start(nPtr)
{}

//--- Definition of LList copy constructor
LList::LList(const LList & original)
{
   start = 0;
   if (!original.empty())
   {
      // Copy first node
      start = new LList::Node(original.start->data);

      // Set pointers to run through the linked lists
      LList::NodePointer lastPtr = start,
                         origPtr = original.start->next;

      while (origPtr != 0)
      {
         lastPtr->next = new LList::Node(origPtr->data);
         origPtr = origPtr->next;
         lastPtr = lastPtr->next;
      }
   }
}

//--- Definition of LList destructor
LList::~LList()
{
   // Set pointers to run through the LList
   LList::NodePointer currPtr = start,  // node to be deallocated
                      nextPtr;          // its successor
   while (currPtr != 0)
   {
      nextPtr = currPtr->next;
      delete currPtr;
      currPtr = nextPtr;
   }
}

//--- Definition of assignment operator
const LList & LList::operator=(const LList & rightHandSide)
{
   if (this != &rightHandSide)         // check that not st = st
   {
      this->~LList();                  // destroy current linked list
      if (rightHandSide.empty())       // empty LList
         start = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         start = new LList::Node(rightHandSide.start->data);

         // Set pointers to run through the linked lists
         LList::NodePointer lastPtr = start,
                            rhsPtr = rightHandSide.start->next;

         while (rhsPtr != 0)
         {
            lastPtr->next = new LList::Node(rhsPtr->data);
            lastPtr = lastPtr->next;
            rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool LList::empty() const
{
   return (start == 0);
}

//--- Definition of count()
int LList::count() const
{
    int count = 0;
    //set pointer to run throught the linked list
    LList::NodePointer countPtr = start;
    while (countPtr != 0){
        count++; //increment count with each iteration
        countPtr = countPtr->next;
    }
    return count;
}

//--- Definition of display()
void LList::display(ostream & out) const
{
    //set pointer to run throught the linked list
    LList::NodePointer ptr;
    for (ptr = start; ptr != 0; ptr = ptr->next)
        out << ptr->data << endl; //print element data
}

//--- Definition of insert()
void LList::insert(const LListElement & value, int pos)
{
    // if the list is empty insert at the start
    if (this->empty())
        start = new LList::Node(value);
    //if the default position (-1) is provided
    //or if position exceeds the number of elements
    //insert at the end of the list
    else if(pos >= this->count() || pos == -1){
        //pointer to run throught the linked list
        LList::NodePointer ptr = start;
        while (ptr->next != 0)
            ptr = ptr->next;
        //insert new node after the last element
        ptr->next = new LList::Node(value);
    }
    //if the position is valid, insert at that position
    else{
        LList::NodePointer ptr = start;
        //iterate ptr to the node one place before the given position
        for (int i = 0; i < pos-1; i++)
            ptr = ptr->next;
        //insert a new node in the given position,
        //which points to the node that occupied this position before it
        ptr->next = new LList::Node(value, ptr->next);
    }
}

//--- Definition of delete()
void LList::deleteNode(int pos){
    //display error if the list is empty
    if(this->empty()){
        cerr << "*** List is empty ***\n";
    }
    //or if the position is invalid
    else if(pos >= this->count() || pos < 0){
        cerr << "*** Invalid position ***\n";
    }
    //if the position is valid, delete the node at the give position.
    else{
        LList::NodePointer ptr = start,
                           tmpPtr; //tmpPtr will hold the address of the node that is to be deleted.
        //iterate ptr to the node one place before the given position
        for (int i = 0; i < pos-1; i++)
            ptr = ptr->next;
        tmpPtr = ptr->next; //store the address in tmpPtr
        //make the node before the one that we're deleting to its next
        ptr->next = ptr->next->next;
        delete tmpPtr;
    }
}

//--- Definition of getNth()
LListElement LList::getNth(int pos){
    //if the list is empth display error message and return -1 as the value
    if(this->empty()){
        cerr << "*** List is empty ***\n";
        return -1;
    }
    //if the position is invalid display error message and return -1 as the value
    else if(pos >= this->count() || pos < 0){
        cerr << "*** Invalid position ***\n";
        return -1;
    }
    else{
        LList::NodePointer ptr = start;
        //navigate with ptr to the supplied position
        for (int i = 0; i < pos; i++)
            ptr = ptr->next;
        //return data stored in that node
        return ptr->data;
    }
}

//--- Definition of split()
LList LList::split(){
    //display error message and return empty list
    //if the list is empty
    if(this->empty()){
        cerr << "*** List is empty ***\n";
        return LList();
    }
    //or it has less than 2 elements
    else if(this->count() == 1){
        cerr << "*** Too few elements ***\n";
        return LList();
    }
    //else split the list in the middle
    else{
        LList::NodePointer ptr = start;
        //count()/2.0 guarantees that even with odd number of elements
        //the ptr will navigate to the necessary position
        for (int i = 0; i < this->count()/2.0 - 1; i++)
            ptr = ptr->next;
        //call explicit value constructor and supply the node next to split to it.
        LList backList(ptr->next);
        //'end' the original list after the middle position
        ptr->next = 0;
        //return the back list
        return backList;
    }
}

//--- Definition of splitNth()
LList LList::splitNth(int pos){
    //display error message and return empty list
    //if the list is empty
    if(this->empty()){
        cerr << "*** List is empty ***\n";
        return LList();
    }
    //or it has less than 2 elements
    else if(this->count() == 1){
        cerr << "*** Too few elements ***\n";
        return LList();
    }
    //or if the position is invalid
    else if(pos >= this->count() || pos < 0){
        cerr << "*** Invalid position ***\n";
        return LList();
    }
    //else split the list at the given position
    else{
        LList::NodePointer ptr = start;
        //navigate ptr to given position
        for (int i = 0; i < pos - 1; i++)
            ptr = ptr->next;
        //call explicit value constructor and supply the node next to split to it.
        LList backList(ptr->next);
        //'end' the original list after the middle position
        ptr->next = 0;
        //return the back list
        return backList;
    }
}

