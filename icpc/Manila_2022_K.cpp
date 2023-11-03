#include <bits/stdc++.h>

using namespace std;

bitset<26> can;
int all = 0, have[33], cnt = 0;

void solve(int test_idx) {
  string s;
  cin >> s;
  cnt = 0;
  for (auto x : s)
  {
    if(!can[x - 'A']) {
      cout << "IMPOSSIBLE";
      return;
    }
    if(have[x - 'A'] != test_idx) {
      have[x - 'A'] = test_idx;
      cnt++;
    }
  }
  cout << (cnt == all ? "POSSIBLE" : "IMPOSSIBLE");
  return;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  can.set();
  for (int i = 1; i <= 3; ++i) {
    cin >> s;
    for(auto x: s) {
      if(x == '*') {
        continue;
      }
      can[x - 'A'] = false;
    }
  }
  all = can.count();
  int q, test_idx = 1;
  cin >> q;
  while(q--) {
    solve(test_idx++);
    cout << "\n";
  }
  return 0;
}