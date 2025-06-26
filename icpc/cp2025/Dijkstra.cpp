#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MxN = 100010;
const long long INF = 1e18 + 100ll;

struct state_t {
  int u;
  long long w;

  state_t(int _u, long long _w): 
    u(_u), w(_w) {}
  bool operator < (const state_t &o) const {
    return w > o.w;
  }
};

std::vector<std::pair<int, long long>> adj[MxN];
std::priority_queue<state_t> pq;
long long w, dist[MxN];
int parent[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, long long>> adj[n + 1];
  for(int i=1, u, v; i<=m; ++i) {
    std::cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  memset(dist, 0x3f, sizeof(dist));
  pq.emplace(1, dist[1] = 0);
  while(!pq.empty()) {
    state_t cur = pq.top();
    pq.pop();
    for(auto [v, w]: adj[cur.u]) {
      long long nxt = cur.w + w;
      if(dist[v] > nxt) {
        pq.emplace(v, dist[v] = nxt);
        parent[v] = cur.u;
      }
    }
  }
  if(dist[n] >= INF) {
    std::cout << "-1\n";
    return 0;
  }
  std::vector<int> p;
  for(int u=n; u!=1; u=parent[u]) {
    p.emplace_back(u);
  }
  p.emplace_back(1);
  std::reverse(p.begin(), p.end());
  for(auto u: p) {
    std::cout << u << " ";
  }
  return 0;
}