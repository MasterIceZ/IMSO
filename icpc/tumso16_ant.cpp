#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const int LG = 22;

vector<pair<int, ll>> adj[MxN];
int lift[LG][MxN], level[MxN];
ll w, dist[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=2, v; i<=n; ++i) {
		cin >> v >> w;
		v++;
		adj[i].emplace_back(v, w);
		adj[v].emplace_back(i, w);	
	}
	function<void (int, int)> dfs = [&](int u, int p) {
		lift[0][u] = p;
		level[u] = level[p] + 1;
		for(auto &[v, w]: adj[u]) {
			if(v == p) {
				continue;
			}
			dist[v] = dist[u] + w;
			dfs(v, u);
		}
	};
	dfs(1, 0);
	for(int state=1; state<LG; ++state) {
		for(int u=1; u<=n; ++u) {
			lift[state][u] = lift[state - 1][lift[state - 1][u]];
		}
	}
	auto lca = [&](int u, int v) {
		if(level[u] > level[v]) {
			swap(u, v);
		}
		for(int state=LG-1; state>=0; --state) {
			if(level[u] > level[lift[state][v]]) {
				continue;
			}
			v = lift[state][v];
		}
		if(u == v) {
			return u;
		}
		for(int state=LG-1; state>=0; --state) {
			if(lift[state][u] == lift[state][v]) {
				continue;
			}
			u = lift[state][u];
			v = lift[state][v];
		}
		return lift[0][u];
	};
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		u++, v++;
		cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << "\n";
	}
	return 0;
}
