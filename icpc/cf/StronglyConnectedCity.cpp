#include <bits/stdc++.h>

using namespace std;

const int MxN = 2020;

vector<int> adj[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}



	return 0;
}
