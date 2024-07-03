#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> subtree_sz(n + 1), dp(n + 1);
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	function<void(int, int)> dfs = [&](int u, int p) {
		int sum_dp = 0;
		subtree_sz[u] = 1;
		for(auto v: adj[u]) {
			if(v == p) {
				continue;
			}
			dfs(v, u);
			sum_dp += dp[v];
			subtree_sz[u] += subtree_sz[v];
		}
		for(auto v: adj[u]) {
			if(v == p) {
				continue;
			}
			dp[u] = max(dp[u], sum_dp - dp[v] + subtree_sz[v] - 1);
		}
	};
	dfs(1, 0);
	cout << dp[1] << "\n";
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
