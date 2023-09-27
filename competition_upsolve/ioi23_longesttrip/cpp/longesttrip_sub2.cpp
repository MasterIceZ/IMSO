#include <bits/stdc++.h>
#include "longesttrip.h"

using namespace std;

vector<int> res;
deque<int> dq;

std::vector<int> longest_trip(int N, int D) {
  res.clear();
  if (D == 3) {
    for (int i = 0; i <= N - 1; ++i) {
      res.emplace_back(i);
    }
  }
  else if(D == 2) {
    dq.clear();
    dq.emplace_back(0);
    dq.emplace_back(1);
    dq.emplace_back(2);
    for (int i = 0; i <= 1; ++i) {
      if(are_connected({i}, {i + 1})) {
        continue;
      }
      swap(dq[0], dq[i]);
      swap(dq[2], dq[i + 1]);
      break;
    }
    for (int i = 3; i <= N - 1; ++i) {
      if(are_connected({i}, {dq[0]})) {
        dq.emplace_front(i);
      }
      else {
        dq.emplace_back(i);
      }
    }
    while(!dq.empty()) {
      res.emplace_back(dq.front());
      dq.pop_front();
    }
  }
  return res;
}
