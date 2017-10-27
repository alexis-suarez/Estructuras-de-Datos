#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <exception>

template <class T>
class Node
{
private:

    T* Data;

    Node<T>* Next;
    Node<T>* Prev;

public:

    Node();
    Node(T&);
    ~Node();

    T& GetData();
    T*& GetDataPtr();

    Node<T>* GetNext();
    Node<T>* GetPrev();

    void SetData(T&);
    void SetDataPtr(T*);

    void SetNext(Node<T>*);
    void SetPrev(Node<T>*);

};

template <class T>
inline Node<T>::Node()
{
    this->Data = nullptr;
    this->Next = nullptr;
    this->Prev = nullptr;
}

template <class T>
inline Node<T>::Node(T& Data)
{
    this->Data = new T(Data);

    if (this->Data == nullptr) { throw std::exception(); }
}

template <class T>
inline Node<T>::~Node()
{
    delete Data;
}

template <class T>
inline T& Node<T>::GetData()
{
    if (this->Data == nullptr) { throw std::exception(); }

    return *this->Data;
}

template <class T>
inline T*& Node<T>::GetDataPtr()
{
    return this->Data;
}

template <class T>
inline Node<T>* Node<T>::GetNext()
{
    return this->Next;
}

template <class T>
inline Node<T>* Node<T>::GetPrev()
{
    return this->Prev;
}

template <class T>
inline void Node<T>::SetData(T& Data)
{
    if (this->Data == nullptr) {
        this->Data = new T(Data);

        if (this->DataPtr == nullptr) {
            throw std::exception();
        }
    }

    else { *this->Data = Data; }
}

template <class T>
inline void Node<T>::SetDataPtr(T* Pointer)
{
    if (this->Data != Pointer) { delete this->Data; }

    this->Data = Pointer;
}

template <class T>
inline void Node<T>::SetNext(Node<T>* Pointer)
{
    this->Next = Pointer;
}

template <class T>
inline void Node<T>::SetPrev(Node<T>* Pointer)
{
    this->Prev = Pointer;
}

#endif // NODE_H_INCLUDED
