#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9 + 100;

struct edge_t {
  int u, v, w;
  edge_t(int _u, int _v, int _w):
    u(_u), v(_v), w(_w) {}
  bool operator < (const edge_t& o) const {
    return w < o.w;
  }
};

struct disjoint_set_union {
  int *parent;
  int c, n;
  disjoint_set_union(int _n) {
    n = _n;
    parent = (int *) calloc(n + 1, sizeof(int));
  }
  void init() {
    for(int i=1; i<=n; ++i) {
      parent[i] = i;
    }
    c = n;
  }
  int find_root(int u) {
    if(parent[u] == u) {
      return parent[u];
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

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  deque<edge_t> edges;
  vector<int> weights;
  for(int i=1, u, v, w; i<=m; ++i) {
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
    weights.emplace_back(w);
  }
  sort(edges.begin(), edges.end());
  sort(weights.begin(), weights.end());
  weights.resize(unique(weights.begin(), weights.end()) - weights.begin());
  int answer = INF;
  disjoint_set_union dsu(n);
  for(auto min_weight: weights) {
    dsu.init();
    int cur_min = INF;
    for(auto edge: edges) {
      if(edge.w < min_weight) {
        edges.pop_front();
        continue;
      }
      if(dsu.unite(edge.u, edge.v) == false) {
        continue;
      }
      if(cur_min == INF) {
        cur_min = edge.w;
      }
      if(dsu.find_root(s) == dsu.find_root(e)) {
        answer = min(answer, edge.w - min_weight);
        break;
      }
    }
  }
  cout << answer << "\n";
  return 0;
}