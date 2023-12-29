#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline ll make_sqrt(ll x) {
  ll l = 0, r = x;
  while(l < r) {
    ll mid = (l + r) >> 1ll;
    if(mid * mid >= x) {
      r = mid;
    } else {
      l = mid + 1ll;
    }
  }
  return l;
}

inline void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for(auto &x: v) {
    cin >> x;
  }
  ll sq = make_sqrt(accumulate(v.begin(), v.end(), 0ll));
  // cerr << sq << "\n";
  cout << (sq * sq == accumulate(v.begin(), v.end(), 0ll) ? "YES": "NO");
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}