#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct color_counter_t {
  int cnt[MxN], maxx = 0;
  ll max_color_sum = 0ll;
  void insert(int color) {
    cnt[color] += 1;
    if(maxx < cnt[color]) {
      maxx = cnt[color];
      max_color_sum = (ll) color;
    }
    else if(maxx == cnt[color]) {
      max_color_sum += (ll) color;
    }
  }
  void erase(int color) {
    cnt[color] -= 1;
  }
  ll query() {
    return max_color_sum;
  }
};

int c[MxN];
int sz[MxN], heavy[MxN], tin[MxN], tout[MxN], rev_tin[MxN], timer = 0;
ll answer[MxN];
vector<int> adj[MxN];
color_counter_t counter;

void dfs(int u, int p) {
  sz[u] = 1;
  tin[u] = ++timer;
  rev_tin[timer] = u;
  for(auto v: adj[u]) {
    if(v == p) {
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
  counter.insert(c[u]);
  for(auto v: adj[u]) {
    if(v == p || v == heavy[u]) {
      continue;
    }
    for(int t=tin[v]; t<=tout[v]; ++t) {
      int inserting_vertex = rev_tin[t];
      counter.insert(c[inserting_vertex]);
    }
  }
  answer[u] = counter.query();
  if(deleting) {
    for(int t=tin[u]; t<=tout[u]; ++t) {
      int erasing_vertex = rev_tin[t];
      counter.erase(c[t]);
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> c[i];
  }
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, 0);
  sack(1, 0, false);
  for(int i=1; i<=n; ++i) {
    cout << answer[i] << " ";
  }
  cout << "\n";
  return 0;
}