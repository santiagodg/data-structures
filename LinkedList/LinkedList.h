#include<iostream>
using namespace std;

#include "Node.h"

template <class T>
class LinkedList
{
    private:
        Node<T> *head;
        int size;
        void deleteHelper();

    public:
        LinkedList();
        LinkedList(LinkedList<T> &list2);
        ~LinkedList();

        bool add(T data, int pos);
        void addFirst(T data);
        void addLast(T data);
        bool change(int pos1, int pos2);
        void del(int pos);
        int deleteAll();
        void deleteFirst();
        void deleteLast();
        T get(int pos);
        int getSize();
        bool isEmpty();
        void print();
        void reverse();
        T set(T data, int pos);

        bool operator==(LinkedList<T> &list2);
        LinkedList<T>& operator+=(T data);
        LinkedList<T>& operator+=(LinkedList<T> &list2);
        LinkedList<T>& operator=(LinkedList<T> &list2);
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T> &list2)
{
    this->head = NULL;
    this->size = 0;
    if (!list2.isEmpty())
    {
        Node<T> *curr1 = this->head;
        Node<T> *curr2 = list2.head;
        while (curr2 != NULL)
        {
            curr1->setNext(new Node<T>(curr2->getData()));
            this->size++;
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    deleteHelper();
}

template<class T>
bool LinkedList<T>::add(T data, int pos)
{
    if (pos > size)
    {
        return false;
    }
    if (pos == 0)
    {
        this->addFirst(data);
    }
    else if (pos == size)
    {
        addLast(data);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
    if (isEmpty())
    {
        this->addFirst(data);
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != NULL)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    Node<T> *previous, *temp, *curr, *posterior;
    int iTemp, i;
    if (pos1 == pos2) return true;
    if (pos1 > pos2)
    {
        iTemp = pos1;
        pos1 = pos2;
        pos2 = iTemp;
    }
    curr = head;
    for (i = 0; i < pos1 - 1; i++)
    {
        curr = curr->getNext();
    }
    previous = curr;
    temp = curr->getNext();
    for (i = 0; i < pos2 - pos1; i++)
    {
        curr = curr->getNext();
    }
    posterior = curr->getNext()->getNext();
    previous->setNext(curr->getNext());
    curr->getNext()->setNext(temp->getNext());
    curr->setNext(temp);
    temp->setNext(posterior);
    return true;
}

template<class T>
void LinkedList<T>::del(int pos)
{
    if (pos < size)
    {
        if (pos == 0)
        {
            deleteFirst();
        }
        else if (pos == size - 1)
        {
            deleteLast();
        }
        else
        {
            Node<T> *curr = head;
            for (int i = 0; i < pos - 1; i++)
            {
                curr = curr->getNext();
            }
            Node<T> *temp = curr->getNext();
            curr->setNext(temp->getNext());
            delete temp;
            size--;
        }
    }
}

template<class T>
int LinkedList<T>::deleteAll()
{
    int cant = size;
    deleteHelper();
    size = 0;
    return cant;
}

template<class T>
void LinkedList<T>::deleteFirst()
{
    if (!this->isEmpty())
    {
        Node<T> *curr = head;
        head = head->getNext();
        size--;
    }
}

template<class T>
void LinkedList<T>::deleteHelper()
{
    Node<T> *curr = head;
    while (!this->isEmpty())
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (size < 2)
    {
        this->deleteFirst();
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != NULL)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
        size--;
    }
}

template <class T>
T LinkedList<T>::get(int pos)
{
    Node<T> *curr;
    curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}


template <class T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template<class T>
void LinkedList<T>::print()
{
    Node<T> *curr = head;
    while (curr != NULL)
    {
        cout << curr->getData() << " ";
        curr = curr->getNext();
    }
    cout << endl;
}

template<class T>
void LinkedList<T>::reverse()
{
    Node<T> *curr = head, *prev = NULL, *next;
    while (curr != NULL)
    {
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<class T>
T LinkedList<T>::set(T data, int pos)
{
    Node<T> *curr;
    T previousData;
    curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
    }
    previousData = curr->getData();
    curr->setData(data);
    return previousData;
}

template<class T>
bool LinkedList<T>::operator==(LinkedList<T> &list2)
{
    if (this->isEmpty() && list2.isEmpty()) return true;
    if (this->size != list2.size) return false;

    Node<T> *curr1 = this->head, *curr2 = list2.head;
    for (int i = 0; i < this->size; i++)
    {
        if (curr1->getData() != curr2->getData())
        {
            return false;
        }
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
    return true;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+=(T data)
{
    this->addLast(data);
    return *this;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+=(LinkedList<T> &list2)
{
    if (list2.isEmpty()) return *this;
    Node<T> *curr1 = this->head;
    while (curr1->getNext() != NULL)
    {
        curr1 = curr1->getNext();
    }

    Node<T> *curr2 = list2.head;
    while (curr2 != NULL)
    {
        curr1->setNext(new Node<T>(curr2->getData()));
        this->size++;
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
    return *this;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &list2)
{
    this->deleteAll();
    return *this += list2;
}
