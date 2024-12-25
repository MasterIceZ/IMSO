#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct disjoint_set_union {
  int parent[MxN];
  set<int> vertices[MxN];
  int find_root(int u) {
    if(parent[u] == u) {
      return u;
    }
    return parent[u] = find_root(parent[u]);
  }
  bool unite(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv) {
      return false;
    }
    vertices[rv].emplace(ru);
    parent[ru] = rv;
    return true;
  }
  void init() {
    for(int i=0; i<MxN; ++i) {
      parent[i] = i;
      vertices[i].clear();
    }
  }
};

vector<int> adj[MxN];
disjoint_set_union dsu;
bool visited[MxN], status[MxN], done[MxN];

void dfs(int u) {
  visited[u] = true;
  status[u] = true;
  for(auto v: adj[u]) {
    if(visited[v]) {
      continue;
    }
    dfs(v);
    status[u] ^= status[v];
    if(!done[v]) {
      dsu.unite(u, v);
    }
  }
  for(auto v: adj[u]) {
    if(done[v] || dep[v] <= dep[u] || parent)
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dsu.init();
  dfs(0);
  return 0;
}