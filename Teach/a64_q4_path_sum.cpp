#include <bits/stdc++.h>

using namespace std;

const int MxN = 22;

int k[10], want;
bool can;
bitset<MxN> visited;
vector<pair<int, int>> adj[MxN];

void rec(int u, int current_sum) {
	if(can == true) {
		return ;
	}
	if(current_sum == want) {
		can = true;
		return ;
	}
	for(auto x: adj[u]) {
		if(visited[x.first] || current_sum + x.second > want) {
			continue;
		}
		visited[x.first] = true;
		rec(x.first, current_sum + x.second);
		visited[x.first] = false;
		if(can == true) {
			return ;
		}
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=8; ++i) {
		cin >> k[i];
	}
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		u++, v++;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=8; ++i) {
		can = false;
		want = k[i];
		for(int stp=1; stp<=n; ++stp) {
			visited[stp] = true;
			rec(stp, 0);
			visited[stp] = false;
		}
		cout << (can ? "YES": "NO") << "\n";
	}
	return 0;
}
