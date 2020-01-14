#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<string> miLista;
    miLista.addLast("A");
    miLista.addLast("B");
    miLista.addLast("C");
    miLista.addLast("D");
    miLista.addLast("E");
    miLista.print();
    miLista.reverse();
    miLista.print();
    
    return 0;
}