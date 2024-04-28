#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int dist[MxN], h[MxN], c[MxN];
vector<int> adj[MxN];
queue<int> q;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i) {
		cin >> h[i];
	}
	for(int i=1; i<=k; ++i) {
		cin >> c[i];
	}
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=k; ++i) {
		dist[c[i]] = 0;
		q.emplace(c[i]);
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto x: adj[now]) {
			if(dist[x] != -1 || h[now] >= h[x]) {
				continue;
			}
			dist[x] = dist[now] + 1;
			q.emplace(x);
		}
	}
	for(int i=1; i<=n; ++i) {
		cout << dist[i] << "\n";
	}
	return 0;
}
