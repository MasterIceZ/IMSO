#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 220;

struct state_t {
	int v, w, mask;
	state_t(int _v, int _w, int _mask):
		v(_v), w(_w), mask(_mask) {}
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
};

int mask[17], floyd_warshall[MxN][MxN], dist[17][1 << 15];
vector<int> visiting;
vector<pair<int, int>> adj[17];
priority_queue<state_t> pq;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	memset(floyd_warshall, 0x3f, sizeof floyd_warshall);
	for(int i=0; i<n; ++i) {
		floyd_warshall[i][i] = 0;
	}
	for(int i=0, x; i<k; ++i) {
		cin >> x;
		x--;
		mask[i] = (1 << i);
		visiting.emplace_back(x);
	}
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		u--, v--;
		floyd_warshall[u][v] = floyd_warshall[v][u] = min(floyd_warshall[v][u], w);
	}
	for(int _k=0; _k<n; ++_k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				floyd_warshall[i][j] = min(floyd_warshall[i][j], floyd_warshall[i][_k] + floyd_warshall[_k][j]);
			}
		}
	}
	for(int i=0; i<k; ++i) {
		int u = visiting[i];
		for(int j=i+1; j<k; ++j) {
			int v = visiting[j];
			adj[i].emplace_back(j, floyd_warshall[u][v]);
			adj[j].emplace_back(i, floyd_warshall[v][u]);
		}
		adj[i].emplace_back(k, floyd_warshall[u][0]);
		adj[k].emplace_back(0, floyd_warshall[0][u]);
		adj[i].emplace_back(k + 1, floyd_warshall[u][n-1]);
		adj[k + 1].emplace_back(i, floyd_warshall[n-1][u]);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(k, dist[k][0] = 0, 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now.v]) {
			int nxt = x.second + now.w;
			int nxt_mask = (now.mask | mask[x.first]);
			if(dist[x.first][nxt_mask] > nxt) {
				pq.emplace(x.first, dist[x.first][nxt_mask] = nxt, nxt_mask);
			}
		}
	}
	cout << dist[k + 1][(1 << k) - 1] << "\n";
	return 0;
}
