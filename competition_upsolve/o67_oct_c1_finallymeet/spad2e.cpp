#include "finallymeet.h"
#include <bits/stdc++.h>
using namespace std;
 
const int MX = 3e5 + 3;
 
vector<int> adj[MX];
int sz[MX], color[MX];
bool vis[MX], vis2[MX];
 
void dfs(int u, int prt=MX-1) {
  if (vis[u]) return;
  vis[u] = 1;
  sz[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v]) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
 
int check_bipartite(int u, int prt=MX-1) {
  if (vis2[u]) return 0;
  vis2[u] = 1;
  color[u] = 1-color[prt];
  int ret = color[u];
  for (auto v : adj[u]) if (color[u] == color[v]) return -1;
  for (auto v : adj[u]) {
    int b = check_bipartite(v, u);
    if (b == -1) return -1;
    else ret += b;
  }
  return ret;
}
 
long long count_init(int N, int M, vector<int> U, vector<int> V) {
  for (int i = 0; i < M; ++i) {
    adj[U[i]].push_back(V[i]);
    adj[V[i]].push_back(U[i]);
  }
  for (int i = 0; i < MX; ++i) color[i] = -1;
  color[MX-1] = 0;
   
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    dfs(i);
    int val = check_bipartite(i);
    if (val == -1) {
      cerr << i << "val == -1\n";
      ans += (long long)sz[i]*sz[i];
    }
    else {
      cerr << i << "val != -1\n";
      ans += (long long)val*val + (long long)(sz[i] - val)*(sz[i] - val);
    }
  }
  return ans;
}