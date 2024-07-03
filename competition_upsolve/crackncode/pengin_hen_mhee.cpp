#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;

vector<int> adj[MxN];
int dist[MxN];
queue<int> q;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for(int i=1, l, r; i<=m; ++i) {
		cin >> l >> r;
		l--;
		adj[l].emplace_back(r);
		adj[r].emplace_back(l);
	}
	for(int i=1; i<=n; ++i) {
		adj[i - 1].emplace_back(i);
		adj[i].emplace_back(i - 1);

		dist[i] = -1;
	}

	dist[0] = 0;
	q.emplace(0);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now == n) {
			cout << dist[n] << "\n";
			return 0;
		}
		for(auto x: adj[now]) {
			if(dist[x] != -1) {
				continue;
			}
			dist[x] = dist[now] + 1;
			q.emplace(x);
		}
	}
	cout << dist[n] << "\n";

	return 0;
}
