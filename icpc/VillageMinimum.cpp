#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int move_to[MxN], all_length = 0;

void dfs(int u, int p) {
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		if(move_to[x] == x) {
			all_length += 2;
			swap(move_to[x], move_to[u]);
		}
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i=1; i<=n; ++i) {
		move_to[i] = i;
	}
	dfs(1, 0);
	if(move_to[1] == 1) {
		all_length += 2;
		swap(move_to[1], move_to[adj[1][0]]);
	}
	cout << all_length << "\n";
	for(int i=1; i<=n; ++i) {
		cout << move_to[i] << " ";
	}
	cout << "\n";
	return 0;
}
