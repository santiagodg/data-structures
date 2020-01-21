#include<iostream>
using namespace std;

#include "stack.h"

int main()
{
    stack<string> miPila;
    
    miPila.push("A");
    miPila.push("B");
    miPila.push("C");
    miPila.push("D");
    miPila.push("E");
    miPila.push("F");

    cout << "Tamano de la pila: " << miPila.size() << endl;

    while (!miPila.empty())
    {
        cout << miPila.top() << " ";
        miPila.pop();
    }
    cout << endl;

    cout << "Tamano de la pila: " << miPila.size() << endl;

    return 0;
}