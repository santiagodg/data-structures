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

  return 0;
}
