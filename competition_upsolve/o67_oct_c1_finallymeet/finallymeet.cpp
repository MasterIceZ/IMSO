#include "finallymeet.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 300030;

vector<int> adj[MxN];
int color[MxN], dist[MxN];
queue<int> q;

bool bipartite_check(int u, int p, int c) {
  if(color[u] != 0) {
    if(color[u] == c) {
      return true;
    }
    else {
      return false;
    }
  }
  color[u] = c;
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    if(bipartite_check(v, u, 3 - c) == false) {
      return false;
    }
  }
  return true;
}

inline array<ll, 2> bfs(int stp) {
  array<ll, 2> cnt = {0ll, 0ll};
  dist[stp] = 1;
  cnt[dist[stp] % 2] += 1;
  q.emplace(stp);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v: adj[u]) {
      if (dist[v] != -1) {
        continue;
      }
      dist[v] = dist[u] + 1;
      cnt[dist[v] % 2] += 1;
      q.emplace(v);
    }
  }
  return cnt;
}

inline ll square(ll x) {
  return x * x;
}

long long count_init(int N, int M, std::vector<int> U, std::vector<int> V) {
  for(int i=0; i<N; ++i) {
    dist[i] = -1ll;
  }
  for(int i=0; i<M; ++i) {
    int u = U[i], v = V[i];
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  ll answer = 0ll;
  for(int i=0; i<N; ++i) {
    if(dist[i] != -1) {
      continue;
    }
    array<ll, 2> cnt = bfs(i);
    if(bipartite_check(i, -1, 1) == true) {
      answer += square(cnt[0]) + square(cnt[1]);
    }
    else {
      answer += square(cnt[0] + cnt[1]);
    }
  }
  return answer;
}