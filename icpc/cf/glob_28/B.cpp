#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int p[MxN];

inline void solve() {
  int n, k;
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    p[i] = -1;
  }
  int t = 1;
  for(int i=k; i<=n; i+=k) {
    p[i] = t;
    t++;
  }
  for(int i=t, it=1; it<=n; ++it) {
    if(p[it] != -1) {
      continue;
    }
    p[it] = i;
    i++;
  }
  for(int i=1; i<=n; ++i) {
    cout << p[i] << " ";
  }
  cout << "\n";
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}