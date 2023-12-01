// Hydrolyzed~
#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN], rev[MxN];
set<int> compress_adj[MxN], compress_rev[MxN];
bitset<MxN> visited;
stack<int> st;
int comp[MxN];

void dfs(int u, int p) {
  visited[u] = true;
  for(auto x: adj[u]) {
    if(x == p || visited[x]) {
      continue;
    }
    dfs(x, u);
  }
  st.emplace(u);
}

void dfs_2(int u, int p, int it) {
  comp[u] = it;
  visited[u] = true;
  for(auto x: rev[u]) {
    if(x == p || visited[x] || comp[x] != -1) {
      continue;
    }
    dfs_2(x, u, it);
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    rev[v].emplace_back(u);
  }
  for(int i=1; i<=n; ++i) {
    comp[i] = -1;
    if(visited[i]) {
      continue;
    }
    dfs(i, 0);
  }
  visited = 0;
  int it = 0;
  while(!st.empty()) {
    int cur = st.top();
    st.pop();
    if(visited[cur]) {
      continue;
    }
    dfs_2(cur, 0, ++it);
  }
  for(int i=1; i<=n; ++i) {
    for(auto x: adj[i]) {
      if(comp[i] == comp[x]) {
        continue;
      }
      compress_adj[comp[i]].emplace(comp[x]);
      compress_rev[comp[x]].emplace(comp[i]);
    }
  }
  int zero_in = 0, zero_out = 0;
  for(int i=1; i<=it; ++i) {
    zero_in += (compress_rev[i].empty() == true);
    zero_out += (compress_adj[i].empty() == true);
  }
  cout << max(zero_in, zero_out) << "\n";
  return 0;
}