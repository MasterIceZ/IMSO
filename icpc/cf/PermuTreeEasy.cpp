#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;

int p[MxN];
ll subtree_size[MxN];
vector<int> adj[MxN];

void dfs_size(int u) {
  for(auto x: adj[u]) {
    dfs_size(x);
    subtree_size[u] += subtree_size[x];
  }
}

inline ll knapsack(vector<ll> v) {
  bitset<MxN> dp;
  dp[0] = true;
  for(auto x: v) {
    dp |= dp << x;
  }
  ll res = 0ll, sum = accumulate(v.begin(), v.end(), 0ll);
  for(int w=0; w<=sum; ++w) {
    if(dp[w] == 0) {
      continue;
    }
    res = max(res, w * (sum - w));
  }
  return res;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  subtree_size[0] = 1ll;
  for(int i=1; i<=n-1; ++i) {
    cin >> p[i];
    p[i] -= 1;
    adj[p[i]].emplace_back(i);
    subtree_size[i] = 1ll;
  }
  dfs_size(0);
  ll answer = 0ll;
  vector<ll> values;
  for(int i=0; i<=n-1; ++i) {
    values.clear();
    for(auto x: adj[i]) {
      values.emplace_back((ll) subtree_size[x]);
    }
    answer += knapsack(values);
  }
  cout << answer << "\n";
  return 0;
}