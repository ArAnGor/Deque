#pragma once
#include <iostream>
using namespace std;

template <class T>
class Deque
{
private:

  template <class T>
  class ListElem
  {
  public:
    ListElem<T> *prev;
    T *data;
    ListElem<T> *next;

    ListElem(ListElem<T> *p, T *d, ListElem<T> *n) { prev = p; data = d; next = n; }
    ~ListElem() { delete data; }
  };

  ListElem<T> *head;
  ListElem<T> *tail;

public:
  Deque();
  ~Deque();
  T GetFront() const;
  T GetBack() const;
  T PopFront();
  T PopBack();
  void PushFront(T &elem);
  void PushBack(T &elem);
  bool IsEmpty() const;
};

template <class T>
Deque<T>::Deque()
{
  head = new ListElem<T>(NULL, NULL, NULL);
  tail = new ListElem<T>(head, NULL, NULL);
  head->next = tail;
}

template <class T>
Deque<T>::~Deque()
{

}

template<class T>
T Deque<T>::GetFront() const
{
  return T();
}

template<class T>
T Deque<T>::GetBack() const
{
  return T();
}

template<class T>
T Deque<T>::PopFront()
{
  return T();
}

template<class T>
T Deque<T>::PopBack()
{
  return T();
}

template<class T>
void Deque<T>::PushFront(T &elem)
{
}

template<class T>
void Deque<T>::PushBack(T &elem)
{
}

template<class T>
bool Deque<T>::IsEmpty() const
{
  return false;
}
