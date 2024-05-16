#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int c[MxN], sz[MxN];
vector<int> adj[MxN];
set<int> s[MxN];

void merge(set<int> &a, set<int> &b) {
	if(a.size() < b.size()) {
		swap(a, b);
	}
	for(auto x: b) {
		a.emplace(x);
	}
}

void dfs(int u, int p) {
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		merge(s[u], s[x]);
	}
	sz[u] = (int) s[u].size();
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> c[i];
		s[i].emplace(c[i]);
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
