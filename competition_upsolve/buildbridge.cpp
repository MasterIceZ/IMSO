// Hydrolyzed~
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct road_t {
  int u, v;
  ll p, c;
  road_t(int _u, int _v, ll _p, ll _c):
    u(_u), v(_v), p(_p), c(_c) {}
};

struct edge_t {
  int u, v;
  ll w;
  bool operator < (const edge_t& o) const {
    return w < o.w;
  }
  edge_t(int _u, int _v, ll _w):
    u(_u), v(_v), w(_w) {}
};

struct disjoint_set {
  int parent[MxN], component_count;
  int find_root(int u) {
    if(u == parent[u]) {
      return u;
    }
    return parent[u] = find_root(parent[u]);
  }
  void unite(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv) {
      return ;
    }
    component_count -= 1;
    parent[ru] = rv;
  }
  void init(int n) {
    component_count = n;
    for(int i=0; i<=component_count; ++i) {
      parent[i] = i;
    }
  }
} dsu;

int n, m;
ll b, p, c;
vector<road_t> roads;
vector<edge_t> edges;

inline bool ok(ll x)  {
  edges.clear();
  dsu.init(n);
  for(auto road: roads) {
    edges.emplace_back(road.u, road.v, road.c + road.p * x);
  }
  sort(edges.begin(), edges.end());
  ll sum = 0ll;
  for(auto edge: edges) {
    int ru = dsu.find_root(edge.u);
    int rv = dsu.find_root(edge.v);
    if(ru == rv) {
      continue;
    }
    dsu.unite(ru, rv);
    sum += edge.w;
  }
  return sum <= b && dsu.component_count == 1;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m >> b;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v >> p >> c;
    roads.emplace_back(u, v, p, c);
  }
  ll l = 0, r = b;
  while(l < r) {
    ll mid = (l + r + 1ll) >> 1ll;
    if(ok(mid)) {
      l = mid;
    }
    else {
      r = mid - 1ll;
    }
  }
  cout << l;
  return 0;
}