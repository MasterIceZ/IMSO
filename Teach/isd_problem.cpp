#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int FALLBACK_COST = 1000;
const int INF = std::numeric_limits<int>::max() / 2;

// ICY MIN COST FLOW
// SEE: https://github.com/MasterIceZ/IMSO/blob/main/ICY_STD_TEMPLATE/min_cost_flow.hpp
struct state_t {
  int v, w;
  state_t(int _v, int _w) : v(_v), w(_w) {}
  bool operator<(const state_t& other) const { return w > other.w; }
};

struct edge_t {
  int v, flow, cap, cost;
  edge_t(int _v, int _flow, int _cap, int _cost)
    : v(_v), flow(_flow), cap(_cap), cost(_cost) {}
  int residual() const { return cap - flow; }
};

struct min_cost_flow {
  int n;
  std::vector<edge_t> edges;
  std::vector<std::vector<int>> adj;
  std::vector<int> dist, parent, potential;

  min_cost_flow(int _n) {
    n = _n;
    adj.resize(n);
  }
  void add_edge(int u, int v, int cap, int cost) {
    adj[u].emplace_back(edges.size());
    edges.emplace_back(v, 0, cap, cost);
    adj[v].emplace_back(edges.size());
    edges.emplace_back(u, 0, 0, -cost);
  }
  bool dijkstra(int s, int t) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    std::priority_queue<state_t> pq;
    pq.emplace(s, dist[s] = 0);
    while (!pq.empty()) {
      state_t cur = pq.top();
      pq.pop();
      if (dist[cur.v] < cur.w) {
        continue;
      }
      for (auto idx : adj[cur.v]) {
        int v = edges[idx].v;
        int nxt = cur.w + potential[cur.v] - potential[v] + edges[idx].cost;
        if (edges[idx].residual() > 0 && dist[v] > nxt) {
          parent[v] = idx;
          pq.emplace(v, dist[v] = nxt);
        }
      }
    }
    return dist[t] < INF;
  }

  std::pair<int, int> flow(int s, int t) {
    int flow = 0, cost = 0;
    potential.assign(n, 0);
    while (dijkstra(s, t)) {
      for (int i = 0; i < n; ++i) {
        potential[i] += dist[i];
      }
      int augment = INF;
      for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
        augment = std::min(augment, edges[parent[v]].residual());
      }
      for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
        edges[parent[v]].flow += augment;
        edges[parent[v] ^ 1].flow -= augment;
      }
      flow += augment;
      cost += augment * potential[t];
    }
    return std::make_pair(flow, cost);
  }
};

signed main(int argc, char *argv[]) {
  int person = 8, groups = 3;

  std::vector<int> capacity = {3, 3, 2};
  std::vector<std::vector<int>> prefs = {
    {0, 1},
    {0, 1},
    {0, 1},
    {1, 2},
    {1, 2},
    {1, 2},
    {0},
    {2}
  };

  int source = person + groups;
  int sink = source + 1;

  min_cost_flow mcmf(sink + 1);

  for(int i=0; i<person; ++i) {
    mcmf.add_edge(source, i, 1, 0);
  }
  for(int i=0; i<person; ++i) {
    std::vector<bool> used(groups, 0);
    for(int j=0; j<(int) prefs[i].size(); ++j) {
      int g = prefs[i][j];
      mcmf.add_edge(i, person + g, 1, j);
      used[g] = true;
    }
    for(int j=0; j<groups; ++j) {
      if(used[j]) {
        continue;
      }
      mcmf.add_edge(i, person + j, 1, FALLBACK_COST);
    }
  }

  for(int i=0; i<groups; ++i) {
    mcmf.add_edge(person + i, sink, capacity[i], 0);
  }

  std::pair<int, int> flow = mcmf.flow(source, sink);

  if(flow.first < person) {
    std::cerr << "Not enough capacity for all persons.\n";
    exit(1);
  }

  std::vector<int> assignment(person, -1);
  for(int u=0; u<person; ++u) {
    for(auto x: mcmf.adj[u]) {
      auto e = mcmf.edges[x];
      if(e.flow == 1 && e.v >= person && e.v < sink) {
        assignment[u] = e.v - person;
      }
    }
  }
  for(int i = 0; i < person; ++i) {
    std::cout << "Person " << i << " assigned to group " << assignment[i] << "\n";
  }
  std::cout << "Total cost: " << flow.second << "\n";
  return 0;
}