#include "Node.h"

template<class T>
class stack
{
    private:
        Node<T> *tope;
        int tamano;

    public:
        stack();
        ~stack();

        void push(T data);
        void pop();
        T top();
        bool empty();
        int size();
};

template<class T>
stack<T>::stack()
{
    tope = NULL;
    tamano = 0;
}

template<class T>
stack<T>::~stack()
{
    Node<T> *curr = tope;
    while (tope != NULL)
    {
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

template<class T>
void stack<T>::push(T data)
{
    tope = new Node<T>(data, tope);
    tamano++;
}

template<class T>
void stack<T>::pop()
{
    Node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    tamano--;
}

template<class T>
T stack<T>::top()
{
    return tope->getData();
}

template<class T>
bool stack<T>::empty()
{
    return tope == NULL;
}

template<class T>
int stack<T>::size()
{
    return tamano;
}

