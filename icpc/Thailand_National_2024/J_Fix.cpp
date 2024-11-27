#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct gem_t {
  ll value;
  int index;
  vector<int> colors;
  bool operator < (const gem_t &o) const {
    if(value != o.value) {
      return value > o.value;
    }
    return index < o.index;
  }
  gem_t(ll _value, int _index, vector<int> _colors):
    value(_value), index(_index), colors(_colors) {}
};

struct disjoint_set {
  int p[MxN];
  bool cycle[MxN];
  int find_root(int u) {
    if(u == p[u]) {
      return u;
    }
    p[u] = find_root(p[u]);
    cycle[u] |= cycle[p[u]];
    return p[u];
  }
  void unite(int u, int v) {
    int ru = find_root(u), rv = find_root(v);
    if(ru == rv) {
      cycle[ru] = cycle[rv] = true;
      return ;
    }
    cycle[rv] |= cycle[ru];
    p[ru] = rv;
  }
  disjoint_set() {
    for(int i=1; i<MxN; ++i) {
      p[i] = i;
    }
  }
};

vector<gem_t> gems;
ll v;
vector<pair<int, int>> adj[MxN];
disjoint_set dsu;
int n, c, mem_answer[MxN], in[MxN];
bool used[MxN], visited[MxN];
bitset<MxN> in_cycle;
queue<int> q;

void dfs(int u, int p) {
  visited[u] = true;
  for(auto [v, idx]: adj[u]) {
    if(u == p || used[idx] || visited[v]) {
      continue;
    }
    used[idx] = true;
    mem_answer[u] = idx;
    dfs(v, u);
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> c;
  for(int i=1, t; i<=n; ++i) {
    cin >> t;
    vector<int> c(t);
    for(auto &x: c) {
      cin >> x;
    }
    if(t == 1) {
      c.emplace_back(c[0]);
    }
    cin >> v;
    gems.emplace_back(v, i, c);
  }
  sort(gems.begin(), gems.end());
  ll res = 0ll;
  int cnt = 0;
  for(auto [value, index, colors]: gems) {
    int cnt_cycle = 0;
    for(auto color: colors) {
      cnt_cycle += dsu.cycle[dsu.find_root(color)];
    }
    if(cnt_cycle > 1) {
      continue;
    }
    dsu.unite(colors[0], colors[1]);
    adj[colors[0]].emplace_back(colors[1], index);
    adj[colors[1]].emplace_back(colors[0], index);
    in[colors[0]]++, in[colors[1]]++;
    res += value;
    cnt++;
  }
  if(cnt != c) {
    cout << "-1\n";
    return 0;
  }
  cout << res << "\n";
  in_cycle.set();
  for(int i=1; i<=c; ++i) {
    if(in[i] == 1) {
      q.emplace(i);
      in_cycle[i] = false;
    }
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(auto [v, idx]: adj[u]) {
      if(!in_cycle[v] || --in[v] == 1) {
        q.emplace(v);
        in_cycle[v] = false;
      }
    }
  }
  for(int i=1; i<=c; ++i) {
    if(!in_cycle[i]) {
      continue;
    }
    dfs(i, 0);
  }
  // for(int i=1; i<=c; ++i) {
  //   if(visited[i]) {
  //     continue;
  //   }
  //   dfs(i, 0);
  // }
  for(int i=1; i<=c; ++i) {
    cout << mem_answer[i] << " ";
  }
  cout << "\n";
  return 0;
}