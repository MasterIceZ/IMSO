#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 660;
const int INF = 1e9 + 100;

struct hopcroft_karp {
  int n, m;
  vector<int> l, r, level, ptr;
  vector<vector<int>> adj;
  hopcroft_karp() {}
  hopcroft_karp(int _n, int _m):
    n(_n), m(_m) {
    init(n, m);
  }
  void init(int _n, int _m) {
    n = _n;
    m = _m;
    adj.assign(n + m, vector<int> ());
  }
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
  }
  void bfs() {
    level = vector<int> (n, -1);
    queue<int> q;
    for(int i=0; i<n; ++i) {
      if(l[i] != -1) {
        continue;
      }
      level[i] = 0;
      q.emplace(i);
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v: adj[u]) {
        if(r[v] != -1 && level[r[v]] == -1) {
          level[r[v]] = level[u] + 1;
          q.emplace(r[v]);
        }
      }
    }
  }
  bool dfs(int u) {
    for(auto &i=ptr[u]; i<(int) adj[u].size(); ++i) {
      int v = adj[u][i];
      if(r[v] == -1 || (level[r[v]] == level[u] + 1 && dfs(r[v]))) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    return false;
  }
  int max_matching() {
    int matching = 0, cur_cnt = 0;
    l = vector<int> (n + m, -1);
    r = vector<int> (n + m, -1);
    do {
      ptr = vector<int> (n);
      bfs();
      cur_cnt = 0;
      for(int i=0; i<n; ++i) {
        if(l[i] == -1 && dfs(i)) {
          cur_cnt++;
        }
      }
      matching += cur_cnt;
    } while(cur_cnt > 0);
    return matching;
  }
};

struct kuhn {
  int n;
  vector<vector<int>> adj;
  vector<int> match;
  vector<bool> visited;
  kuhn(int _n):
    n(_n) {
    adj.assign(n, vector<int> ());
    match = vector<int> (n, -1);
    visited = vector<bool> (n, false);
  }
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
  }
  bool try_match(int u) {
    if(visited[u]) {
      return false;
    }
    visited[u] = true;
    for(auto v: adj[u]) {
      if(match[v] == -1 || try_match(match[v])) {
        match[v] = u;
        return true;
      }
    }
    return false;
  }
  int max_matching() {
    for(int u=0; u<n; ++u) {
      visited = vector<bool> (n, false);
      try_match(u);
    }
    int cnt = 0;
    for(int i=0; i<n; ++i) {
      cnt += (match[i] != -1);
    }
    return cnt;
  }
};

int stp[MxN], dist[MxN][MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, t, d;
  cin >> n >> m >> t >> d;
  for(int i=0; i<t; ++i) {
    cin >> stp[i];
    stp[i] -= 1;
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }
  for(int i=1, u, v, w; i<=m; ++i) {
    cin >> u >> v >> w;
    u -= 1;
    v -= 1;
    dist[u][v] = dist[v][u] = min(w, dist[v][u]);
  }
  for(int k=0; k<n; ++k) {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  auto ok = [&](int mid) {
    // hopcroft_karp mbm(t, n);
    kuhn mbm(n);
    for(int i=0; i<t; ++i) {
      for(int j=0; j<n; ++j) {
        if(dist[stp[i]][j] > mid) {
          continue;
        }
        mbm.add_edge(i, j);
      }
    }
    return mbm.max_matching() >= d;
  };
  int l = 0, r = INF;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(ok(mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  cout << (l != INF ? l: -1) << "\n";
  return 0;
}