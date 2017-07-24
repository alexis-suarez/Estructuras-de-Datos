#ifndef LISTARRAY_H_INCLUDED
#define LISTARRAY_H_INCLUDED

#include <iostream>

template <class T, int ListSize>
class List
{
private:

    T Data[ListSize]
    unsigned Last;
    unsigned Size;

public:

    List();
    List(List&);
    ~List();

    unsigned Count();

    bool IsEmpty();
    bool IsFull();
    bool Contains(T&);

    void Insert(int, T&);
    void Insert(T&);
    void Push_Back(T&);
    void Push_Front(T&);
    void Enqueue(T&);

    void Delete(int);
    void Delete(T&);
    void Clear();
    void Pop_Back();
    void Pop_Front();
    void Dequeue();

    int FirstPos();
    int LastPos();
    int PrevPos(int);
    int NextPos(int);
    int Find(T&);

    T& Retrieve(int);
    T& Retrieve(T&);
    T& Top();
    T& Bottom();
    T& Front();

};

#endif // ARRAYLIST_H_INCLUDED