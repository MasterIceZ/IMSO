#include "longest.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<std::pair<int,int>> longest(int N) {
  vector<pair<int, int>> res;
  res.emplace_back(0, 0);
  res.emplace_back(0, 1);
  if(N <= 2) {
    return res;
  }
  int center, maxx;
  if(find(0, 1, 2)) {
    maxx = 1;
    center = 2;
  }
  else {
    center = 0;
    maxx = 2;
  }
  res.emplace_back(center, maxx);
  for (int i = 3; i < N; ++i) {
    if(find(center, maxx, i)) {
      // (max -> i) better than (center -> i) -> change center
      swap(center, maxx);
    }
    if(find(maxx, i, center)) {
      // (max -> center) better than (i -> center) -> change max
      maxx = i;
    }
    res.emplace_back(center, maxx);
  }
  return res;
}