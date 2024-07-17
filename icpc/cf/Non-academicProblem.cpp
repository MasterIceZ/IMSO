#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto solve() -> void {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	vector<ll> sz(n + 1), b;
	vector<int> low(n + 1), idx(n + 1);
	int timer = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		idx[u] = low[u] = ++timer;
		sz[u] = 1ll;
		for(auto v: adj[u]) {
			if(v == p) {
				continue;
			}
			if(!idx[v]) {
				dfs(v, u);
				if(low[v] > idx[u]) {
					b.emplace_back((ll) v);
				}
				low[u] = min(low[u], low[v]);
				sz[u] += sz[v];
			}
			else {
				low[u] = min(low[u], idx[v]);
			}
		}
	};
	dfs(1, 0);
	ll answer = 0ll;
	for(auto v: b) {
		answer = max(answer, sz[v] * ((ll) n - sz[v]));
	}
	cout << (((ll) n * ((ll) (n - 1))) / 2) - answer << "\n";
	return ;
}

auto main(int argc, char *argv[]) -> signed {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
