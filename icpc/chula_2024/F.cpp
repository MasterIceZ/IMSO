#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;

int n, c;
vector<pair<int, ll>> adj[MxN];
ll w, sum_w;
vector<int> odd_deg;

void dfs(int u, int p) {
	if(adj[u].size() % 2 == 1) {
		odd_deg.emplace_back(u);
	}
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> c;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		sum_w += w;
	}
	dfs(1, 0);
	ll cost = sum_w + c * odd_deg.size() / 2ll;
	cout << cost << " " << odd_deg.size() / 2ll << "\n";
	// number nodes with odd deg is always even!
	for(int i=0; i<(int) odd_deg.size(); i+=2) {
		cout << odd_deg[i] << " " << odd_deg[i + 1] << "\n";
	}
	return 0;
}
