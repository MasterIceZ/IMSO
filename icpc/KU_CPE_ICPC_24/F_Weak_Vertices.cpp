#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 22;

bool e[MxN][MxN];

inline void solve() {
  int n;
  cin >> n;
  if(n == -1) {
    exit(0);
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1, x; j<=n; ++j) {
      cin >> x;
      e[i][j] = (x == 1);
    }
  }
  set<int> answer;
  for(int i=1; i<=n; ++i) {
    bool can = false;
    for(int j=1; j<=n; ++j) {
      for(int k=1; k<=n; ++k) {
        if(i == j || i == k || j == k) {
          continue;
        }
        can |= (e[i][j] && e[i][k] && e[j][k]);
      }
    }
    if(!can) {
      answer.emplace(i);
    }
  }
  for(auto x: answer) {
    cout << x - 1 << " ";
  }
  cout << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  while(true) {
    solve();
  }
  return 0;
}