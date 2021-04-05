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
    T data;
    ListElem<T> *next;

    ListElem(ListElem<T> *p, T &d, ListElem<T> *n) { prev = p; data = d; next = n; }
    ~ListElem() {}
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
  T t;
  head = new ListElem<T>(NULL, t, NULL);
  tail = new ListElem<T>(head, t, NULL);
  head->next = tail;
}

template <class T>
Deque<T>::~Deque()
{
  while (!IsEmpty())
  {
    tail->prev = tail->prev->prev;
    delete tail->prev->next;
    tail->prev->next = tail;
  }
  delete head;
  delete tail;
}

template<class T>
T Deque<T>::GetFront() const
{
  if (IsEmpty()) throw exception();
  return head->next->data;
}

template<class T>
T Deque<T>::GetBack() const
{
  if (IsEmpty()) throw exception();
  return tail->prev->data;
}

template<class T>
T Deque<T>::PopFront()
{
  if (IsEmpty()) throw exception();
  T data = head->next->data;
  head->next = head->next->next;
  delete head->next->prev;
  head->next->prev = head;
  return data;
}

template<class T>
T Deque<T>::PopBack()
{
  if (IsEmpty()) throw exception();
  T data = tail->prev->data;
  tail->prev = tail->prev->prev;
  delete tail->prev->next;
  tail->prev->next = tail;
  return data;
}

template<class T>
void Deque<T>::PushFront(T &elem)
{
  ListElem<T> *le = head->next;
  head->next = new ListElem<T>(head, elem, le);
  le->prev = head->next;
}

template<class T>
void Deque<T>::PushBack(T &elem)
{
  ListElem<T> *le = tail->prev;
  tail->prev = new ListElem<T>(le, elem, tail);
  le->next = tail->prev;
}

template<class T>
bool Deque<T>::IsEmpty() const
{
  if (head->next == tail) return true;
  return false;
}
