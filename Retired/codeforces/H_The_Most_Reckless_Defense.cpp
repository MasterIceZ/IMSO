#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int INF = std::numeric_limits<int>::max() / 2;

struct state_t {
  int v, w;
  state_t(int _v, int _w): 
    v(_v), w(_w) {}
  bool operator<(const state_t& other) const {
    return w > other.w;
  }
};

struct edge_t {
  int v, flow, cap, cost;
  edge_t(int _v, int _flow, int _cap, int _cost): 
    v(_v), flow(_flow), cap(_cap), cost(_cost) {}
  int residual() const {
    return cap - flow;
  }
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
    while(!pq.empty()) {
      state_t cur = pq.top();
      pq.pop();
      if(dist[cur.v] < cur.w) {
        continue;
      }
      for(auto idx: adj[cur.v]) {
        int v = edges[idx].v;
        int nxt = cur.w + potential[cur.v] - potential[v] + edges[idx].cost;
        if(edges[idx].residual() > 0 && dist[v] > nxt) {
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
    while(dijkstra(s, t)) {
      for(int i=0; i<n; ++i) {
        potential[i] += dist[i];
      }
      int augment = INF;
      for(int v=t; v!=s; v=edges[parent[v]^1].v) {
        augment = std::min(augment, edges[parent[v]].residual());
      }
      for(int v=t; v!=s; v=edges[parent[v]^1].v) {
        edges[parent[v]].flow += augment;
        edges[parent[v]^1].flow -= augment;
      }
      flow += augment;
      cost += augment * potential[t];
    }
    return std::make_pair(flow, cost);
  }
};

inline void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::string> a(n);
  for(auto &r: a) {
    std::cin >> r;
  }
  int sq = sqrt(n * n + m * m) + 3;
  min_cost_flow mcf(k + sq + 3);
  int s = k + sq + 1, t = k + sq + 2;
  for(int i=0; i<k; ++i) {
    mcf.add_edge(s, i, 1, 0);
  }
  for(int i=0; i<sq; ++i) {
    mcf.add_edge(k + i, t, 1, 0);
  }

  for(int i=0, x, y, p; i<k; ++i) {
    std::cin >> x >> y >> p;
    x -= 1;
    y -= 1;
    int adding = 1;
    for(int j=0; j<sq; ++j) {
      int sum = 0;
      for(int i_1=0; i_1<n; ++i_1) {
        for(int j_1=0; j_1<m; ++j_1) {
          if(a[i_1][j_1] != '#') {
            continue;
          }
          if((x - i_1) * (x - i_1) + (y - j_1) * (y - j_1) <= j * j) {
            sum += p;
          }
        }
      }
      if(sum > adding) {
        mcf.add_edge(i, k + j, 1, adding - sum);
      }
      else {
        mcf.add_edge(i, k + j, 1, 0);
      }
      adding *= 3;
      if(adding > INF) {
        break;
      }
    }
  }

  std::cout << -mcf.flow(s, t).second << "\n";
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}