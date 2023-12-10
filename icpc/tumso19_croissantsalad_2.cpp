#include <bits/stdc++.h>

using namespace std;

struct hopcroft_karp {
	int n, m;
	vector<vector<int>> adj;
	vector<int> l, r, dist, cur;
	void add_edge(int u, int v) {
		adj[u].emplace_back(v);
	}
	void bfs() {
		queue<int> q;
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
			int now = q.front(); q.pop();
			for(auto x: adj[now]) {
				if(r[x] != -1 && dist[r[x]] == -1) {
					dist[r[x]] = dist[now] + 1;
					q.emplace(r[x]);
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
		int match = 0;
		while(1) {
			bfs();
			fill(cur.begin(), cur.end(), 0);
			int cnt = 0;
			for(int u=0; u<n; ++u) {
				if(l[u] == -1) {
					 cnt += dfs(u);
				}
			}
			if(cnt == 0) {
				break;
			}
			match += cnt;
		}
		return match;
	}
	hopcroft_karp(int _n, int _m):
		n(_n), m(_m), adj(_n), l(_n, -1), r(_m, -1), dist(_n, 0), cur(_n, 0) {}
};

int main() {
	int n, m;
	cin >> n >> m;
	hopcroft_karp mbm(n, n);
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		mbm.add_edge(u - 1, v - 1);
	}
	//cerr << "D: " << mbm.max_matching() << "\n";
	cout << n + m - mbm.max_matching() * 2 << "\n";
	return 0;
}
