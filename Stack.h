#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <exception>

#include "Node.h"

template <class T>
class Stack
{
private:

    Node<T>* Top;

    unsigned Size;

public:

    Stack();
    ~Stack();

    unsigned Count();

    bool Empty();

    void Push(T&);
    void Pop();

    void Clear();

    T& GetTop();

    void Print();
};

template <class T>
inline Stack<T>::Stack()
{
    this->Top = new Node<T>();

    if (this->Top == nullptr) { throw std::exception(); }

    this->Top->SetNext(this->Top);
    this->Top->SetPrev(this->Top);

    this->Size = 0;
}

template <class T>
inline Stack<T>::~Stack()
{
    this->Clear();
}

template <class T>
inline unsigned Stack<T>::Count()
{
    return this->Count;
}

template <class T>
inline bool Stack<T>::Empty()
{
    return this->Top->GetNext() == this->Top;
}

template <class T>
inline void Stack<T>::Push(T& Data)
{
    Node<T>* Front = this->Top;

    Node<T>* Aux;

    try { Aux = new Node<T>(Data); } catch (std::exception Exception) { throw Exception.what(); }

    if (Aux == nullptr) { throw std::exception(); }

    Aux->SetPrev(Front);
    Aux->SetNext(Front->GetNext());

    Front->GetNext()->SetPrev(Aux);
    Front->SetNext(Aux);

    this->Size++;
}

template <class T>
inline void Stack<T>::Pop()
{
    Node<T>* Front;

    if (this->Empty()) {
        Front = this->Top;
    } else {
        Front = this->Top->GetNext();
    }

    Front->GetPrev()->SetNext(Front->GetNext());
    Front->GetNext()->SetPrev(Front->GetPrev());

    this->Size--;

    delete Front;
}

template <class T>
inline T& Stack<T>::GetTop()
{
    return this->Top->GetNext()->GetData();
}

template <class T>
inline void Stack<T>::Clear()
{
    Node<T>* Aux = nullptr;

    while (this->Top->GetNext() != this->Top) {
        Aux = this->Top->GetNext();
        this->Top->SetNext(this->Top->GetNext()->GetNext());
        delete Aux;
    }

    this->Top->SetPrev(this->Top);
    this->Size = 0;
}

template <class T>
inline void Stack<T>::Print()
{
    Node<T>* Aux = this->Top->GetNext();

    while (Aux != this->Top) {
        std::cout << "\t " << Aux->GetData() << std::endl;
        Aux = Aux->GetNext();
    }
}

#endif // STACK_H_INCLUDED
