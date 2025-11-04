#ifndef __K_ARY_HEAP_INCLUDED__
#define __K_ARY_HEAP_INCLUDED__

#include <iostream>
#include <vector>

namespace CP {

template<typename T, size_t K, typename Comp = std::less<T>>
class kary_heap {
protected:
  T *mData;
  size_t mSize;
  size_t mCap;
  Comp mLess;

  void expand(size_t capacity) {
    T* arr = new T[capacity]();
    for (size_t i = 0; i < mSize; i++) {
      arr[i] = mData[i];
    }
    delete[] mData;
    mData = arr;
    mCap = capacity;
  }

  void fixUp(size_t idx);
  void fixDown(size_t idx);

  void heapify() {
    for (size_t i = (mSize - 2) / K; i >= 0; --i) {
      fixDown(i);
    }
  }

public:
  kary_heap(const std::vector<T>& vec):
    mData(nullptr), mSize(0), mCap(0), mLess(Comp()) {
    mSize = vec.size();
    mCap = mSize > 0 ? mSize : 1;
    mData = new T[mCap]();
    for (size_t i = 0; i < mSize; i++) {
      mData[i] = vec[i];
    }
    heapify();
  }

  kary_heap(const Comp& c = Comp()):
    mData(new T[1]()), mSize(0), mCap(1), mLess(c) {}
  
  kary_heap<T, K, Comp>& operator=(const kary_heap<T, K, Comp>& other) {
    std::swap(mSize, other.mSize);
    std::swap(mCap, other.mCap);
    std::swap(mData, other.mData);
    std::swap(mLess, other.mLess);
    return *this;
  }

  ~kary_heap() {
    delete[] mData;
  }

  bool empty() const {
    return mSize == 0;
  }

  size_t size() const {
    return mSize;
  }

  const T& top();
  void push(const T& element);
  void pop();
  void debug();
  
  void printHeap() {
    for (size_t i = 0; i < mSize; i++) {
      std::cout << mData[i] << " ";
    }
    std::cout << "\n";
  }
};

}

#endif