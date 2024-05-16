#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN];
vector<int> adj[MxN];
multiset<int> s[MxN];

inline void merge(multiset<int> &x, multiset<int> &y) {
	if(x.size() < y.size()) {
		swap(x, y);
	}
	for(auto e: y) {
		x.emplace(e);
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
	auto it = s[u].upper_bound(a[u]);
	if(it != s[u].end()) {
		s[u].erase(it);
	}
	s[u].emplace(a[u]);
}	

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		u++, v++;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	cout << n - (int) s[1].size() << "\n";
	return 0;
}
