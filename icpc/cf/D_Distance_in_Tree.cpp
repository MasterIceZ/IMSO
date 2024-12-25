#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 50050;
const int MxK = 550;

int k;
vector<int> adj[MxN];
ll dp[MxK][MxN], answer;

void dfs(int u, int p) {
  dp[0][u] = 1ll;
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    dfs(v, u);
    for(int i=0; k-i-1>=0; ++i) {
      answer += dp[i][u] * dp[k - i - 1][v];
    }
    for(int i=1; i<=k; ++i) {
      dp[i][u] += dp[i - 1][v];
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n >> k;
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, 0);
  cout << answer << "\n";
  return 0;
}