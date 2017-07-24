#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

#include "Node.h"

template <class T>
class Queue
{
private:

    Node<T>* Anchor;

    unsigned int Count;

public:

    Queue();
    Queue(Queue&);
    ~Queue();

    void Enqueue(T&);
    void PriorityEnqueue(T&);

    void Dequeue();

    T& GetFront();
    unsigned int GetCount();

};

#endif // QUEUE_H_INCLUDED