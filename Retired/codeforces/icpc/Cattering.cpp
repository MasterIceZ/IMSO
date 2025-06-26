#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 1010;

struct hopcroft_karp {
  int n, m;
  std::vector<std::vector<int>> adj;
  std::vector<int> l, r, dist, cur;

  hopcroft_karp(int _n, int _m):
    n(_n), m(_m), adj(_n), l(_n, -1), r(_m, -1), dist(_n, 0), cur(_n, 0) {}

  void add_edge(int u, int v) {
    adj[u].push_back(v);
  }
  void bfs() {
    std::queue<int> q;
    for(int i=0; i<n; ++i) {
      if(l[i] == -1) {
        q.emplace(i);
        dist[i] = 0;
      }
      else {
        dist[i] = -1;
      }
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v: adj[u]) {
        if(r[v] != -1 && dist[r[v]] == -1) {
          q.emplace(r[v]);
          dist[r[v]] = dist[u] + 1;
        }
      }
    }
  }
  bool dfs(int u) {
    for(int &i=cur[u]; i<(int) adj[u].size(); ++i) {
      int v = adj[u][i];
      if(r[v] == -1 || dist[r[v]] == dist[u] + 1 && dfs(r[v])) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    return false;
  }
  int max_matching() {
    int cnt = 0;
    while(true) {
      bfs();
      std::fill(cur.begin(), cur.end(), 0);
      int local_cnt = 0;
      for(int i=0; i<n; ++i) {
        if(l[i] == -1) {
          local_cnt += dfs(i);
        }
      }
      if(local_cnt == 0) {
        break;
      }
      cnt += local_cnt;
    }
    return cnt;
  }
};

int n, m, a[MxN][MxN];


inline bool ok(int mid) {
  hopcroft_karp mbm(n + m, n + m);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(a[i][j] >= mid) {
        mbm.add_edge(i, j + n);
      }
    }
  }
  return mbm.max_matching() == n;
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  std::vector<int> c;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      std::cin >> a[i][j];
      c.emplace_back(a[i][j]);
    }
  }
  std::sort(c.begin(), c.end());
  c.resize(std::unique(c.begin(), c.end()) - c.begin());
  int l = 0, r = c.size() - 1;
  while(l < r) {
    int mid = (l + r + 1) / 2;
    if(ok(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  hopcroft_karp mbm(n + m, n + m);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      if (a[i][j] >= l) {
        mbm.add_edge(i, j + n);
      }
    }
  }
  std::cout << l << "\n";
  for(int i=0; i<n; ++i) {
    std::cout << mbm.l[i] - n + 1 << " ";
  }
}