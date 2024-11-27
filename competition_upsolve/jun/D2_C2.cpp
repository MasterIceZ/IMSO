// Hello Junior Dev
 
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MxN = 1000010;
 
vector<int> adj[MxN];
bool done[MxN], heavy[MxN];
 
int dfs(int u, int p) {
  int maxx = 0, idx = -1;
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    int k = dfs(v, u);
    if(k > maxx) {
      maxx = k;
      idx = v;
    }
  }
  if(idx == -1) {
    return 1;
  }
  heavy[idx] = true;
  return 1 + maxx;
}
 
signed main(int argc, char *argv[]) {
  // cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  // cin >> n;
  scanf("%d", &n);
  for(int i=2, u, v; i<=n; ++i) {
    // cin >> u >> v;
    scanf("%d %d", &u, &v);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, 1);
  int cnt = 0;
  for(int i=1; i<=n; ++i) {
    if(heavy[i]) {
      continue;
    }
    cnt++;
  }
  printf("%d\n", cnt-1);
  return 0;
}