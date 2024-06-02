#include <bits/stdc++.h>

using namespace std;

int n, a, b;
queue<int> q;

inline void solve() {
	cin >> n;
	cin >> a >> b;
	vector<vector<int>> adj(n + 1, vector<int> ());
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	int last = -1;
	auto bfs = [&](int stp) {
		vector<int> dist(n + 1, -1);
		q.emplace(stp);
		dist[stp] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			last = now;
			for(auto x: adj[now]) {
				if(dist[x] != -1) {
					continue;
				}
				q.emplace(x);
				dist[x] = dist[now] + 1;
			}
		}
		return dist;
	};

	bfs(1);
	vector<int> from_leaf_1 = bfs(last);
	vector<int> from_leaf_2 = bfs(last);
	vector<int> from_a = bfs(a);
	vector<int> from_b = bfs(b);

	vector<int> from_leaf(n + 1, 0);
	for(int i=1; i<=n; ++i) {
		from_leaf[i] = max(from_leaf_1[i], from_leaf_2[i]);
	}

	int answer = (int) 1e9 + 100;
	for(int i=1; i<=n; ++i) {
		int cur_max = max(from_a[i], from_b[i]);
		cur_max += ((cur_max & 1) != (from_b[i] & 1));
		answer = min(answer, cur_max - from_leaf[i]);		
	}
	
	cout << answer + 2 * (n - 1) << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
