#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct disjoint_set_union {
  vector<int> parent;
  disjoint_set_union(int n) {
    parent.resize(n + 1);
    for(int i=1; i<=n; ++i) {
      parent[i] = i;
    }
  }
  int find_root(int u) {
    if(u == parent[u]) {
      return u;
    }
    return parent[u] = find_root(parent[u]);
  }
  bool unite(int u, int v) {
    int ru = find_root(u), rv = find_root(v);
    if(ru == rv) {
      return false;
    }
    parent[ru] = rv;
    return true;
  }
};

int remains[MxN];

inline void solve() {
  int n;
  cin >> n;
  disjoint_set_union dsu(2 * n);
  for(int i=1; i<=n; ++i) {
    remains[i] = 2;
  }
  for(int i=1, u, v; i<=n; ++i) {
    cin >> u >> v;
    remains[u]--;
    remains[v]--;
    dsu.unite(u, v + n);
    dsu.unite(v, u + n);
  }
  for(int i=1; i<=n; ++i) {
    if(dsu.find_root(i) == dsu.find_root(i + n) || remains[i] < 0) {
      cout << "NO\n";
      return ;
    }
  }
  cout << "YES\n";
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