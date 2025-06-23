#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

const int MxN = 220;

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

std::string s[MxN];
int n, m;

inline bool in_bound(int i, int j) {
	return 0 <= i && 0 <= j && i < n && j < m;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	for(int i=0; i<n; ++i) {
		std::cin >> s[i];
	}
	int cnt = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(s[i][j] != '#') {
				continue;
			}
			cnt++;
			cnt -= (in_bound(i - 1, j) && s[i - 1][j] == '#');
			cnt -= (in_bound(i, j - 1) && s[i][j - 1] == '#');
		}
	}

	std::cerr << cnt << "\n";

	return 0;
}
