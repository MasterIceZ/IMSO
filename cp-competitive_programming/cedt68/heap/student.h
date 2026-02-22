#include "priority_queue.h"

#include <algorithm>
#include <stack>
#include <vector>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  //Write your code here
  std::vector<int> left_subtree, right_subtree;
  // Collect left subtree of k
  std::stack<size_t> dfs;
  dfs.push(2 * k + 1);
  while(!dfs.empty()) {
    size_t cur = dfs.top();
    dfs.pop();
    if(cur >= mSize) continue;
    left_subtree.push_back(cur);
    dfs.push(2 * cur + 1);
    dfs.push(2 * cur + 2);
  }
  // Collect right subtree of k
  dfs.push(2 * k + 2);
  while(!dfs.empty()) {
    size_t cur = dfs.top();
    dfs.pop();
    if(cur >= mSize) continue;
    right_subtree.push_back(cur);
    dfs.push(2 * cur + 1);
    dfs.push(2 * cur + 2);
  }
  // Swap left and right subtree
  for(int i=0; i<(int) left_subtree.size(); ++i) {
    size_t l = left_subtree[i], r = right_subtree[i];
    std::swap(mData[l], mData[r]);
  }
  return ;
}