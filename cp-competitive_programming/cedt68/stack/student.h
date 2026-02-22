#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

// can include other libs or write util funtion here

template <typename T>
void CP::stack<T>::push(const T& value) {
  if(empty() || mData.back().size() == mData.size()) {
    mData.push_back(std::vector<T>());
  }
  mData.back().push_back(value);
  mSize++;
}

template <typename T>
void CP::stack<T>::pop() {
  if (size() == 0) throw std::out_of_range("index of out range") ;
	//write your code here
  mData.back().pop_back();
  if(mData.back().empty()) {
    mData.pop_back();
  }
  mSize--;
}

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return mSize;
}

template <typename T>
const T&  CP::stack<T>::top() const {
  //write your code here
  if (size() == 0) throw std::out_of_range("index of out range") ;
  return mData.back().back();
}

/*
Push and pop with steady hand,
or tears may fall from teacher’s stand.
*/

#endif