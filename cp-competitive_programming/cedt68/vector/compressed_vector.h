#ifndef _CP_SEGMENTED_VECTOR_INCLUDED_
#define _CP_SEGMENTED_VECTOR_INCLUDED_
#include <iostream>
#include <vector>

namespace CP {

template <typename T> class CompressedVector {
private:
  T *mDataV;
  size_t *mDataL;
  size_t mCap;
  size_t mSize;

protected:
  void ensureCapacity(size_t capacity) {
    if (capacity > mCap) {
      size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
      expand(s);
    }
  }

public:
  CompressedVector(size_t capacity) {
    mCap = capacity;
    mSize = 0;
    mDataV = new T[mCap]();
    mDataL = new size_t[mCap]();
  }
  ~CompressedVector() {
    delete[] mDataV;
    delete[] mDataL;
  }
  size_t size() { return mSize; }
  size_t capacity() { return mCap; }
  void pop_back() {
    mDataL[mSize - 1]--;
    if (mDataL[mSize - 1] == 0) {
      mSize--;
    }
  }
  void push_back(const T &element) { insert(mSize, element); }
  void print_vector() {
    for (int i = 0; i < mSize; i++) {
      for (int j = 0; j < mDataL[i]; j++) {
        std::cout << mDataV[i] << ' ';
      }
    }
    std::cout << '\n';
  }

  /* --------------- FOR student.h --------------- */
protected:
  void expand(size_t capacity);

public:
  void insert(int index, const T &element);
  T &operator[](int index) const;
  /* --------------------------------------------- */
};

} // namespace CP
#endif
