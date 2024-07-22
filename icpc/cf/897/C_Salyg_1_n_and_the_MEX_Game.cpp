#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN];

inline int play(int v) {
  cout << v << "\n";
  cout.flush();
  int res;
  cin >> res;
  return res;
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if(a[1] != 0) {
    play(0);
    return ;
  }
  int cnt = 0;
  for(int i=1; i<=n; ++i) {
    cnt += (a[i] == i - 1);
  }
  int t = cnt;
  while(t != 0) {
    t = play(t);
  }
  play(t);
  return ;
}

signed main(int argc, char *argv[]) {
  // cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}