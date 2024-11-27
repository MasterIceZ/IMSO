#include "dungeons.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int n;
vector<int> a, b;

void init(int N, int Q, std::vector<int> A, std::vector<int> B) {
  n = N;
  a = A;
  b = B;
}

int solve(int X, int Y) {
  array<int, 2> can_go = {X, X};
  int power_have = a[X];
  while(can_go[0] > 0 || can_go[1] < n) {
    if(can_go[0] > 0 && power_have >= b[can_go[0] - 1]) {
      power_have = max(power_have, a[can_go[0] - 1]);
      can_go[0] -= 1;
    }
    else if(can_go[1] + 1 < n && power_have >= b[can_go[1]]) {
      power_have = max(power_have, a[can_go[1] + 1]);
      can_go[1] += 1;
    }
    else {
      break;
    }
  }

  return power_have;
}