#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const int NONE = -2;

int dp[MxN], answer;
vector<int> adj[MxN];

void dfs(int u, int p) {
  int cur_deg = (int) adj[u].size();
  dp[u] = cur_deg - 2;
  int first_max = NONE, second_max = NONE;
  for(auto v: adj[u]) {
    if(v == p) {
      continue;
    }
    dfs(v, u);
    dp[u] = max(dp[u], dp[v] + cur_deg - 2);
    if(dp[v] > first_max) {
      second_max = first_max;
      first_max = dp[v];
    }
    else if(dp[v] > second_max) {
      second_max = dp[v];
    }
  }
  answer = max(dp[u], answer);
  if(first_max > NONE && second_max > NONE) {
    answer = max(answer, first_max + second_max + cur_deg - 2);
  }
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=2, u, v; i<=n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  answer = NONE;
  dfs(1, 0);
  cout << 2 + answer << "\n";
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
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