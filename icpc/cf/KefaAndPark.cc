#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

vector<int> adj[MxN];
int c[MxN], cnt, m;

void dfs(int u, int p, int cur_cnt) {
  if(c[u]) {
    cur_cnt++;
  }
  else {
    cur_cnt = 0;
  }
  if(cur_cnt > m) {
    return ;
  }
  bool gone = false;
  for(auto x: adj[u]) {
    if(x == p) {
      continue;
    }
    dfs(x, u, cur_cnt);
    gone = true;
  }
  if(!gone) {
    cnt++;
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> c[i];
  }
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, 0, 0);
  cout << cnt << "\n";
  return 0;
} 