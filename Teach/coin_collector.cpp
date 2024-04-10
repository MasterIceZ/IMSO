#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

vector<int> adj[MxN], rev[MxN], adj2[MxN];
bitset<MxN> visited;
stack<int> st;
map<pair<int, int>, bool> have;
int comp[MxN];
ll a[MxN], b[MxN], mem[MxN];

void dfs(int u, int p) {
  visited[u] = true;
  for(auto x: adj[u]) {
    if(visited[x] || x == p) {
      continue;
    }
    dfs(x, u);
  }
  st.emplace(u);
}

void dfs2(int u, int p, int it) {
  visited[u] = true;
  comp[u] = it;
  for(auto x: rev[u]) {
    if(x == p || visited[x]) {
      continue;
    }
    dfs2(x, u, it);
  }
}

ll dfs3(int u, int p) {
  if(mem[u] != 0ll) {
    return mem[u];
  }
  ll res = 0ll;
  for(auto x: adj2[u]) {
    res = max(res, dfs3(x, u));
  }
  return mem[u] = res + b[u];
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    rev[v].emplace_back(u);
  }
  for(int i=1; i<=n; ++i) {
    if(visited[i]) {
      continue;
    }
    dfs(i, 0);
  }
  visited = 0;
  int it = 0;
  while(!st.empty()) {
    int now = st.top(); st.pop();
    if(visited[now]) {
      continue;
    }
    dfs2(now, 0, ++it);
  }
  for(int i=1; i<=n; ++i) {
    b[comp[i]] += a[i];
    for(auto x: adj[i]) {
      if(comp[x] == comp[i] || have[make_pair(comp[i], comp[x])]) {
        continue;
      }
      adj2[comp[i]].emplace_back(comp[x]);
      have[make_pair(comp[i], comp[x])] = true;
    }
  }
  ll answer = 0ll;
  visited = 0;
  for(int i=1; i<=it; ++i) {
    answer = max(answer, dfs3(i, 0));
  }
  cout << answer << "\n";
  return 0;
}