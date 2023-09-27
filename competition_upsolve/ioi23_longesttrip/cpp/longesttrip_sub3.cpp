#include <bits/stdc++.h>
#include "longesttrip.h"

using namespace std;

vector<int> res, line_1, line_2;
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
  else {
    line_1 = {0};
    line_2 = {1};
    for (int i = 2; i <= N-1; ++i) {
      if(are_connected({i}, {line_1.back()})) {
        // i connect with 1
        line_1.emplace_back(i);
      }
      else if(are_connected({i}, {line_2.back()})) {
        // i connect with 2
        line_2.emplace_back(i);
      }
      else {
        // i is not connect with 1 and 2
        // so 1 is connect with 2 -> pigeonhole principle
        while(!line_2.empty()) {
          line_1.emplace_back(line_2.back());
          line_2.pop_back();
        }
        line_2.emplace_back(i);
      }
    }
    if(line_1.size() > line_2.size()) {
      res = line_1;
    }
    else {
      res = line_2;
    }
  }
  return res;
}
