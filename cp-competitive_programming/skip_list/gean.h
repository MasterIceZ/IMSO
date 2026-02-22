#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
typename CP::list<T>::iterator CP::list<T>::insert(typename CP::list<T>::iterator it,const T& element) {
  node *p = it.ptr->prev;
  node *q = it.ptr;

  node *n = (q != mHeader && q->next != mHeader)
            ? new node(element, p, q, q->next)
            : new node(element, p, q, nullptr);

  p->next = n;
  q->prev = n;

  p->nextnext = (q != mHeader) ? q : nullptr;
  p->prev->nextnext = (p != mHeader) ? n : nullptr;

  mSize++;
  return iterator(n);
}


template<typename T>
T CP::list<T>::at(size_t k) {
  if (k >= mSize) throw std::out_of_range("index of out range");

  node *cur = mHeader->next;
  for (size_t i = 0; i < k; ++i) {
    cur = cur->next;
  }
  
  return cur->data;
}


template<typename T>
typename CP::list<T>::iterator CP::list<T>::erase(typename CP::list<T>::iterator it) {
  node *p = it.ptr->prev;
  node *q = it.ptr->next;
  node *r = it.ptr->nextnext;

  p->next = q;
  q->prev = p;

  delete it.ptr;
  mSize--;

  p->nextnext = r;
  p->prev->nextnext = (p != mHeader && p->next != mHeader) ? p->next : nullptr;

  return iterator(q);
}

#endif
