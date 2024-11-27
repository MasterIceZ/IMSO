#include "reunion.h"
#include <bits/stdc++.h>

using namespace std;

namespace lemon {

const int MxN = 2020;

struct state_t {
  int v;
  long long w;
  bool operator < (const state_t& o) const {
    return w > o.w;
  }
  state_t(int _v, long long _w): 
    v(_v), w(_w) {}
};

priority_queue<state_t> pq;
vector<pair<int, long long>> adj[MxN];
int parent[MxN], N;
long long dist[MxN];
pair<int, long long> target;

inline void dijkstra(int stp) {
  for(int i=0; i<N; ++i) {
    dist[i] = 1e18 + 100ll;
    parent[i] = -1;
  }
  pq.emplace(stp, dist[stp] = 0ll);
  while(!pq.empty()) {
    state_t now = pq.top();
    pq.pop();
    for(auto [v, w]: adj[now.v]) {
      long long next_dist = now.w + w;
      if(next_dist < dist[v]) {
        pq.emplace(v, dist[v] = next_dist);
        parent[v] = now.v;
      }
    }
  }
}

void lemon_init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W, int u) {
  lemon::N = N;
  for(int i=0; i<M; ++i) {
    adj[U[i]].emplace_back(V[i], W[i]);
    adj[V[i]].emplace_back(U[i], W[i]);
  }

  target = make_pair(-1, 1e18 + 100ll);
  for(int i=0; i<N; ++i) {
    dijkstra(i);
    long long local = dist[N - 1];
    for(int j=0; j<N; ++j) {
      local = max(local, dist[j]);
    }
    if (local < target.second) {
      target = make_pair(i, local);
    }
  }
  dijkstra(target.first);
}

int lemon_move(int u) { 
  return u == target.first ? u : parent[u]; 
}

} // namespace lemon