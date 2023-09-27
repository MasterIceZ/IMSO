#include <bits/stdc++.h>
#include "longesttrip.h"

using namespace std;

vector<int> res, line_1, line_2, qry;
deque<int> dq;

inline int search(vector<int> a, vector<int> b) {
  int l = 0, r = (int) a.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    qry.clear();
    for (int i = l; i <= mid; ++i) {
      qry.emplace_back(a[i]);
    }
    if(are_connected(qry, b)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

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
    bool connected = true;
    for (int i = 2; i <= N - 1; ++i) {
      if(are_connected({i}, {line_1.back()})) {
        // i connect with 1
        line_1.emplace_back(i);
        connected = true;
      }
      else if(!connected || are_connected({i}, {line_2.back()})) {
        // i connect with 2
        line_2.emplace_back(i);
        connected = false;
      }
      else {
        // i is not connect with 1 and 2
        // so 1 is connect with 2 -> pigeonhole principle
        while(!line_2.empty()) {
          line_1.emplace_back(line_2.back());
          line_2.pop_back();
        }
        line_2.emplace_back(i);
        connected = true;
      }
    }
    if(line_1.size() > line_2.size()) {
      swap(line_1, line_2);
    }
    if(are_connected(line_1, line_2) == false) {
      return line_2;
    }
    if(are_connected({line_1[0]}, {line_2[0]})) {
      reverse(line_2.begin(), line_2.end());
      for(auto x: line_1) {
        line_2.emplace_back(x);
      }
      return line_2;
    }
    if (are_connected({line_1[0]}, {line_2.back()})) {
      for(auto x: line_1) {
        line_2.emplace_back(x);
      }
      return line_2;
    }
    if(are_connected({line_1.back()}, {line_2[0]})) {
      // reverse(line_2.begin(), line_2.end());
      for(auto x : line_2) {
        line_1.emplace_back(x);
      }
      return line_1;
    }
    if(are_connected({line_1.back()}, {line_2.back()})) {
      reverse(line_1.begin(), line_1.end());
      for(auto x: line_1) {
        line_2.emplace_back(x);
      }
      return line_2;
    }
    int edge_1 = search(line_2, line_1);
    int edge_2 = search(line_1, {line_2[edge_1]});
    for (int i = 0; i < (int)line_2.size(); ++i) {
      res.emplace_back(line_2[(edge_1 + i + 1) % ((int)line_2.size())]);
    }
    for (int i = 0; i < (int)line_1.size(); ++i) {
      res.emplace_back(line_1[(edge_2 + i) % ((int)line_1.size())]);
    }
  }
  return res;
}
