#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 110;
const int MxS = 1010;
const int INF = 1e9 + 100;

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

int fw[MxN][MxN], sx[MxS], sa[MxS], sf[MxS], bx[MxS], bd[MxS];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			fw[i][j] = INF;
		}
		fw[i][i] = 0;
	}
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v;
		u -= 1;
		v -= 1;
		fw[u][v] = fw[v][u] = std::min(fw[u][v], 1);
	}
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				fw[i][j] = std::min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}
	int s, b, h;
	long long k;
	std::cin >> s >> b >> k >> h;
	for(int i=0; i<s; ++i) {
		std::cin >> sx[i] >> sa[i] >> sf[i];
		sx[i] -= 1;
	}
	for(int i=0; i<b; ++i) {
		std::cin >> bx[i] >> bd[i];
		bx[i] -= 1;
	}
	hopcroft_karp mbm(s, b);
	for(int i=0; i<s; ++i) {
		for(int j=0; j<b; ++j) {
			if(sa[i] < bd[j] || fw[sx[i]][bx[j]] > sf[i]) {
				continue;
			}
			mbm.add_edge(i, j);
		}
	}
	long long matching = (long long) mbm.max_matching();
	long long answer = matching * k;
	for(long long i=1ll; i<=(long long) s; ++i) {
		answer = std::min(answer, i * h + std::min(matching, ((long long) s) - i) * k);
	}
	std::cout << answer << "\n";
	return 0;
}
