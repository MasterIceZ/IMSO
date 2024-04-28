#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

ll c[MxN], answer[MxN];
vector<int> adj[MxN];
map<ll, ll> color_count[MxN], sum_count[MxN];

void merge(int idx_x, int idx_y) {
	if(color_count[idx_x].size() < color_count[idx_y].size()) {
		swap(color_count[idx_x], color_count[idx_y]);
		swap(sum_count[idx_x], sum_count[idx_y]);
	}
	for(auto e: color_count[idx_y]) {
		if(color_count[idx_x].count(e.first)) {
			sum_count[idx_x][color_count[idx_x][e.first]] -= e.first;
		}
		color_count[idx_x][e.first] += e.second;
		sum_count[idx_x][color_count[idx_x][e.first]] += e.first;
	}
}

void dfs(int u, int p) {
	color_count[u][c[u]] += 1;
	sum_count[u][1] += c[u];
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		merge(u, x);
	}
	answer[u] = sum_count[u].rbegin()->second;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> c[i];
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}
