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
  int p[MxN * 2];
  bool cycle[MxN * 2];
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
    for(int i=1; i<MxN * 2; ++i) {
      p[i] = i;
    }
  }
};

vector<gem_t> gems;
int used[MxN * 2], mem[MxN];
ll v;
vector<int> adj[MxN * 2];
disjoint_set dsu;
int n, c, mem_answer[MxN];
bool visited[MxN * 2];

void dfs(int u, int p) {
  visited[u] = true;
  if(p > n) {
    mem_answer[p - n] = u;
  }
  for(auto v: adj[u]) {
    if(v == p || visited[v] == true) {
      continue;
    }
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
      x += n;
    }
    if(t == 1) {
      c.emplace_back(c[0]);
    }
    cin >> v;
    gems.emplace_back(v, i, c);
  }
  sort(gems.begin(), gems.end());
  ll res = 0ll;
  for(auto [value, index, colors]: gems) {
    int cnt_cycle = 0;
    for(auto color: colors) {
      cnt_cycle += dsu.cycle[dsu.find_root(color)];
    }
    if(cnt_cycle > 1) {
      continue;
    }
    for(auto color: colors) {
      dsu.unite(index, color);
      adj[index].emplace_back(color);
      adj[color].emplace_back(index);
    }
    res += value;
  }
  bool have_all = true;
  for(int i=n+1; i<=n+c; ++i) {
    if(adj[i].size() == 0) {
      have_all = false;
    }
  }
  if(!have_all) {
    cout << "-1\n";
    return 0;
  }
  cout << res << "\n";
  for(int i=n+1; i<=n+c; ++i) {
    if(adj[i].size() == 1 && !visited[i]) {
      dfs(i, 0);
    }
  }
  for(int i=n+1; i<=n+c; ++i) {
    if(visited[i]) {
      continue;
    }
    dfs(i, 0);
  }
  for(int i=1; i<=c; ++i) {
    cout << mem_answer[i] << " ";
  }
  cout << "\n";
  return 0;
}