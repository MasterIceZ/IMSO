#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

inline void solve() {
  int n, k, m, mask = 0;
  string s, u;
  cin >> n >> k >> m >> s;
  int max_mask = (1 << k) - 1;
  for(int i=0; i<=m-1; ++i) {
    mask |= (1 << (s[i] - 'a'));
    if(mask == max_mask) {
      mask = 0;
      u += s[i];
    }
  }
  if((int) u.size() >= n) {
    cout << "YES";
    return ;
  }
  for(int i=0; i<=k-1; ++i) {
    if(mask & (1 << i)) {
      continue;
    }
    while((int) u.size() < n) {
      u += (char) (i + 'a');
    }
  }
  cout << "NO\n" << u;
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}