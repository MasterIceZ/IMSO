#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 22;

struct edge_t {
  int u, v;
  ll w;
  bool operator < (const edge_t &o) const {
    return w < o.w;
  }
  edge_t(int _u, int _v, ll _w):
    u(_u), v(_v), w(_w) {}
};

struct disjoint_set_union {
  vector<int> parent;
  inline void init(int n) {
    parent = vector<int> (n, -1);
    for(int i=0; i<n; ++i) {
      parent[i] = i;
    }
  }
  int find_root(int u) {
    return u == parent[u] ? u: parent[u] = find_root(parent[u]);
  }
  void unite(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv) {
      return ;
    }
    parent[ru] = rv;
  }
} dsu;

ll c, a[MxN][MxN], answer = 1e18 + 100ll;
vector<edge_t> edges;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n >> c;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cin >> a[i][j];
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      if(a[i][j] == 0) {
        continue;
      }
      edges.emplace_back(i, j, a[i][j]);
    }
  }
  sort(edges.begin(), edges.end());
  int max_mask = (1 << n) - 1;

  auto mst_mask = [&](int mask) {
    dsu.init(n + 1);
    ll cost = c * (n - __builtin_popcountll(mask));
    int cnt = 0;
    for(auto e: edges) {
      if(((mask >> e.u) & 1 && (mask >> e.v) & 1) || dsu.find_root(e.u) == dsu.find_root(e.v)) {
        continue;
      }
      cnt++;
      cost += e.w;
      dsu.unite(e.u, e.v);
    }
    return cnt == n - 1 ? cost: (ll) 1e18 + 100ll;
  };

  for(int mask=0; mask<=max_mask; ++mask) {
    answer = min(answer, mst_mask(mask));
  }
  cout << answer << "\n";
  return 0;
}