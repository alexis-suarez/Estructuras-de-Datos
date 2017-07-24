#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <exception>

#include "Node.h"

template <class T>
class List
{
private:

    Node<T>* Header;

    unsigned Size;

    bool ValidPosition(Node<T>*);

public:

    List();
    List(List&);
    ~List();

    unsigned Count();

    bool Empty();
    bool Contains(T&);

    Node<T>* Insert(Node<T>*, T&);
    Node<T>* Insert(T&);
    void Append(Node<T>*, T&);
    void Append(T&);
    void Push_Back(T&);
    void Push_Front(T&);
    void Enqueue(T&);

    void Delete(Node<T>*);
    void Delete(T&);
    void Clear();
    void Pop_Back();
    void Pop_Front();
    void Dequeue();

    Node<T>* FirstPos();
    Node<T>* LastPos();
    Node<T>* NextPos(Node<T>*);
    Node<T>* PrevPos(Node<T>*);
    Node<T>* Find(T&);

    T& Retrieve(Node<T>*);
    T& Retrieve(T&);
    T& Top();
    T& Bottom();
    T& Front();

};

template <class T>
inline bool List<T>::ValidPosition(Node<T>* Pointer)
{
    Node<T>* Aux = this->Header->GetNext();

    while (Aux != this->Header) {
        if (Aux == Pointer) { return true; }
        Aux = Aux->GetNext();
    }

    return false;
}

template <class T>
inline List<T>::List()
{
    this->Header = new Node<T>();

    if (this->Header == nullptr) { throw std::exception(); }

    this->Header->SetNext(this->Header);
    this->Header->SetPrev(this->Header);

    this->Size = 0;
}

template <class T>
inline List<T>::List(List& List)
{
    this->Clear();

    Node<T>* Aux = List.Header;

    while (Aux != this->Header) {
        this->Append(Aux->GetData());
        Aux = Aux->GetNext();
    }

    *this = List;
}

template <class T>
inline List<T>::~List()
{
    this->Clear();
}

template <class T>
inline unsigned List<T>::Count()
{
    return this->Size;
}

template <class T>
inline bool List<T>::Empty()
{
    return this->Header->GetNext() == this->Header;
}

template <class T>
inline bool List<T>::Contains(T& Data)
{
    Node<T>* Aux = this->Header;

    while (Aux != this->Header) {
        if (Aux->GetData() == Data){ return true; }
        Aux = Aux->GetNext();
    }

    return false;
}

template <class T>
inline Node<T>* List<T>::Insert(Node<T>* Pointer, T& Data)
{
    if (Pointer != nullptr && !this->ValidPosition(Pointer)) { throw std::exception(); }

    if (Pointer == nullptr) { Pointer = this->Header; }

    Node<T>* Aux;

    try { Aux = new Node<T>(Data); } catch (std::exception Exception) { throw Exception.what(); }

    if (Aux == nullptr) { throw std::exception(); }

    Aux->SetPrev(Pointer);
    Aux->SetNext(Pointer->GetNext());

    Pointer->GetNext()->SetPrev(Aux);
    Pointer->SetNext(Aux);

    this->Size++;

    return Aux;
}

template <class T>
inline Node<T>* List<T>::Insert(T& Data)
{
    Node<T>* Aux = this->Insert(this->LastPos, Data);
    return Aux;
}

template <class T>
inline void List<T>::Append(Node<T>* Pointer, T& Data)
{
    if (Pointer != nullptr && !this->ValidPosition(Pointer)) { throw std::exception(); }

    if (Pointer == nullptr) { Pointer = this->Header; }

    Node<T>* Aux;

    try { Aux = new Node<T>(Data); } catch (std::exception Exception) { throw Exception.what(); }

    if (Aux == nullptr) { throw std::exception(); }

    Aux->SetPrev(Pointer);
    Aux->SetNext(Pointer->GetNext());

    Pointer->GetNext()->SetPrev(Aux);
    Pointer->SetNext(Aux);

    this->Size++;
}

template <class T>
inline void List<T>::Append(T& Data)
{
    this->Append(this->LastPos(), Data);
}

template <class T>
inline void List<T>::Push_Back(T& Data)
{
    this->Append(this->LastPos(), Data);
}

template <class T>
inline void List<T>::Push_Front(T& Data)
{
    this->Append(this->FirstPos(), Data);
}

template <class T>
inline void List<T>::Enqueue(T& Data)
{
    this->Append(this->LastPos(), Data);
}

template <class T>
inline void List<T>::Delete(Node<T>* Pointer)
{
    if (!this->ValidPosition(Pointer)) { throw std::exception(); }

    Pointer->GetPrev()->SetNext(Pointer->GetNext());
    Pointer->GetNext()->SetPrev(Pointer->GetPrev());

    this->Count--;

    delete Pointer;
}

template <class T>
inline void List<T>::Delete(T& Data)
{
    this->Delete(this->Find(Data));
}

template <class T>
inline void List<T>::Clear()
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
inline void List<T>::Pop_Back()
{
    this->Delete(this->LastPos());
}

template <class T>
inline void List<T>::Pop_Front()
{
    this->Delete(this->FirstPos());
}

template <class T>
inline void List<T>::Dequeue()
{
    this->Delete(this->FirstPos());
}

template <class T>
inline Node<T>* List<T>::FirstPos()
{
    if (this->Empty()) { return nullptr; }

    return this->Header->GetNext();
}

template <class T>
inline Node<T>* List<T>::LastPos()
{
    if (this->Empty()) { return nullptr; }

    return this->Header->GetPrev();
}

template <class T>
inline Node<T>* List<T>::NextPos(Node<T>* Pointer)
{
    if (Pointer == this->Header->GetPrev() || !this->ValidPosition(Pointer)) { return nullptr; }

    if (Pointer->GetNext() == this->Header) { return this->Header->GetNext(); }

    return Pointer->GetNext();
}

template <class T>
inline Node<T>* List<T>::PrevPos(Node<T>* Pointer)
{
    if (Pointer == this->Header->GetNext() || !this->ValidPosition(Pointer)) { return nullptr; }

    if (Pointer->GetPrev() == this->Header) { return this->Header->GetPrev(); }

    return Pointer->GetPrev();
}

template <class T>
inline Node<T>* List<T>::Find(T& Data)
{
    Node<T>* Aux = this->Header->GetNext();

    while (Aux != this->Header) {
        if (Aux->GetData() == Data) { return Aux; }
        Aux = Aux->GetNext();
    }

    return nullptr;
}

template <class T>
inline T& List<T>::Retrieve(Node<T>* Pointer)
{
    if (!this->ValidPosition(Pointer)) { throw std::exception(); }

    return Pointer->GetData();
}

template <class T>
inline T& List<T>::Retrieve(T& Data)
{
    return this->Retrieve(this->Find(Data));
}

template <class T>
inline T& List<T>::Top()
{
    if(this->Empty()) { throw std::exception(); }

    return this->Retrieve(this->FirstPos());
}

template <class T>
inline T& List<T>::Bottom()
{
    if(this->Empty()) { throw std::exception(); }

    return this->Retrieve(this->LastPos());
}

template <class T>
inline T& List<T>::Front()
{
    if(this->Empty()) { throw std::exception(); }

    return this->Retrieve(this->FirstPos());
}

#endif // LIST_H_INCLUDED
