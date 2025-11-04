#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "kary-heap.h"
#include <iostream>

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::fixUp(size_t idx) {
  // Write your code here
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::fixDown(size_t idx) {
  // Write your code here
}

template<typename T, size_t K, typename Comp>
const T& CP::kary_heap<T, K, Comp>::top() {
  if(empty()) {
    throw std::runtime_error("Heap is empty");
  }
  // Write your code here
  return T();
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::pop() {
  if(empty()) {
    throw std::runtime_error("Heap is empty");
  }
  // Write your code here
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::push(const T& element) {
  // Write your code here
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::debug() {
  // you can put debug code here
  // this function will NOT be called during evaluation
}

#endif