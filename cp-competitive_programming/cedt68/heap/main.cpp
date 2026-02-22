#include <iostream>
#include "priority_queue.h"
#include "student.h"

void test() {
  int n, m; std::cin >> n >> m;
  CP::priority_queue<int, std::less<int>> pq;
  for (int i = 1; i <= n; ++i) {
    int x; std::cin >> x;
    pq.push(x);
  }
  size_t k; std::cin >> k;
  pq.child_swap(k);
  std::cout << "After Swap:" << std::endl;
  pq.print();
}

signed main() {
  int T; std::cin >> T;
  while (T--) {
    test();
  }
}