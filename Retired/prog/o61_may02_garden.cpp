#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;
const int MxC = 10;
const ll MOD = 1e6 + 3;

vector<int> adj[MxN];
int color[MxN];
ll dp[MxN][1 << MxC];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, c;
  cin >> n >> m >> c;
  for(int i=1; i<=n; ++i) {
    cin >> color[i];
    color[i] = (1 << color[i]);
    dp[i][color[i]] = 1ll;
  }
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    u++, v++;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int max_mask = (1 << c) - 1;
  for(int cur_mask=0; cur_mask<=max_mask; ++cur_mask) {
    for(int from=1; from<=n; ++from) {
      if(dp[from][cur_mask] == 0) {
        continue;
      }
      for(auto to: adj[from]) {
        if(cur_mask & color[to]) {
          continue;
        }
        int next_mask = (cur_mask ^ color[to]);
        dp[to][next_mask] = (dp[to][next_mask] + dp[from][cur_mask]) % MOD;
      }
    }
  }
  ll res = 0ll;
  for(int i=1; i<=n; ++i) {
    res = (res + dp[i][max_mask]) % MOD;
  }
  cout << res << "\n";
  return 0;
}