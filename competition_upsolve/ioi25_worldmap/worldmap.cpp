#include "worldmap.h"

#include <vector>

std::vector<std::vector<int>> create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
  std::vector<std::vector<int>> adj(N + 1);
  for(int i=0; i<M; ++i) {
    int u = A[i], v = B[i];
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int cur = -1;
  for(int i=1; i<=N; ++i) {
    if((int) adj[i].size() != 1) {
      continue;
    }
    cur = i;
    break;
  }

  int parent = -1;
  std::vector<std::vector<int>> world_map;
  for(int i=0; i<N; ++i) {
    world_map.emplace_back(std::vector<int> (N, cur));
    int last_cur = cur;
    for(auto v: adj[cur]) {
      if(v == parent) {
        continue;
      }
      cur = v;
      break;
    }
    parent = last_cur;
  }

  return world_map;
}
