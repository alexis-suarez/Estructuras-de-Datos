#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <exception>

#include "Node.h"

template <class T>
class Queue
{
private:

    Node<T>* Header;

    unsigned Size;

public:

    Queue();
    ~Queue();

    unsigned Count();

    bool Empty();

    void Enqueue(T&);

    void Dequeue();
    void Clear();

    T& Front();
    void Print();
};

template <class T>
inline Queue<T>::Queue()
{
    this->Header = new Node<T>();

    if (this->Header == nullptr) { throw std::exception(); }

    this->Header->SetNext(this->Header);
    this->Header->SetPrev(this->Header);

    this->Size = 0;
}

template <class T>
inline Queue<T>::~Queue()
{
    this->Clear();
}

template <class T>
inline unsigned Queue<T>::Count()
{
    return this->Size;
}

template <class T>
inline bool Queue<T>::Empty()
{
    return this->Header->GetNext() == this->Header;
}

template <class T>
inline void Queue<T>::Enqueue(T& Data)
{
    Node<T>* Back;

    if (this->Empty()) {
        Back = this->Header;
    } else {
        Back = this->Header->GetPrev();
    }

    Node<T>* Aux;

    try { Aux = new Node<T>(Data); } catch (std::exception Exception) { throw Exception.what(); }

    if (Aux == nullptr) { throw std::exception(); }

    Aux->SetPrev(Back);
    Aux->SetNext(Back->GetNext());

    Back->GetNext()->SetPrev(Aux);
    Back->SetNext(Aux);

    this->Size++;
}

template <class T>
inline void Queue<T>::Dequeue()
{
    Node<T>* Front;

    if (this->Empty()) {
        Front = this->Header;
    } else {
        Front = this->Header->GetNext();
    }

    Front->GetPrev()->SetNext(Front->GetNext());
    Front->GetNext()->SetPrev(Front->GetPrev());

    this->Size--;

    delete Front;
}

template <class T>
inline void Queue<T>::Clear()
{
    Node<T>* Aux = nullptr;

    while (this->Header->GetNext() != this->Header) {
        Aux = this->Header->GetNext();
        this->Header->SetNext(this->Header->GetNext()->GetNext());
        delete Aux;
    }

    this->Header->SetPrev(this->Header);
    this->Size = 0;
}

template <class T>
inline T& Queue<T>::Front()
{
    return this->Header->GetNext()->GetData();
}

template <class T>
inline void Queue<T>::Print()
{
    Node<T>* Aux = this->Header->GetNext();

    while (Aux != this->Header) {
        std::cout << Aux->GetData() << ", ";
        Aux = Aux->GetNext();
    }
}

#endif // QUEUE_H_INCLUDED
