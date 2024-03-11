#include "findhome.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 330;

vector<int> adj[MxN];
int dist[MxN][MxN];
bitset<MxN> available;

int find_home(int N, int M, vector<pair<int, int>> R) {
  for(int i=1; i<=N; ++i) {
    for(int j=1; j<=N; ++j) {
      dist[i][j] = N;
    }
  }
  for(auto edge: R) {
    dist[edge.first + 1][edge.second + 1] = dist[edge.second + 1][edge.first + 1] = 1;
    adj[edge.first + 1].emplace_back(edge.second + 1);
    adj[edge.second + 1].emplace_back(edge.first + 1);
  }
  for(int k=1; k<=N; ++k) {
    for(int i=1; i<=N; ++i) {
      for(int j=1; j<=N; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  available.set();
  int cnt_available = N;
  while(cnt_available > 1) {
    pair<int, int> c = make_pair(N, -1);
    for(int u=1; u<=N; ++u) {
      if(!available[u]) {
        continue;
      }
      int maxx = 0;
      for(auto v: adj[u]) {
        int cnt = 0;
        for(auto w: adj[v]) {
          cnt += available[w];
        }
        maxx = max(maxx, cnt);
      }
      c = min(c, make_pair(maxx, u));
    }
    if(check(c.second - 1)) {
      return c.second - 1;
    }
    for(auto x: adj[u]) {
      
    }
  }
  return 0;
}
