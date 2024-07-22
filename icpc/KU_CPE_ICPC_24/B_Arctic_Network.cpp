#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;

struct edge_t {
  int u, v;
  double w;
  edge_t(int _u, int _v, double _w):
    u(_u), v(_v), w(_w) {}
  bool operator < (const edge_t &o) const {
    return w < o.w;
  }
};

struct disjoint_set {
  int parent[MxN];
  void init(int n) {
    for(int i=0; i<=n; ++i) {
      parent[i] = i;
    }
  }
  int find_root(int u) {
    return u == parent[u] ? u: parent[u] = find_root(parent[u]);
  }
  void unite(int u, int v) {
    if(find_root(u) == find_root(v)) {
      return ;
    }
    parent[find_root(u)] = find_root(v);
  }
};

pair<double, double> p[MxN];
disjoint_set dsu;

double make_dist(int i, int j) {
  return (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
}

inline void solve() {
  int n, m;
  cin >> m >> n;
  for(int i=1; i<=n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  vector<edge_t> edges;
  for(int i=1; i<=n; ++i) {
    for(int j=i+1; j<=n; ++j) {
      edges.emplace_back(i, j, make_dist(i, j));
    }
  }
  sort(edges.begin(), edges.end());
  dsu.init(n);
  vector<edge_t> mst;
  for(auto [u, v, w]: edges) {
    if(dsu.find_root(u) == dsu.find_root(v)) {
      continue;
    }
    dsu.unite(u, v);
    mst.emplace_back(u, v, w);
  }
  cout << fixed << setprecision(2) << sqrt(mst[mst.size() - m].w) << "\n";
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