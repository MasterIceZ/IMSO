#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct disjoint_set {
  int parent[MxN], sz[MxN];
  int find_root(int u) {
    while(parent[u] != u) {
      u = parent[u];
    }
    return u;
  }
  void unite(int u, int v) {
    int ru = find_root(u), rv = find_root(v);
    if(ru == rv) {
      return ;
    }
    if(sz[ru] > sz[rv]) {
      swap(ru, rv);
    }
    sz[rv] = sz[ru] + sz[rv];
    parent[ru] = rv;
  }
  disjoint_set() {
    for(int i=1; i<MxN; ++i) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
} dsu;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=n; ++i) {
    cin >> u >> v;
    dsu.unite(u, v);
  }
  vector<int> c;
  for(int i=1; i<=n; ++i) {
    if(dsu.find_root(i) != i) {
      continue;
    }
    c.emplace_back(dsu.sz[i]);
  }
  bitset<MxN> can;
  can[0] = true;
  for(auto x: c) {
    can |= can << x;
  }
  for(int i=1; i<=n; ++i) {
    cout << can[i];
  }
  cout << "\n";
  return 0;
}