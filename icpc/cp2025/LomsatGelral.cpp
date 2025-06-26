#include <iostream>
#include <map>
#include <vector>

const int MxN = 100010;

struct node_t {
  std::map<long long, long long> cnt, sum;

  void insert(long long x) {
    cnt[x] += 1;
    sum[1] += x;
  }
};

long long c[MxN], mem[MxN];
std::vector<int> adj[MxN];
node_t vertex[MxN];

inline void merge(int u, int v) {
  if(vertex[u].cnt.size() < vertex[v].cnt.size()) {
    std::swap(vertex[u], vertex[v]);
  }
  for(auto e: vertex[v].cnt) {
    if(vertex[u].cnt.count(e.first)) {
      vertex[u].sum[vertex[u].cnt[e.first]] -= e.first;
    }
    vertex[u].cnt[e.first] += e.second;
    vertex[u].sum[vertex[u].cnt[e.first]] += e.first;
  }
}

void dfs(int u, int p) {
  vertex[u].insert(c[u]);
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    dfs(v, u);
    merge(u, v);
  }
  mem[u] = vertex[u].sum.rbegin()->second;
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for(int i=1; i<=n; ++i) {
    std::cin >> c[i];
  }
  for(int i=2, u, v; i<=n; ++i) {
    std::cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, 0);
  for(int i=1; i<=n; ++i) {
    std::cout << mem[i] << " ";
  }
  std::cout << "\n";
  return 0;
}