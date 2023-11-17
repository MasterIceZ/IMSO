#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;
const int MxM = 100010;

int n, m, dist[MxM], tree_depth[MxN], tree_diameter[MxN];
vector<int> adj[MxM];
queue<int> q;

inline void bfs(int stp) {
  q.emplace(stp);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(auto x: adj[now]) {
      if(dist[x] != -1) {
        continue;
      }
      dist[x] = dist[now] + 1;
      q.emplace(x);
    }
  }
}

void processTree(int idx) {
  int m, p, root;
  cin >> m;
  for(int i=1; i<=m; ++i) {
    cin >> p;
    if(p == 0) {
      root = i;
      continue;
    }
    adj[i].emplace_back(p);
    adj[p].emplace_back(i);
  }
  for(int i=1; i<=m; ++i) {
    dist[i] = -1;
  }
  dist[root] = 0;
  bfs(root);
  int new_root = -1;
  for(int i=1; i<=m; ++i) {
    if(dist[i] <= tree_depth[idx]) {
      continue;
    }
    new_root = i;
    tree_depth[idx] = dist[i];
  }
  for(int i=1; i<=m; ++i) {
    dist[i] = -1;
  }
  dist[new_root] = 0;
  bfs(new_root);
  for(int i=1; i<=m; ++i) {
    tree_diameter[idx] = max(tree_diameter[idx], dist[i]);
  }

  for(int i=1; i<=m; ++i) {
    adj[i].clear();
  }
}

void solve() {
  cin >> n;
  for(int i=1; i<=n; ++i) {
    tree_depth[i] = -1;
    tree_diameter[i] = 0;
    processTree(i);
  }
  int all_depth = accumulate(tree_depth + 1, tree_depth + n + 1, 0);
  int minn = 1e9 + 100, maxx = 0;
  for(int i=1; i<=n; ++i) {
    if(tree_depth[i] == 0) {
      continue;
    }
    int product = tree_diameter[i] + 2 * (all_depth - tree_depth[i]);
    minn = min(minn, product);
    maxx = max(maxx, product);
  }
  minn = min(minn, maxx);
  cout << maxx << " " << minn;
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}