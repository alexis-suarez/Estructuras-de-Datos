#ifndef LISTARRAY_H_INCLUDED
#define LISTARRAY_H_INCLUDED

#include <iostream>
#include <exception>

template <class T, int ListSize>
class List
{
private:

    T Data[ListSize];
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

    void Print();

};

template <class T, int ListSize>
inline List<T, ListSize>::List()
{
    this->Last = -1;
    this->Size = 0;
}

template <class T, int ListSize>
inline List<T, ListSize>::List(List& List)
{
    int i = 0;

    while (i < List.Count()) {
        this->Data[i] = List.Data[i];
        i++;
    }

    this.Last = List.Last;
    this.Count = List.Count();
}

template <class T, int ListSize>
inline List<T, ListSize>::~List()
{
    this->Clear();
}

template <class T, int ListSize>
inline unsigned List<T, ListSize>::Count()
{
    return this->Size;
}

template <class T, int ListSize>
inline bool List<T, ListSize>::IsEmpty()
{
    return this->Last == - 1;
}

template <class T, int ListSize>
inline bool List<T, ListSize>::IsFull()
{
    return this->Last == ListSize - 1;
}

template <class T, int ListSize>
inline bool List<T, ListSize>::Contains(T& Value)
{
    if (!this->IsEmpty()) {
        int i = 0;

        while (i < this->Count()) {
            if (this->Data[i] == Value) {
                return true;
            }
            i++;
        }

        return false;
    }
}

template <class T, int ListSize>
inline void List<T, ListSize>::Insert(int Pos, T& Value)
{
    if (this->IsFull()) {
        throw std::exception();
    }

    if (Pos < -1 || Pos > this->Last) {
        throw std::exception();
    }

    int i = this->Last;

    while (i > Pos) {
        this->Data[i] = this->Data[i - 1];
        i--;
    }

    this->Data[Pos + 1] = Value;

    this->Last++;
    this->Size++;
}

template <class T, int ListSize>
inline void List<T, ListSize>::Insert(T& Value)
{
    this->Insert(this->LastPos(), Value);
}

template <class T, int ListSize>
inline void List<T, ListSize>::Push_Back(T& Value)
{
    this->Insert(this->LastPos(), Value);
}

template <class T, int ListSize>
inline void List<T, ListSize>::Push_Front(T& Value)
{
    this->Insert(this->FirstPos(), Value);
}

template <class T, int ListSize>
inline void List<T, ListSize>::Enqueue(T& Value)
{
    this->Insert(this->LastPos(), Value);
}

template <class T, int ListSize>
inline void List<T, ListSize>::Delete(int Pos)
{
    if (this->IsEmpty()) {
        throw std::exception();
    }

    if (Pos < -1 || Pos > this->Last) {
        throw std::exception();
    }

    int i = Pos;

    while (i < this->Last) {
        this->Data[i] = this->Data[i + 1];
    }

    this->Last--;
    this->Size--;
}

template <class T, int ListSize>
inline void List<T, ListSize>::Delete(T& Value)
{
    if (!this->IsEmpty()) {
        this->Delete(this->Find(Value));
    }
}

template <class T, int ListSize>
inline void List<T, ListSize>::Clear()
{
    this->Last = -1;
    this->Size = 0;
}

template <class T, int ListSize>
inline void List<T, ListSize>::Pop_Back()
{
    this->Delete(this->LastPos());
}

template <class T, int ListSize>
inline void List<T, ListSize>::Pop_Front()
{
    this->Delete(this->FirstPos());
}

template <class T, int ListSize>
inline void List<T, ListSize>::Dequeue()
{
    this->Delete(this->FirstPos());
}

template <class T, int ListSize>
inline int List<T, ListSize>::FirstPos()
{
    if (this->IsEmpty()) {
        return -1;
    }

    return 0;
}

template <class T, int ListSize>
inline int List<T, ListSize>::LastPos()
{
    return this->Last;
}

template <class T, int ListSize>
inline int List<T, ListSize>::PrevPos(int Pos)
{
    if (this->IsEmpty() || Pos < 1 || Pos > this->Last) {
        return -1;
    }

    return Pos -1;
}

template <class T, int ListSize>
inline int List<T, ListSize>::NextPos(int Pos)
{
    if (this->IsEmpty() || Pos < 0 || Pos > this->Last - 1) {
        return -1;
    }

    return Pos + 1;
}

template <class T, int ListSize>
inline int List<T, ListSize>::Find(T& Value)
{
    int i = 0;
    while (i < this->Count()) {
        if (this->Data[i] == Value) {
            return i;
        }
        i++;
    }

    return -1;
}

template <class T, int ListSize>
inline T& List<T, ListSize>::Retrieve(int Pos)
{
    if (this->IsEmpty()) {
        throw std::exception();
    }

    if (Pos < 0 and Pos > this->Last) {
        throw std::exception();
    }

    return this->Data[Pos];
}

template <class T, int ListSize>
inline T& List<T, ListSize>::Retrieve(T& Value)
{
    return this->Retrieve(this->Find(Value));
}

template <class T, int ListSize>
inline T& List<T, ListSize>::Top()
{
    if (!this->IsEmpty()) {
        return this->Data[0];
    }
}

template <class T, int ListSize>
inline T& List<T, ListSize>::Bottom()
{
    if (!this->IsEmpty()) {
        return this->Data[this->Last];
    }
}

template <class T, int ListSize>
inline T& List<T, ListSize>::Front()
{
    if (!this->IsEmpty()) {
        return this->Data[0];
    }
}

template <class T, int ListSize>
inline void List<T, ListSize>::Print()
{
    int i = 0;

    while (i < this->Count()) {
        std::cout << this->Data[i] << std::endl;
        i++;
    }
}

#endif // LISTARRAY_H_INCLUDED
