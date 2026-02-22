#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
typename CP::list<T>::iterator CP::list<T>::insert(typename CP::list<T>::iterator it,const T& element) {
  // Your code here
  node* current = it.ptr;
  node* before_node = current->prev;
  node* new_node = new node(element, before_node, current, nullptr);
  before_node->next = new_node;
  current->prev = new_node;
  // Update nextnext pointers
  new_node->nextnext = (new_node->next != mHeader) ? new_node->next->next : nullptr;
  if (before_node != mHeader) {
    before_node->nextnext = (before_node->next != mHeader) ? before_node->next->next : nullptr;
  }
  current->nextnext = (current->next != mHeader) ? current->next->next : nullptr;
  mSize++;
  return iterator(new_node);
}

template<typename T>
T CP::list<T>::at(size_t k) {
  // Ensure k is in range
  if (k >= mSize) throw std::out_of_range("index of out range");
  // Your code here
  node* current = mHeader->next;
  while (k > 0) {
    if (current->nextnext != nullptr && current->nextnext != mHeader && k >= 2) {
      current = current->nextnext;
      k -= 2;
    } else {
      current = current->next;
      k -= 1;
    }
  }
  return current->data;
}

template<typename T>
typename CP::list<T>::iterator CP::list<T>::erase(typename CP::list<T>::iterator it) {
  // Your code here
  node* current = it.ptr;
  node* before_node = current->prev;
  node* after_node = current->next;
  before_node->next = after_node;
  after_node->prev = before_node;
  // Update nextnext pointers
  if (before_node != mHeader) {
    before_node->nextnext = (before_node->next != mHeader) ? before_node->next->next : nullptr;
  }
  delete current;
  mSize--;
  return iterator(after_node);
}

#endif