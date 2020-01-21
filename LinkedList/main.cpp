#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<int> myList;
    myList.addLast(0);
    myList.addLast(1);
    myList.add(2, 2);
    myList.print();                    // 0 1 2
    cout << myList.getSize() << endl;  // 3

    myList.addFirst(3);
    myList.addFirst(4);
    myList.addFirst(5);
    myList.print();                    // 5 4 3 0 1 2
    cout << myList.getSize() << endl;  // 6

    myList.addLast(6);
    myList.addLast(7);
    myList.print();                    // 5 4 3 0 1 2 6 7
    cout << myList.getSize() << endl;  // 8

    cout << endl;

    cout << myList.change(0, 7) << endl;  // 1
    myList.print();                       // 7 4 3 0 1 2 6 5
    cout << myList.getSize() << endl;     // 8

    cout << myList.change(0, 6) << endl;  // 1
    myList.print();                       // 6 4 3 0 1 2 7 5
    cout << myList.getSize() << endl;     // 8

    cout << myList.change(0, 1) << endl;  // 1
    myList.print();                       // 4 6 3 0 1 2 7 5
    cout << myList.getSize() << endl;     // 8

    cout << myList.change(0, 0) << endl;  // 1
    myList.print();                       // 4 6 3 0 1 2 7 5
    cout << myList.getSize() << endl;     // 8

    cout << myList.change(1, 7) << endl;  // 1
    myList.print();                       // 4 5 3 0 1 2 7 6
    cout << myList.getSize() << endl;     // 8

    cout << myList.change(6, 7) << endl;  // 1
    myList.print();                       // 4 5 3 0 1 2 6 7
    cout << myList.getSize() << endl;     // 8

    myList.del(0);
    myList.print();                       // 5 3 0 1 2 6 7

    myList.del(1);
    myList.print();                       // 5 0 1 2 6 7

    myList.del(5);
    myList.print();                       // 5 0 1 2 6

    LinkedList<int> myList2(myList);

    myList.deleteAll();
    myList.addFirst(0);
    myList.addLast(1);
    myList.print();                       // 0 1
    myList.del(1);
    myList.print();                       // 0
    cout << myList.getSize() << endl;     // 1

    myList2.deleteFirst();
    myList2.print();                      // 0 1 2 6

    myList2.deleteLast();
    myList2.print();                      // 0 1 2

    myList2.deleteLast();
    myList2.deleteLast();
    myList2.print();                      // 0
    myList2.deleteLast();
    myList2.print();                      //

    myList2.addLast(0);
    myList2.print();                      // 0
    myList2.reverse();
    myList2.print();                      // 0
    myList2.addLast(1);
    myList2.print();                      // 0 1
    myList2.reverse();
    myList2.print();                      // 1 0
    myList2.addLast(2);
    myList2.print();                      // 1 0 2
    myList2.reverse();
    myList2.print();                      // 2 0 1
    myList2.addLast(3);
    myList2.print();                      // 2 0 1 3
    myList2.reverse();
    myList2.print();                      // 3 1 0 2
    myList2.addLast(4);
    myList2.print();                      // 3 1 0 2 4
    myList2.reverse();
    myList2.print();                      // 4 2 0 1 3

    cout << endl;

    myList2.shift(1);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(0);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(2);
    myList2.print();                       // 1 3 4 2 0
    myList2.shift(3);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(4);
    myList2.print();                       // 4 2 0 1 3
    myList2.shift(5);
    myList2.print();                       // 4 2 0 1 3
    myList2.shift(50);
    myList2.print();                       // 4 2 0 1 3
    myList2.shift(51);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(-1);
    myList2.print();                       // 4 2 0 1 3
    myList2.shift(-2);
    myList2.print();                       // 1 3 4 2 0
    myList2.shift(-3);
    myList2.print();                       // 4 2 0 1 3
    myList2.shift(-4);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(-5);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(-50);
    myList2.print();                       // 2 0 1 3 4
    myList2.shift(-51);
    myList2.print();                       // 4 2 0 1 3

    LinkedList<int> myList3;
    myList3.shift(0);
    myList3.print();                       //
    myList3.addLast(0);
    myList3.shift(1);
    myList3.print();                       // 0
    myList3.addLast(2);
    myList3.print();                       // 0 2
    myList3.shift(2);
    myList3.print();                       // 0 2
    myList3.addLast(1);
    myList3.shift(0);
    myList3.print();                       // 0 2 1
    myList3.shift(1);
    myList3.print();                       // 2 1 0
    myList3.shift(-1);
    myList3.print();                       // 0 2 1
    myList3.shift(2);
    myList3.print();                       // 1 0 2

    cout << "list1 = ";
    myList.print();                        // 0
    cout << "list2 = ";
    myList2.print();                       // 4 2 0 1 3
    cout << "list3 = ";
    myList3.print();                       // 1 0 2

    myList += myList2;
    myList.print();                        // 0 4 2 0 1 3

    LinkedList<int> myList4;
    myList4 = myList2;
    myList4.print();                       // 4 2 0 1 3
    cout << myList4.getSize() << endl;     // 5

    myList4.set(99, 2);
    myList4.print();                       // 4 2 99 1 3

    myList4.set(91, 4);
    myList4.print();                       // 4 2 99 1 91

    myList4.set(92, 0);
    myList4.print();                       // 92 2 99 1 91

    cout << endl;

    LinkedList<int> myList5;
    myList5.addLast(0);
    myList5.print();                       // 0

    myList5.set(1, 0);
    myList5.print();                       // 1

    myList5.addLast(2);
    myList5.print();                       // 1 2

    myList5.set(3, 0);
    myList5.print();                       // 3 2

    myList5.set(4, 1);
    myList5.print();                       // 3 4

    return 0;
}