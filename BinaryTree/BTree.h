#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <string>
#include <exception>

#include "Node.h"

template <class T>
class BTree
{
private:

    Node<T>* Root;

    unsigned Weight(Node<T>*&);

    void Insert(Node<T>*&, T&);

    Node<T>*& Find(Node<T>*&, T&);

    Node<T>*& GetTheMayor(Node<T>*&);
    Node<T>*& GetTheMinor(Node<T>*&);

    void Inorder(Node<T>*);
    void Preorder(Node<T>*);
    void Postorder(Node<T>*);

    void Clear(Node<T>*&);

public:

    BTree();
    ~BTree();

    unsigned Weight();

    bool IsEmpty();
    bool IsLeaf(Node<T>*&);

    void Insert(T&);
    void Delete(Node<T>*&);

    Node<T>*& Find(T&);

    T& Retrieve(Node<T>*);

    void Inorder();
    void Preorder();
    void Postorder();

    void Clear();

};

template <class T>
inline Node<T>*& BTree<T>::GetTheMayor(Node<T>*& Pointer)
{
    if (Pointer->GetRight() == nullptr or Pointer == nullptr) { return Pointer; }

    return this->GetTheMayor(Pointer->GetRight());
}

template <class T>
inline Node<T>*& BTree<T>::GetTheMinor(Node<T>*& Pointer)
{
    if (Pointer->GetLeft() == nullptr or Pointer == nullptr) { return Pointer; }

    return this->GetTheMinor(Pointer->GetLeft());
}

template <class T>
inline BTree<T>::BTree()
{
    this->Root = nullptr;
}

template <class T>
inline BTree<T>::~BTree()
{
    this->Clear();
}

template <class T>
inline unsigned BTree<T>::Weight()
{
    return this->Weight(this->Root);
}

template <class T>
inline unsigned BTree<T>::Weight(Node<T>*& Pointer)
{
    if (Pointer == nullptr) { return 0;}

    unsigned LHeight = this->Weight(Pointer->GetLeft());
    unsigned RHeight = this->Weight(Pointer->GetRight());

    return 1 + (LHeight > RHeight ? LHeight : RHeight);
}

template <class T>
inline bool BTree<T>::IsEmpty()
{
    return this->Root == nullptr;
}

template <class T>
inline bool BTree<T>::IsLeaf(Node<T>*& Pointer)
{
    return (Pointer->GetLeft() == nullptr and Pointer->GetRight() == nullptr);
}

template <class T>
inline void BTree<T>::Insert(T& Data)
{
    this->Insert(this->Root, Data);
}

template <class T>
inline void BTree<T>::Insert(Node<T>*& Pointer, T& Data)
{
    if (Pointer == nullptr) {

        Pointer = new Node<T>(Data);
    } else {
    std::cout << Pointer->GetInfo() << std::endl;
        if (Data < Pointer->GetInfo()) {
            Insert(Pointer->GetLeft(), Data);
            std::cout << "izq" << std::endl;
        } else {
            Insert(Pointer->GetRight(), Data);
            std::cout << "der" << std::endl;
        }
    }
}

template <class T>
inline void BTree<T>::Delete(Node<T>*& Pointer)
{
    if (Pointer == nullptr) { return; }

    if (this->IsLeaf(Pointer)) {
        delete Pointer;
        Pointer = nullptr;
    } else {
        Node<T>* Aux;

        if (Pointer->GetLeft() != nullptr) {
            Aux = this->GetTheMayor(Pointer->GetLeft());
        } else {
            Aux = this->GetTheMinor(Pointer->GetRight());
        }

        Pointer->SetInfoPtr(Aux->GetInfoPtr());

        this->Delete(Aux);
    }
}

template <class T>
inline Node<T>*& BTree<T>::Find(T& Data)
{
    return this->Find(this->Root, Data);
}

template <class T>
inline Node<T>*& BTree<T>::Find(Node<T>*& Pointer, T& Data)
{
    if (Pointer == nullptr) { return nullptr; }

    if (Pointer->GetInfo() == Data) { return Pointer; }

    if (Data < Pointer->GetInfo()) {
        return this->Find(Pointer->GetLeft(), Data);
    } else {
        return this->Find(Pointer->GetRight(), Data);
    }
}

template <class T>
inline T& BTree<T>::Retrieve(Node<T>* Pointer)
{
    if (this->Root == nullptr and Pointer == nullptr) { throw std::exception(); }

    return Pointer->GetInfo();
}

template <class T>
inline void BTree<T>::Inorder()
{
    this->Inorder(this->Root);
}

template <class T>
inline void BTree<T>::Inorder(Node<T>* Pointer)
{
    if (Pointer == nullptr) { return; }

    this->Inorder(Pointer->GetLeft());
    std::cout << Pointer->GetInfo() << ", ";
    this->Inorder(Pointer->GetRight());
}

template <class T>
inline void BTree<T>::Preorder()
{
    this->Preorder(this->Root);
}

template <class T>
inline void BTree<T>::Preorder(Node<T>* Pointer)
{
    if (Pointer == nullptr) { return; }

    std::cout << Pointer->GetInfo() << ", ";
    this->Preorder(Pointer->GetLeft());
    this->Preorder(Pointer->GetRight());
}

template <class T>
inline void BTree<T>::Postorder()
{
     this->Postorder(this->Root);
}

template <class T>
inline void BTree<T>::Postorder(Node<T>* Pointer)
{
    if (Pointer == nullptr) { return; }

    this->Postorder(Pointer->GetLeft());
    this->Postorder(Pointer->GetRight());
    std::cout << Pointer->GetInfo() << ", ";
}

template <class T>
inline void BTree<T>::Clear()
{
    this->Clear(this->Root);

    this->Root = nullptr;
}

template <class T>
inline void BTree<T>::Clear(Node<T>*& Pointer)
{
    if (Pointer == nullptr) { return; }

    this->Delete(Pointer->GetLeft());
    this->Delete(Pointer->GetRight());

    delete Pointer;
}

#endif // BTREE_H_INCLUDED
