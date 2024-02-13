#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int a[MxN], n;

inline void solve() {
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = 0;
  while(l <= n && a[l] == a[1]) {
    l++;
  }
  while(n - r >= 1 && a[n - r] == a[n]) {
    r++;
  }
  if(l > r) {
    cout << l << "\n";
  }
  e
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