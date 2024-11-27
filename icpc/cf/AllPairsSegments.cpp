#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> v(n);
  for(auto &x: v) {
    cin >> x;
  }
  map<ll, ll> mp;
  for(ll i=1; i<(ll) n; ++i) {
    ll vi = v[(int) i - 1], vi1 = v[(int) i];
    mp[i * (n - i)] += vi1 - vi - 1ll;
    mp[(i - 1) * (n - i) + (n - 1)] += 1ll;
  }
  mp[n - 1] += 1;
  while(q--) {
    ll k;
    cin >> k;
    cout << mp[k] << " ";
  }
  cout << "\n";
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