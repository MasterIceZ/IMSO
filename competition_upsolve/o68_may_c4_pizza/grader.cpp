#include <cstdio>

#include "pizza.h"

int main() {
  int M;
  std::vector<int> n;
  std::vector<int> a;
  int tmp;

  tmp = scanf("%d", &M);
  n.resize(M);
  a.resize(M);
  for (int i = 0; i < M; ++i) {
    tmp = scanf("%d %d", &n[i], &a[i]);
  }

  int result = countangles(M, n, a);
  printf("%d\n", result);

  return 0;
}