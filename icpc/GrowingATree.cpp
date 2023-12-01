#include <bits/stdc++.h>

using namespace std;

const int MxN = 500050;

struct fenwick_tree {
  int *t, n;
  void update(int idx, int v) {
    for(; idx<=n; idx+=idx&-idx) {
      t[idx] += v;
    }
  }
  int query(int idx) {
    int res = 0;
    for(; idx>0; idx-=idx&-idx) {
      res += t[idx];
    }
    return res;
  }
  fenwick_tree(int _n): n(_n) {
    t = (int *) calloc(n + 1, sizeof(int));
  }
};

vector<int> adj[MxN];
int timer, t_in[MxN], t_out[MxN];

void dfs(int u) {
  t_in[u] = ++timer;
  for(auto x: adj[u]) {
    dfs(x);
  }
  t_out[u] = timer;
}

inline void solve() {
  int t;
  cin >> t;
  for(int i=1; i<=t; ++i) {
    adj[i].clear();
    t_in[i] = 0;
    t_out[i] = 0;
  }
  int n = 1;
  vector<pair<int, int>> query;
  for(int i=1, o, x, y; i<=t; ++i) {
    cin >> o >> x;
    if(o == 1) {
      query.emplace_back(-1, ++n);
      adj[x].emplace_back(n);
    }
    else {
      cin >> y;
      query.emplace_back(x, y);
    }
  }
  timer = 0;
  dfs(1);
  fenwick_tree fw(timer + 1);
  for(auto x: query) {
    if(x.first == -1) {
      int u = x.second, t = t_in[u];
      int val = fw.query(t);
      fw.update(t, -val);
      fw.update(t + 1, val);
    }
    else {
      int u = x.first;
      fw.update(t_in[u], x.second);
      fw.update(t_out[u], -x.second);
    }
  }
  for(int i=1; i<=n; ++i) {
    cout << fw.query(t_in[i]) << " ";
  }
  return ;
}

signed main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}