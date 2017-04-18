/*-- LList.h --------------------------------------------------------------

  This header file defines a Linked List and Node data types.
  Basic operations:
    constructor:  Constructs an empty LList
    empty:        Checks if a LList is empty
    push:         Modifies a LList by adding a value at the top
    top:          Accesses the top LList value; leaves LList unchanged
    pop:          Modifies LList by removing the value at the top
    display:      Displays all the LList elements
  Note: Execution terminates if memory isn't available for a LList element.
--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef LLIST
#define LLIST

typedef int LListElement;

class LList{
    private:
        class Node{
            public:
                LListElement data;
                Node *next;
                //--- Node constructor
                Node(LListElement value, Node * link = 0)
                /*-------------------------------------------------------------------
                    Precondition:  None.
                    Postcondition: A Node has been constructed with value in its data
                    part and its next part set to link (default 0).
                -------------------------------------------------------------------*/
                : data(value), next(link)
                {}
        };

        typedef Node * NodePointer;
        NodePointer start;

    public:
        /***** Function Members *****/
        LList();
        /*-----------------------------------------------------------------------
            Construct a LList object.
            Precondition:  None.
            Postcondition: An empty LList object has been constructed
                (start is initialized to a null pointer).
        ------------------------------------------------------------------------*/

        LList(NodePointer nPtr);
        /*-----------------------------------------------------------------------
            Construct a LList with an explicit value.
            Precondition:  None.
            Postcondition: A new list is constructed using the given node pointer.
        ------------------------------------------------------------------------*/

        LList(const LList & original);
        /*-----------------------------------------------------------------------
            Copy constructor
            Precondition:  Original is a valid list.
            Postcondition: The original list is deep copied to a new list.
        ------------------------------------------------------------------------*/

        ~LList();
        /*------------------------------------------------------------------------
            Class destructor
            Precondition:  None
            Postcondition: The linked list in the LList has been deallocated.
        ------------------------------------------------------------------------*/

        const LList & operator= (const LList & rightHandSide);
        /*------------------------------------------------------------------------
            Assignment Operator
            Precondition:  rightHandSide is the LList to be assigned and is
            received as a const reference parameter.
            Postcondition: The current LList becomes a copy of rightHandSide
                and a const reference to it is returned.
        ------------------------------------------------------------------------*/

        bool empty() const;
        /*------------------------------------------------------------------------
            Check if LList is empty.
            Precondition: None
            Postcondition: Returns true if LList is empty and false otherwise.
        -----------------------------------------------------------------------*/

        int count() const;
        /*------------------------------------------------------------------------
            Count the number of nodes in a list.
            Precondition: None
            Postcondition: Returns the number of elements in a LList.
        -----------------------------------------------------------------------*/

        void display(ostream & out) const;
        /*------------------------------------------------------------------------
            Display values stored in the LList.
            Precondition:  ostream out is open.
            Postcondition: LList's contents, from top down, have been output to out.
        -----------------------------------------------------------------------*/

        void insert(const LListElement & value, int pos = -1);
        /*------------------------------------------------------------------------
            Insert a node into a list.
            Precondition:  value is to be inserted into this list
            Postcondition: Value is inserted into the give position in the list.
                If the position exceeds the number of elements in the list,
                the element is added at the end.
                The default position is -1, such values will also be added at
                the end of the list;
        -----------------------------------------------------------------------*/

        void deleteNode(int pos);
        /*------------------------------------------------------------------------
            Delete a node from a list.
            Precondition:  The list is not empty.
            Postcondition: The position is checked against the count of the list.
                If it exceeds the count a message is displayed and no node is deleted.
                If the node exists, it is deleted.
        -----------------------------------------------------------------------*/

        LListElement getNth(int pos);
        /*------------------------------------------------------------------------
            Get Nth element.
            Precondition:  The list is not empty.
            Postcondition: The position is checked against the count of the list.
                If it exceeds the count, or if the list is empty an error message is displayed.
                If the node exists, it's value is returned.
        -----------------------------------------------------------------------*/

        LList split();
        /*------------------------------------------------------------------------
            Split the list into two sublists.
            Precondition:  The list has at least two elements
            Postcondition: The provided list is split in two. If the number of elements is odd,
                the extra element should goes in the front list.
                The back half is returned by the function.
                If the provided list is empty or has fewer than 2 elements,
                a message is displayed and an empty list is returned.
        -----------------------------------------------------------------------*/

        LList splitNth(int pos);
        /*------------------------------------------------------------------------
            Split the list into two sublists.
            Precondition:  The list has at least two elements
            Postcondition: The provided list is split in two at the given position.
                The back half is returned by the function.
                If the provided list is empty or has fewer than 2 elements, or the position is invalid
                a message is displayed and an empty list is returned.
        -----------------------------------------------------------------------*/
};

#endif
