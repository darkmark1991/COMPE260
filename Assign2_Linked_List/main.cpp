#include <iostream>

using namespace std;

#include "LList.h"

int main()
{
    LList list1;

    list1.insert(1);
    list1.insert(2,-110);
    list1.insert(3,1);
    list1.insert(4,-1);
    list1.insert(5,1);
    list1.insert(6,2);
    list1.insert(7,1);

    cout << "Display the list:" << endl;
    list1.display(cout);
    cout << endl;

    cout << "Insert 100 at position 3 and display list:" << endl;
    list1.insert(100, 3);
    list1.display(cout);
    cout << endl;

    cout << "Delete node at position 5 and display list:" << endl;
    list1.deleteNode(5);
    list1.display(cout);
    cout << endl;


    cout << "The number of elements is: " << list1.count() << endl;
    cout << endl;

    cout << "Split the list in two:" << endl;
    LList list2 = list1.split();
    cout << "List 1: " << endl;
    list1.display(cout);
    cout << "List 2: " << endl;
    list2.display(cout);
    cout << endl;

    cout << "The number of elements in list one is even: " << list1.count() << endl;
    cout << endl;

    cout << "Split the list 1 in two:" << endl;
    cout << "List 1: " << endl;
    list1.display(cout);
    LList list12 = list1.split();
    cout << "List 1.1: " << endl;
    list1.display(cout);
    cout << "List 1.2: " << endl;
    list12.display(cout);
    cout << endl;

    cout << "Split the list 2 at position 1:" << endl;
    cout << "List 2: " << endl;
    list2.display(cout);
    LList list22 = list2.splitNth(1);
    cout << "List 2.1: " << endl;
    list2.display(cout);
    cout << "List 2.2: " << endl;
    list22.display(cout);
    cout << endl;

    cout << "Delete invalid node: position 100" << endl;
    list1.deleteNode(100);
    cout << endl;

    LList emptyList;
    cout << "Delete node from an empty list" << endl;
    emptyList.deleteNode(100);
    cout << endl;

    cout << "Get Nth from an empty list" << endl;
    emptyList.getNth(100);
    cout << endl;

    cout << "Get Nth with invalid position" << endl;
    list1.getNth(100);
    cout << endl;


    cout << "Split empty list" << endl;
    emptyList.split();
    cout << endl;

    cout << "Split list with less than 2 elements" << endl;
    cout << "List 2.1: " << endl;
    list2.display(cout);
    list2.split();
    cout << endl;

    cout << "Split empty list at Nth element" << endl;
    emptyList.splitNth(2);
    cout << endl;

    cout << "Split list with less than 2 elements" << endl;
    cout << "List 2.1: " << endl;
    list2.display(cout);
    list2.splitNth(2);
    cout << endl;

    cout << "Split list at invalid position" << endl;
    cout << "List 1.1: " << endl;
    list1.display(cout);
    list1.splitNth(200);
    cout << endl;


    return 0;
}
