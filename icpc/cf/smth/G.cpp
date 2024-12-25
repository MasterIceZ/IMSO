#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int n, deg[MxN];
vector<int> adj[MxN];

inline void solve() {
  cin >> n;
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }
  int first_max = -1, second_max = -1;
  int first_idx = -1, second_idx = -1;
  for(int i=1; i<=n; ++i) {
    if(deg[i] > second_max) {
      second_max = deg[i];
      second_idx = i;
    }
    if(second_max > first_max) {
      swap(first_max, second_max);
      swap(first_idx, second_idx);
    }
  }
  
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}