#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

#include "Node.h"

template <class T>
class Stack
{
private:

    Node<T>* Top;

    unsigned int Count;

    void DeleteAll();

public:

    Stack();
    Stack(Stack&);
    ~Stack();

    void Push(T&);
    void Pop();

    T& GetTop();
    unsigned int GetCount();
};

template <class T>
void Stack<T>::DeleteAll()
{

}

template <class T>
Stack<T>::Stack()
{
    this->Top = nullptr;
    this->Count = 0;
}

template <class T>
Stack<T>::Stack(Stack&)
{

}

template <class T>
Stack<T>::~Stack()
{
    DeleteAll();
}

template <class T>
void Stack<T>::Push(T& Value)
{

}

template <class T>
void Stack<T>::Pop()
{

}

template <class T>
T& Stack<T>::GetTop()
{

}

template <class T>
unsigned int Stack<T>::GetCount()
{
    return this->Count;
}

#endif // STACK_H_INCLUDED
