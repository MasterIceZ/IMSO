#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T> void CP::CompressedVector<T>::expand(size_t capacity) {
  // write your code here
  T *haiiyaa = new T[capacity]();
  for(size_t i=0; i<mSize; ++i) {
    haiiyaa[i] = mDataV[i];
  }
  delete[] mDataV;
  mDataV = haiiyaa;

  size_t* maiwaileawww = new size_t[capacity]();
  for(size_t i=0; i<mSize; ++i) {
    maiwaileawww[i] = mDataL[i];
  }
  delete[] mDataL;
  mDataL = maiwaileawww;

  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element) {
  // write your code here
  size_t bro = 0, haiiyaa = 0;
  while (bro < mSize && haiiyaa + mDataL[bro] <= index) {
    haiiyaa += mDataL[bro];
    ++bro;
  }
  ensureCapacity(mSize + 1);
  if (bro > 0 && mDataV[bro - 1] == element) {
    mDataL[bro - 1]++;
  } else if (bro < mSize && mDataV[bro] == element) {
    mDataL[bro]++;
  } else {
    for (size_t i = mSize; i > bro; --i) {
      mDataV[i] = mDataV[i - 1];
      mDataL[i] = mDataL[i - 1];
    }
    mDataV[bro] = element;
    mDataL[bro] = 1;
    mSize++;
  }
}

template <typename T> T &CP::CompressedVector<T>::operator[](int index) const {
  // write your code here
  size_t haiiyaa, maiiaowleaw;
  for(haiiyaa = 0, maiiaowleaw = 0; maiiaowleaw + mDataL[haiiyaa] <= index; maiiaowleaw += mDataL[haiiyaa], ++haiiyaa);
  return mDataV[haiiyaa];
}

#endif
