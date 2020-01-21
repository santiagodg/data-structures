#include<iostream>
using namespace std;

#include "Node.h"

template<class T>
class LinkedList
{
    private:
        Node<T> *head;
        int      size;
        void     deleteHelper();

    public:
        LinkedList();
        LinkedList(const LinkedList<T> &list2);
        ~LinkedList();

        bool add(T data, int pos);
        void addFirst(T data);
        void addLast(T data);
        bool change(int pos1, int pos2);
        void del(int pos);
        int  deleteAll();
        void deleteFirst();
        void deleteLast();
        T    get(int pos) const;
        int  getSize() const ;
        bool isEmpty() const;
        void print() const;
        void reverse();
        T    set(T data, int pos);
        void shift(int casillas);

        bool operator==(const LinkedList<T> &list2) const;
        void operator+=(T data);
        void operator+=(const LinkedList<T> &list2);
        void operator=(const LinkedList<T> &list2);
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list2)
{
    this->head = NULL;
    this->size = 0;
    if (!list2.isEmpty())
    {
        Node<T> *curr1, *curr2 = list2.head;
        this->addFirst(curr2->getData());
        curr1 = this->head;
        curr2 = curr2->getNext();
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

template<class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template<class T>
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

template<class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    if (pos1 == pos2)
    {
        return true;
    }

    int max = (pos1 > pos2 ? pos1 : pos2);
    int min = (pos1 < pos2 ? pos1 : pos2);

    Node<T> *curr1 = head;
    for (int i = 0; i < min; i++)
    {
        curr1 = curr1->getNext();
    }

    Node<T> *curr2 = curr1;
    for (int i = min; i < max; i++)
    {
        curr2 = curr2->getNext();
    }

    T prev = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(prev);

    return true;

    /*
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
    */
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

template<class T>
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

template<class T>
T LinkedList<T>::get(int pos) const
{
    Node<T> *curr;
    curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

template<class T>
int LinkedList<T>::getSize() const
{
    return size;
}


template<class T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0 || head == NULL;
}

template<class T>
void LinkedList<T>::print() const
{
    if (!this->isEmpty())
    {
        Node<T> *curr = head;
        while (curr != NULL && curr->getNext() != NULL)
        {
            cout << curr->getData() << " ";
            curr = curr->getNext();
        }
        cout << curr->getData();
    }
    cout << endl;
}

template<class T>
void LinkedList<T>::reverse()
{
    if (size > 1)
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
void LinkedList<T>::shift(int casillas)
{
    if (this->isEmpty()) return;
    int shifts = casillas >= 0 ? casillas % size : ((casillas % size) + size) % size;
    if (size > 1 && shifts > 0)
    {
        Node<T> *prev;
        prev = head;
        while (prev->getNext() != NULL)
        {
            prev = prev->getNext();
        }
        prev->setNext(head);
        for (int i = 0; i < shifts; i++)
        {
            prev = head;
            head = head->getNext();
        }
        prev->setNext(NULL);
    }
}

template<class T>
void LinkedList<T>::operator+=(T data)
{
    this->addLast(data);
}

template<class T>
void LinkedList<T>::operator+=(const LinkedList<T> &rhs)
{
    if (rhs.isEmpty()) return;
    if (this->isEmpty()) *this = rhs;

    Node<T> *curr1 = this->head, *curr2 = rhs.head;
    while (curr1->getNext() != NULL)
    {
        curr1 = curr1->getNext();
    }
    while (curr2 != NULL)
    {
        curr1->setNext(new Node<T>(curr2->getData()));
        this->size++;
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
}

template<class T>
void LinkedList<T>::operator=(const LinkedList<T> &list2)
{
    this->deleteAll();
    if (!list2.isEmpty())
    {
        Node<T> *curr1, *curr2 = list2.head;
        this->addFirst(curr2->getData());
        curr1 = this->head;
        curr2 = curr2->getNext();
        while (curr2 != NULL)
        {
            curr1->setNext(new Node<T>(curr2->getData()));
            this->size++;
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
    }
}
