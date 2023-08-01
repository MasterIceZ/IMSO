#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
bitset<MxN> visited;

void dfs(int u, int p) {
	visited[u] = true;
	for(auto x: adj[u]) {
		if(x == p || visited[x]) {
			continue;
		}
		dfs(x, u);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i=1; i<=n; ++i) {
		if(visited[i]) {
			continue;
		}
		dfs(i, 0);
		cnt++;
	}
	cout << cnt;
	return 0;
}
