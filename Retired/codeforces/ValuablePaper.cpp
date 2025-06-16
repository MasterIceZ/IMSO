#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 10010;

struct edge_t {
	int u, v, w;
	
	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge_t& o) const {
		return w < o.w;
	}
};

struct hopcroft_karp {
	int n, m;
	std::vector<std::vector<int>> adj;
	std::vector<int> l, r, dist, cur;

	hopcroft_karp(int _n, int _m):
		n(_n), m(_m), adj(_n), l(_n, -1), r(_m, -1), dist(_n, 0), cur(_n, 0) {}
	void add_edge(int u, int v) {
		adj[u].emplace_back(v);
	}
	void bfs() {
		std::queue<int> q;
		for(int i=0; i<n; ++i) {
			if(l[i] == -1) {
				q.emplace(i);
				dist[i] = 0;
			}
			else {
				dist[i] = -1;
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v: adj[u]) {
				if(r[v] != -1 && dist[r[v]] == -1) {
					dist[r[v]] = dist[u] + 1;
					q.emplace(r[v]);
				}
			}
		}
	}
	bool dfs(int u) {
		for(int &i=cur[u]; i<(int) adj[u].size(); ++i) {
			int v = adj[u][i];
			if(r[v] == -1 || dist[r[v]] == dist[u] + 1 && dfs(r[v])) {
				l[u] = v;
				r[v] = u;
				return true;
			}
		}
		return false;
	}
	int max_matching() {
		int cnt = 0;
		while(true) {
			bfs();
			std::fill(cur.begin(), cur.end(), 0);
			int local_cnt = 0;
			for(int u=0; u<n; ++u) {
				if(l[u] == -1) {
					local_cnt += dfs(u);
				}
			}
			if(local_cnt == 0) {
				break;
			}
			cnt += local_cnt;
		}
		return cnt;
	}
};

int n, m;
std::vector<edge_t> edges;

inline bool ok(int mid) {
	hopcroft_karp mbm(n, n);
	for(int i=0; i<=mid; ++i) {
		mbm.add_edge(edges[i].u, edges[i].v);
	}
	return mbm.max_matching() == n;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	for(int i=1, u, v, w; i<=m; ++i) {
		std::cin >> u >> v >> w;
		edges.emplace_back(--u, --v, w);
	}
	std::sort(edges.begin(), edges.end());
	int l = 0, r = m - 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(ok(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	std::cout << (ok(l) ? edges[l].w : -1) << "\n";
	return 0;
}
