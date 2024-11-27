#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;
const int MxM = 1000010;
const int INF = 1e9 + 100;

pair<int, int> parent[MxN][MxN];
int dist[MxN][MxN];
vector<int> edges[MxN], col[MxM];
vector<pair<int, int>> adj[MxN];

inline void print_path(int u, int v) {
  for(int i=0; i<(int) col[u].size(); ++i) {
    for(int j=0; j<(int) col[v].size(); ++j) {
      int cur_u = col[u][i], cur_v = col[v][j];
      if(dist[cur_u][cur_v] >= INF) {
        continue;
      }
      vector<int> path;
      int cur = cur_v;
      path.emplace_back(v);
      path.emplace_back(cur);
      while(cur != cur_u) {
        path.emplace_back(parent[cur_u][cur].second);
        path.emplace_back(parent[cur_u][cur].first);
        cur = parent[cur_u][cur].first;
      }
      path.emplace_back(u);
      reverse(path.begin(), path.end());
      cout << (path.size() + 1) / 2 << "\n";
      for(auto x: path) {
        cout << x << " ";
      }
      cout << "\n";
      return ;
    }
  }
  cout << "-1\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }
  for(int i=1, t; i<=n; ++i) {
    cin >> t;
    for(int j=1, x; j<=t; ++j) {
      cin >> x;
      edges[i].emplace_back(x);
      col[edges[i][j - 1]].emplace_back(i);
    }
  }
  for(int i=1; i<=m; ++i) {
    auto &cur_col = col[i];
    if((int) cur_col.size() <= 1) {
      continue;
    }
    for(int j=1; j<(int) cur_col.size(); ++j) {
      int u = cur_col[j], v = cur_col[j - 1];
      adj[u].emplace_back(v, i);
      adj[v].emplace_back(u, i);
      dist[u][v] = dist[v][u] = 1;
      parent[u][v] = make_pair(u, i);
      parent[v][u] = make_pair(v, i);
    }
  }
  for(int k=1; k<=n; ++k) {
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          parent[i][j] = parent[k][j];
        }
      }
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    print_path(u, v);
  }
  return 0;
}