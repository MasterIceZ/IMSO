#include <bits/stdc++.h>
#include "longesttrip.h"

using namespace std;

std::vector<int> longest_trip(int N, int D) {
  if (D == 3) {
    vector<int> res;
    for (int i = 0; i <= N - 1; ++i) {
      res.emplace_back(i);
    }
    return res;
  }
  return {};
}
