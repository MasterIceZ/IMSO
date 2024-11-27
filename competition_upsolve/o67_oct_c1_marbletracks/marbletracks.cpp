#include "marbletracks.h"
// #include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

struct fenwick_tree_2d {
  vector<vector<int>> fw;
  void init(int n, int m) {
    fw.assign(n+1, vector<int>(m+1, 0));
  }
  void update(int idx_i, int idx_j, int val) {
    for(int i=idx_i; i<fw.size(); i+=i&-i) {
      for(int j=idx_j; j<fw[i].size(); j+=j&-j) {
        fw[i][j] += val;
      }
    }
  }
  int query(int idx_i, int idx_j) {
    int res = 0;
    for(int i=idx_i; i>0; i-=i&-i) {
      for(int j=idx_j; j>0; j-=j&-j) {
        res += fw[i][j];
      }
    }
    return res;
  }
};

struct sack_ds {
  int n, m;
  fenwick_tree_2d fw;
  void init_ds(int _n, int _m) {
    n = _n;
    m = _m;
    fw.init(n, m);
  }
  void add(int idx_i, int idx_j) {
    // TODO: ADD VAL TO DS
    fw.update(idx_i, idx_j, 1);
  }
  void remove(int idx_i, int idx_j) {
    // TODO: REMOVE VAL FROM DS
    fw.update(idx_i, idx_j, -1);
  }
};

int in[MxN], comp_root[MxN], comp_id[MxN];
int tin[MxN], timer, tin[MxN], tout[MxN], rev_tin[MxN], sz[MxN], heavy[MxN];
vector<int> adj[MxN], rev_adj[MxN];
sack_ds ds;

void dfs(int u, int p) {
  tin[u] = ++timer;
  rev_tin[timer] = u;
  sz[u] = 1;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    sz[u] += sz[v];
    if(sz[v] > sz[heavy[u]]) {
      heavy[u] = v;
    }
  }
  tout[u] = timer;
}

void sack(int u, int p, bool deleting) {
  for(auto v: adj[u]) {
    if(v == p || v == heavy[u]) {
      continue;
    }
    sack(v, u, true);
  }
  if(heavy[u] != 0) {
    sack(heavy[u], u, false);
  }
  // TODO: UPDATE DS FOR u
  for(auto v: adj[u]) {
    if(v == p || heavy[u] == v) {
      continue;
    }
    for(int t=tin[v]; t<=tout[v]; t++) {
      // TODO: UPDATE DS FOR LIGHT CHILDREN OF u
      int cur_vertex = rev_tin[t];
    }
  }
  // TODO: ANSWER QUERY
  if(deleting) {
    for(int t=tin[u]; t<=tout[u]; t++) {
      // TODO: REMOVE SUBTREE u
      int v = rev_tin[t];

    }
  }
}

vector<int> observe(int N, int Q, vector<int> v, vector<tuple<int, int, int>> queries) {
  auto [a, b, c] = queries[0];
  // for(int i=0; i<N; ++i) {
  //   adj[i + 1].emplace_back(v[i] + 1);
  //   rev_adj[v[i] + 1].emplace_back(i + 1);
  //   in[v[i] + 1]++;
  // }
  // queue<int> q;
  // for(int i=1; i<=N; ++i) {
  //   if(in[i] == 0) {
  //     q.emplace(i);
  //   }
  // }
  // while(!q.empty()) {
  //   int u = q.front();
  //   q.pop();
  //   for(auto v: adj[u]) {
  //     if(--in[v] == 0) {
  //       q.emplace(v);
  //     }
  //   }
  // }
  // vector<int> in_cycle;
  // for(int i=1; i<=N; ++i) {
  //   if(in[i] != 0) {
  //     in_cycle.emplace_back(i);
  //   }
  // }
  // int it = 0;
  // for(auto u: in_cycle) {
  //   if(comp_id[u] != 0) {
  //     continue;
  //   }
  //   comp_id[u] = ++it;
  //   comp_root[it] = u;
  //   int cur = u;
  //   while(v[cur] + 1 != u) {
  //     cur = v[cur] + 1;
  //     comp_id[cur] = it;
  //   }
  // }
  // for(int id=1; id<=it; ++id) {
  //   rev_adj[v[comp_root[id]] + 1].erase(find(
  //     rev_adj[v[comp_root[id]] + 1].begin(), rev_adj[v[comp_root[id]] + 1].end(), comp_root[id]
  //   ));
  // }
  return {};
}
