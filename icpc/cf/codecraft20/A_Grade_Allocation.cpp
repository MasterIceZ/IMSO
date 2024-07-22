#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for(auto &x: v) {
    cin >> x;
  }
  cout << min(accumulate(v.begin(), v.end(), 0), m) << "\n";
  return ;
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