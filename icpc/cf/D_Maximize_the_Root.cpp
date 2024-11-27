#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const ll INF = 1e18 + 100;

int a[MxN];
vector<int> adj[MxN];

bool ok(int u, ll val) {
  ll t = max(0ll, val - a[u]);
  if(val >= INF) {
    return false;
  }
  bool isLeaf = true, can = true;
  if(u == 1) {
    val = 0;
  }
  for(auto v: adj[u]) {
    isLeaf = false;
    can &= ok(v, t + val);
  }
  if(isLeaf && t > 0) {
    return false;
  }
  return can;
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int i=2, p; i<=n; ++i) {
    cin >> p;
    adj[p].emplace_back(i);
  }
  ll l = 0ll, r = INF;
  while(l < r) {
    ll mid = (l + r + 1ll) >> 1ll;
    if(ok(1, mid)) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
  for(int i=0; i<=n+1; ++i) {
    adj[i].clear();
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