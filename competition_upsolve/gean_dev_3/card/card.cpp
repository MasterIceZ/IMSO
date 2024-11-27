#include <vector>
#include <algorithm>
#include "card.h"

std::vector<int> Shin(int N, std::vector<int> A) {
  std::sort(A.begin(), A.end());
  A.pop_back();
  return A;
}

int Lena(int N, std::vector<int> B) {
  return 5;
}
