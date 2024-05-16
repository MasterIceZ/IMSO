#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int a[MxN];

inline void solve() {
  int n;
  cin >> n;
  map<int, priority_queue<int, vector<int>, greater<int>>> mp;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    mp[a[i] >> 2].emplace(a[i]);
  }
  for(int i=1; i<=n; ++i) {
    cout << mp[a[i] >> 2].top() << " ";
    mp[a[i] >> 2].pop();
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