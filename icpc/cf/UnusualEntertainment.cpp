#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct query_t {
  int idx, l, r;
  query_t(int _idx, int _l, int _r):
    idx(_idx), l(_l), r(_r) {}
};

vector<int> adj[MxN];
vector<query_t> query[MxN];
set<int> subtree[MxN];
int permute[MxN], answer[MxN];

void dfs(int u, int p) {
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    dfs(v, u);
    if(subtree[u].size() < subtree[v].size()) {
      swap(subtree[u], subtree[v]);
    }
    for(auto x: subtree[v]) {
      subtree[u].emplace(x);
    }
  }
  subtree[u].emplace(permute[u]);
  for(auto x: query[u]) {
    set<int>::iterator lb = subtree[u].lower_bound(x.l);
    answer[x.idx] = (lb != subtree[u].end() && *lb <= x.r);
  }
}

inline void solve() {
  int n, q;
  cin >> n >> q;
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    permute[x] = i;
  }
  for(int i=1, l, r, v; i<=q; ++i) {
    cin >> l >> r >> v;
    query[v].emplace_back(i, l, r);
  }
  dfs(1, 0);
  for(int i=1; i<=q; ++i) {
    cout << (answer[i] ? "YES": "NO") << "\n";
  }
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
    query[i].clear();
    subtree[i].clear();
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