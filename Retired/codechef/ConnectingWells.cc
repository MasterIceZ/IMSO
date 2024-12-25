#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 2020;

struct disjoint_set_union {
  int* parent;
  disjoint_set_union(int n) {
    parent = (int *) calloc(n + 1, sizeof(int));
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

struct edge_t {
  int u, v;
  ll w;
  edge_t(int _u, int _v, ll _w):
    u(_u), v(_v), w(_w) {}
  bool operator < (const edge_t& o) const {
    return w < o.w;
  }
};

pair<ll, ll> a[MxN];

inline void solve() {
	int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  vector<edge_t> edges;
  auto make_edge = [&](pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first == b.first) {
      return (abs(a.second - b.second) + 1ll) / 2ll;
    }
    if(a.second == b.second) {
      return (abs(a.first - b.first) + 1ll) / 2ll;
    }
    return max(abs(a.first - b.first), abs(a.second - b.second));
  };
  for(int i=1; i<=n; ++i) {
    for(int j=i+1; j<=n; ++j) {
      edges.emplace_back(i, j, make_edge(a[i], a[j]));
    }
  }
  sort(edges.begin(), edges.end());
  disjoint_set_union dsu(n);
  ll max_edge = 0ll;
  for(auto e: edges) {
    if(dsu.unite(e.u, e.v) == false) {
      continue;
    }
    max_edge = e.w;
  }
  cout << max_edge << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
