#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

vector<int> adj[MxN];
bitset<MxN> visited;
int cnt = 0;

void dfs(int u, int p) {
  bool gone = false;
  visited[u] = true;
  for(auto x: adj[u]) {
    if(x == p || visited[x]) { 
      continue;
    }
    gone = true;
    dfs(x, u);
  }
  cnt += !gone;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, p;
  cin >> n >> p;
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(0, -1);
  int s = (p % cnt == 0 ? 0: p % cnt == 1 ? 1: 2);
  cout << 2 * (p / cnt) + s;
  return 0;
}