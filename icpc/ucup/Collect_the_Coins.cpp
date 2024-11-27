#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;
const ll INF = 1e9;

int n;
map<ll, vector<ll>> coins;
ll t, p;

inline pair<ll, ll> make_pos(ll b) {
  return make_pair(b, b);
}

inline bool can_go(pair<ll, ll> c, ll r, ll p) {
  return c.first - r <= p && p <= c.second + r;
}

inline bool check(ll speed) {
  pair<ll, ll> bot_range = make_pair(-INF, INF);
  for(int i=1; i<n; ++i) {
    ll time_diff = 
  }
}

inline void solve() {
  coins.clear();
  cin >> n;
  bool ok = true;
  for(int i=1; i<=n; ++i) {
    cin >> t >> p;
    if(coins[t].size() == 2) {
      ok = false;
    }
    coins[t].emplace_back(p);
  }
  if(!ok) {
    cout << -1 << "\n";
    return ;
  }
  for(auto &[t, v]: coins) {
    if(v.size() == 1) {
      continue;
    }
    tie(v[0], v[1]) = minmax(v[0], v[1]);
  }
  ll l = 0, r = INF;
  while(l < r) {
    ll mid = (l + r) >> 1ll;
    if(check(mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  if(check(l)) {
    cout << l << "\n";
  }
  else {
    cout << -1 << "\n";
  }
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