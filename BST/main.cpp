#include <queue>
#include <iostream>
using namespace std;

#include "BST.h"

/*
               10
              /  \
             /    \
            /      \
           /        \
          /          \
         5           20
        / \         /  \
       /   \       /    \
      /     \     /      \
     2       8   17      30
      \         /  \    /
       3       12  19  25
                  /
                 18
*/

int main() {
  BST arbol;

  arbol.add(10);
  arbol.add(5);
  arbol.add(2);
  arbol.add(3);
  arbol.add(8);
  arbol.add(20);
  arbol.add(17);
  arbol.add(12);
  arbol.add(19);
  arbol.add(18);
  arbol.add(30);
  arbol.add(25);

  cout << "preOrder: ";
  arbol.print(1);
  cout << "inOrder: ";
  arbol.print(2);
  cout << "postOrder: ";
  arbol.print(3);

  cout << "search(20): " << arbol.search(20) << endl;
  cout << "search(25): " << arbol.search(25) << endl;
  cout << "search(99): " << arbol.search(99) << endl;

  /*
  arbol.remove(25);
  cout << "search(25): " << arbol.search(25) << endl;
  cout << endl;
  */

  cout << "height: " << arbol.height() << endl;

  cout << "ancestors(18): ";
  arbol.ancestors(18);

  cout << "ancestors(3): ";
  arbol.ancestors(3);
  cout << endl;

  cout << "whatLevelamI(18): " << arbol.whatLevelamI(18) << endl;
  cout << "whatLevelamI(12): " << arbol.whatLevelamI(12) << endl;
  cout << "whatLevelamI(17): " << arbol.whatLevelamI(17) << endl;
  cout << "whatLevelamI(2): " << arbol.whatLevelamI(2) << endl;
  cout << "whatLevelamI(20): " << arbol.whatLevelamI(20) << endl;
  cout << "whatLevelamI(10): " << arbol.whatLevelamI(10) << endl;
  cout << "whatLevelamI(11): " << arbol.whatLevelamI(11) << endl;
  cout << endl;

  cout << "print(5) (nivelXnivel): ";
  arbol.print(5);
  cout << endl;

  cout << "maxWidth: " << arbol.maxWidth() << endl;
  arbol.remove(2);
  arbol.remove(3);
  arbol.remove(25);
  cout << "maxWidth: " << arbol.maxWidth() << endl;
  arbol.remove(8);
  cout << "maxWidth: " << arbol.maxWidth() << endl;

  /*
  cout << "nearstRelative(5, 20): " << arbol.nearstRelative(5, 20) << endl;
  cout << "nearstRelative(8, 2): " << arbol.nearstRelative(8, 2) << endl;
  cout << "nearstRelative(18, 19): " << arbol.nearstRelative(18, 19) << endl;
  cout << "nearstRelative(10, 20): " << arbol.nearstRelative(10, 20) << endl;
  cout << "nearstRelative(3, 25): " << arbol.nearstRelative(3, 25) << endl;
  cout << "nearstRelative(25, 18): " << arbol.nearstRelative(25, 18) << endl;
  cout << endl;

  BST arbol2(arbol);
  cout << "arbol1.preOrder(): ";
  arbol.print(1);
  cout << "arbol2.preOrder(): ";
  arbol2.print(1);
  cout << "arbol1.inOrder(): ";
  arbol.print(2);
  cout << "arbol2.inOrder(): ";
  arbol2.print(2);
  cout << "arbol1.postOrder(): ";
  arbol.print(3);
  cout << "arbol2.postOrder(): ";
  arbol2.print(3);
  cout << endl;

  cout << "arbol1 == arbol2: " << (arbol == arbol2 ? "true" : "false") << endl;
  arbol.add(4);
  cout << "added 4 into arbol1." << endl;
  cout << "arbol1 == arbol2: " << (arbol == arbol2 ? "true" : "false") << endl;
  arbol.remove(4);
  cout << "removed 4 from arbol1." << endl;
  cout << "arbol1 == arbol2: " << (arbol == arbol2 ? "true" : "false") << endl;
  arbol.remove(17);
  cout << "removed 17 from arbol1." << endl;
  cout << "arbol1 == arbol2: " << (arbol == arbol2 ? "true" : "false") << endl;

  queue<int> qiu;

  qiu = arbol.toQueue();
  cout << "toQueue: ";
  while (!qiu.empty()) {
    cout << qiu.front() << " ";
    qiu.pop();
  }
  cout << endl;
  */

  return 0;
}
