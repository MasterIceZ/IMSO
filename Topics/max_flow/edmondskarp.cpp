// O(VE^2)
#include <bits/stdc++.h>

using namespace std;

const int MxN = 110; 
const int INF = 1e9 + 100;

int n, parent[MxN], cap[MxN][MxN];
vector<int> adj[MxN];

inline void add_edge(int u, int v, int c) {
  adj[u].emplace_back(v);
  cap[u][v] = c;
  adj[v].emplace_back(u);
}

inline int get_flow(int s, int t) {
  for(int i=1; i<=n; ++i) {
    parent[i] = -1;
  }
  queue<pair<int, int>> q;
  q.emplace(s, INF);
  parent[s] = s;
  while(!q.empty()) {
    auto [u, flow] = q.front(); q.pop();
    for(auto v: adj[u]) {
      if(cap[u][v] == 0 || parent[v] != -1) {
        continue;
      }
      parent[v] = u;
      int next_flow = min(flow, cap[u][v]);
      if(v == t) {
        return next_flow;
      }
      q.emplace(v, next_flow);
    }
  }
  return 0;
}

signed main(int argc, char *argv[]) {
  n = 6;
  add_edge(1, 2, 16);
  add_edge(1, 3, 13);
  add_edge(2, 3, 10);
  add_edge(2, 4, 12);
  add_edge(3, 2, 4);
  add_edge(3, 5, 14);
  add_edge(4, 3, 9);
  add_edge(4, 6, 20);
  add_edge(5, 4, 7);
  add_edge(5, 6, 4);
  int s = 1, t = 6, max_flow = 0;
  while(true) {
    int cur_flow = get_flow(s, t);
    if(cur_flow == 0) {
      break;
    }
    max_flow += cur_flow;
    int u = t;
    while(u != s) {
      int nxt = parent[u];
      cap[nxt][u] -= cur_flow;
      cap[u][nxt] += cur_flow;
      u = nxt;
    }
  }
  cout << "MAX FLOW = " << max_flow << "\n";
  // answer = 23
  return 0;
}