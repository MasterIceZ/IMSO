#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

vector<int> adj[MxN];
set<int> color[MxN];
int sz[MxN];

void merge(set<int> &a, set<int> &b) {
	if(a.size() < b.size()) {
		swap(a, b);
	}
	for(auto e: b) {
		a.emplace(e);
	}	
}

void dfs(int u, int p) {
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
		merge(color[u], color[v]);
	}
	sz[u] = color[u].size();
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1, c; i<=n; ++i) {
		cin >> c;
		color[i].emplace(c);
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i) {
		cout << sz[i] << " ";
	}
	cout << "\n";
	return 0;
}
