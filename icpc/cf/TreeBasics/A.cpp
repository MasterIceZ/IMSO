#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;

vector<int> adj[MxN];
queue<int> q;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	vector<int> dist(n + 1, -1);
	auto bfs = [&](int stp) {
		dist = vector<int> (n + 1, -1);
		q.emplace(stp);
		dist[stp] = 0;
		int last = stp;
		while(!q.empty()) {
			int now = q.front(); q.pop();
			last = now;
			for(auto v: adj[now]) {
				if(dist[v] != -1) {
					continue;
				}
				q.emplace(v);
				dist[v] = dist[now] + 1;
			}
		}
		return last;
	};
	int t = bfs(1);
	int res = *max_element(dist.begin() + 1, dist.end());
	bfs(t);
	cout << 3 * max(res, *max_element(dist.begin() + 1, dist.end())) << "\n";
	return 0;
}
