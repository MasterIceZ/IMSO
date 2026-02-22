#include "priority_queue.h"

#include <algorithm>
#include <stack>
#include <vector>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  int l = 2 * k + 1;
  int ll = 2 * l + 1, lr = 2 * l + 2;
  int r = 2 * k + 2;
  int rl = 2 * r + 1, rr = 2 * r + 2;
  std::swap(mData[l], mData[r]);
  std::swap(mData[ll], mData[rl]);
  std::swap(mData[lr], mData[rr]);
  return ;
}