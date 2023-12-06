#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int comp[MxN], comp_size[MxN];
ll a[MxN], comp_sum[MxN];
vector<int> adj[MxN], rev[MxN], st;
bitset<MxN> visited;
pair<int, ll> dp[MxN];

void dfs(int u, int p) {
  visited[u] = true;
  for(auto x: adj[u]) {
    if(x == p || visited[u]) {
      continue;
    }
    dfs(x, u);
  }
  st.emplace_back(u);
}

void dfs_2(int u, int p, int c) {
  comp[u] = c;
  comp_size[c] += 1;
  comp_sum[c] += a[u];
  for(auto x: rev[u]) {
    if(x == p || comp[x] != 0) {
      continue;
    }
    dfs_2(x, u, c);
  }
}

inline void solve() {
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
  visited = 0;
  st.clear();
  for(int i=1; i<=n; ++i) {
    if(visited[i]) {
      continue;
    }
    dfs(i, 0);
  }
  int it = 0;
  reverse(st.begin(), st.end());
  for(auto u: st) {
    if(comp[u] != 0) {
      continue;
    }
    dfs_2(u, 0, ++it);
  }
  pair<int, ll> res = make_pair(0, 0ll);
  for(int i=1; i<=it; ++i) {
    dp[i] = make_pair(comp_size[i], -comp_sum[i]); 
    res = max(res, dp[i]);
  }
  reverse(st.begin(), st.end());
  for(auto u: st) {
    for(auto x: adj[u]) {
      if(comp[x] == comp[u]) {
        continue;
      }
      pair<int, ll> cur = make_pair(
        dp[comp[x]].first + comp_size[comp[u]], 
        dp[comp[x]].second - comp_sum[comp[u]]
      );
      dp[comp[u]] = max(dp[comp[u]], cur);
      res = max(res, dp[comp[u]]);
    }
  }
  cout << res.first << " " << -res.second;
  // cerr << "\nFINISHED!\n";
  for(int i=1; i<=n; ++i) {
    comp[i] = 0;
    comp_size[i] = 0;
    comp_sum[i] = 0ll;
    adj[i].clear();
    rev[i].clear();
  }
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