#include "goatpay.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;
const int MxC = 1000010;

struct vertex_t {
  int v, w, c;

  vertex_t(int _v, int _w, int _c):
    v(_v), w(_w), c(_c) {}
};

struct edge_t {
  int u, v, w, c;
  
  edge_t(int _u=0, int _v=0, int _w=0, int _c=0): 
    u(_u), v(_v), w(_w), c(_c) {}
};

struct fenwick_tree {
  vector<int> t;
  int n;
  void init(int _n) {
    n = _n + 1;
    t.assign(n, 0ll);
  }
  void update(int idx, int v) {
    for(; idx<n; idx+=idx&-idx) {
      t[idx] ^= v;
    }
  }
  int query(int idx) {
    int ret = 0;
    for(; idx>0; idx-=idx&-idx) {
      ret ^= t[idx];
    }
    return ret;
  }
};

fenwick_tree fws[MxC];
int pos[MxN << 1];
int tin[MxN], tout[MxN], timer, depth[MxN], color[MxN];
edge_t edges[MxN];
vector<vertex_t> adj[MxN];
int weight[MxN];
set<int> color_set;
vector<int> mem_color[MxC];

void dfs(int u, int p) {
  tin[u] = ++timer;
  pos[tin[u]] = u;
  mem_color[color[u]].emplace_back(tin[u]);
  depth[u] = depth[p] + 1;
  for(auto &[v, w, c]: adj[u]) {
    if(v == p) {
      continue;
    }
    weight[v] = w;
    color[v] = c;
    color_set.emplace(c);
    dfs(v, u);
  }
  tout[u] = ++timer;
  pos[tout[u]] = u;
  mem_color[color[u]].emplace_back(tout[u]);
}

void plant_tree(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W, std::vector<int> C) {
  for(int i=0; i<N-1; ++i) {
    adj[U[i] + 1].emplace_back(V[i] + 1, W[i], C[i]);
    adj[V[i] + 1].emplace_back(U[i] + 1, W[i], C[i]);

    edges[i + 1] = edge_t(U[i] + 1, V[i] + 1, W[i], C[i]);
  }
  dfs(1, 0);
  for(auto c: color_set) {
    fws[c].init((int) mem_color[c].size());
    for(int i=0; i<(int) mem_color[c].size(); ++i) {
      fws[c].update(i + 1, weight[pos[mem_color[c][i]]]);
    }
  }
}

int goat_pay(int u, int v, int x) {
  u += 1;
  v += 1;
  if(tin[u] > tin[v]) {
    swap(u, v);
  }
  
  auto &mem = mem_color[x];
  auto l = upper_bound(mem.begin(), mem.end(), tin[u]);
  auto r = upper_bound(mem.begin(), mem.end(), tin[v]);
  
  if(l == r) {
    return 0;
  }

  return fws[x].query(r - mem.begin()) ^ fws[x].query(l - mem.begin());
}

void update_edge(int id, int d) {
  id += 1;
  auto &[u, v, w, c] = edges[id];
  if(tin[u] < tin[v]) {
    swap(u, v);
  }
  for(auto &idx: {tin[u], tout[u]}) {
    fws[c].update(lower_bound(mem_color[c].begin(), mem_color[c].end(), idx) - mem_color[c].begin() + 1, d ^ w);
  }
  w = d;
}

