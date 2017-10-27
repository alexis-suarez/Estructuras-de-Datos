#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <exception>

template <class T>
class Node
{
private:

    T* Info;

    Node<T>* Left;
    Node<T>* Right;

public:

    Node();
    Node(T&);
    ~Node();

    T& GetInfo();
    T*& GetInfoPtr();

    Node<T>*& GetLeft();
    Node<T>*& GetRight();

    void SetInfo(T&);
    void SetInfoPtr(T*&);

    void SetLeft(Node<T>*);
    void SetRight(Node<T>*);

};

template <class T>
inline Node<T>::Node()
{
    this->Info = nullptr;
    this->Left = nullptr;
    this->Right = nullptr;
}

template <class T>
inline Node<T>::Node(T& Info)
{
    this->Info = new T(Info);

    if (this->Info == nullptr) { throw std::exception(); }

    this->Left = nullptr;
    this->Right = nullptr;
}

template <class T>
inline Node<T>::~Node()
{
    delete this->Info;
}

template <class T>
inline T& Node<T>::GetInfo()
{
    if (this->Info == nullptr) { throw std::exception(); }

    return *this->Info;
}

template <class T>
inline T*& Node<T>::GetInfoPtr()
{
    return this->Info;
}

template <class T>
inline Node<T>*& Node<T>::GetLeft()
{
    return this->Left;
}

template <class T>
inline Node<T>*& Node<T>::GetRight()
{
    return this->Right;
}

template <class T>
inline void Node<T>::SetInfo(T& Info)
{
    if (this->Info == nullptr) {
        this->Info = new T(Info);

        if (this->Info == nullptr) {
            throw std::exception();
        }
    } else {
        *this->Info = Info;
    }
}

template <class T>
inline void Node<T>::SetInfoPtr(T*& Pointer)
{
    if (this->Info != Pointer) { delete this->Info; }

    this->Info = Pointer;
}

template <class T>
inline void Node<T>::SetLeft(Node<T>* Pointer)
{
    this->Left = Pointer;
}

template <class T>
inline void Node<T>::SetRight(Node<T>* Pointer)
{
    this->Right = Pointer;
}

#endif // NODE_H_INCLUDED
