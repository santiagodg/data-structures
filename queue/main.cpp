#include<iostream>
using namespace std;

#include "queue.h"

int main()
{
    queue<string> miFila;
    
    miFila.push("A");
    miFila.push("B");
    miFila.push("C");
    miFila.push("D");
    miFila.push("E");
    miFila.push("F");

    cout << "Tamano de la fila: " << miFila.size() << endl;

    while (!miFila.empty())
    {
        cout << miFila.front() << " ";
        miFila.pop();
    }
    cout << endl;

    cout << "Tamano de la fila: " << miFila.size() << endl;

    return 0;
}