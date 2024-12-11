#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

vector<int> adj[MxN];
int a[MxN], cur;

void dfs(int u, int p) {
	a[u] = cur;
	cur++;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		while(cur != a[u] + 1 && ((cur - a[u]) % 2 == 1 || cur - a[u] == 2)) {
			cur++;
		}
		dfs(v, u); 
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
	cur = 1;
	dfs(1, 0);
	for(int i=1; i<=n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
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
