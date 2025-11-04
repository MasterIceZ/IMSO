#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "kary-heap.h"
#include <iostream>

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::fixUp(size_t idx) {
  while(idx > 0) {
    size_t parent = (idx - 1) / K;
    if(mLess(mData[parent], mData[idx])) {
      std::swap(mData[parent], mData[idx]);
      idx = parent;
      continue;
    }
    break;
  }
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::fixDown(size_t idx) {
  T t = mData[idx];
  while(idx * K + 1 < mSize) {
    size_t c = idx * K + 1;
    if(c + 1 < mSize) {
      for(size_t i=1; i<K; ++i) {
        size_t nx = c + i;
        if(nx < mSize && mLess(mData[c], mData[nx])) {
          c = nx;
        }
      }
    }
    if(mLess(mData[c], t)) {
      break;
    }
    mData[idx] = mData[c];
    idx = c;
  }
  mData[idx] = t;
}

template<typename T, size_t K, typename Comp>
const T& CP::kary_heap<T, K, Comp>::top() {
  if(empty()) {
    throw std::runtime_error("Heap is empty");
  }
  // Write your code here
  return mData[0];
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::pop() {
  // Write your code here
  if(empty()) {
    throw std::runtime_error("Heap is empty");
  }
  mData[0] = mData[--mSize];
  fixDown(0);
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::push(const T& element) {
  // Write your code here
  if(mSize == mCap) {
    expand(mCap * 2);
  }
  mData[mSize++] = element;
  fixUp(mSize - 1);
}

template<typename T, size_t K, typename Comp>
void CP::kary_heap<T, K, Comp>::debug() {
  // you can put debug code here
  // this function will NOT be called during evaluation
}

#endif