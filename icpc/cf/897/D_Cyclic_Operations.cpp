#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int n, k, a[MxN], level[MxN], root[MxN];
vector<int> adj[MxN];

bool dfs(int u, int p, int rt) {
  level[u] = level[p] + 1;
  root[u] = rt;
  for(auto v: adj[u]) {
    if(level[v] != 0 && root[u] == root[v] && level[u] - level[v] != k - 1) {
      return false;
    }
    if(level[v] == 0) {
      return dfs(v, u, rt);
    }
  }
  return true;
}

inline void solve() {
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
    level[i] = root[i] = 0;
  }
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    adj[i].emplace_back(a[i]);
  }
  bool ok = true;
  if(k == 1) {
    for(int i=1; i<=n; ++i) {
      ok &= (a[i] == i);
    }
    cout << (ok ? "YES": "NO") << "\n";
    return ;
  }
  for(int i=1; i<=n; ++i) {
    ok &= (level[i] || dfs(i, 0, i));
  }
  cout << (ok ? "YES": "NO") << "\n";
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