#include <bits/stdc++.h>

#include <vector>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct edge_t {
  int u, v;
  ll w;
  edge_t(int _u, int _v, ll _w):
    u(_u), v(_v), w(_w) {}
  bool operator < (const edge_t& o) const {
    return w < o.w;
  }
};

struct disjoint_set_union {
  int p[MxN];
  void init(int n) {
    for(int i=1; i<=n; ++i) {
      p[i] = i;
    }
  }
  int find_root(int u) {
    if(u == p[u]) {
      return u;
    }
    return p[u] = find_root(p[u]);
  }
  bool unite(int u, int v) {
    int ru = find_root(u), rv = find_root(v);
    if(ru == rv) {
      return false;
    }
    p[ru] = rv;
    return true;
  }
} dsu;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<edge_t> edges, done, not_done;
  for(int i=1, u, v; i<=n; ++i) {
    ll w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
  }
  sort(edges.begin(), edges.end());
  dsu.init(n);
  for(auto edge: edges) {
    auto [u, v, w] = edge;
    if(dsu.unite(u, v)) {
      done.emplace_back(edge);
    }
    else {
      not_done.emplace_back(edge);
    }
  }
  vector<int> l(done.size()), r(done.size(), not_done.size()), mid(done.size());
  while(true) {
    bool pending = false;
    for(int i=0; i<done.size(); ++i) {
      mid[i] = (l[i] + r[i]) >> 1;
      if(l[i] == r[i]) {
        continue;
      }
      pending = true;
    }
    if(!pending) {
      break;
    }
    dsu.init(n);
    sort(mid.begin(), mid.end());
    for(int i=0; i<(int) done.size(); ++i) {
      auto [u, v, w] = not_done[i];
      dsu.unite(u, v);
      
    }
  }
  return 0;
}