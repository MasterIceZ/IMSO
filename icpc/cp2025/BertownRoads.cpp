#include <algorithm>
#include <bitset>
#include <iostream>
#include <utility>
#include <vector>

const int MxN = 100010;

std::vector<int> adj[MxN];
std::bitset<MxN> visited;
std::vector<std::pair<int, int>> bridges;
int low[MxN], disc[MxN], timer = 0;

bool find_bridges(int u, int p) {
  visited[u] = true;
  disc[u] = low[u] = ++timer;
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    if(disc[v] == 0 || disc[v] < disc[u]) {
      bridges.emplace_back(u, v);
    }
    if(disc[v] != 0) {
      low[u] = std::min(low[u], disc[v]);
    }
    else {
      if(find_bridges(v, u)) {
        return true;
      }
      low[u] = std::min(low[u], low[v]);
      if(low[v] > disc[u]) {
        return true;
      }
    }
  }
  return false;
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    std::cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  bool found = (find_bridges(1, 0) == false);
  for(int i=1; i<=n; ++i) {
    found &= (visited[i] == true);
  }
  if(found == false) {
    std::cout << "0\n";
    return 0;
  }
  for(auto bridge: bridges) {
    std::cout << bridge.first << " " << bridge.second << "\n";
  }
  return 0;
}