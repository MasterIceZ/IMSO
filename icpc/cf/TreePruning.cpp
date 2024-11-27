#include <bits/stdc++.h>

using namespace std;

const int MxN = 500050;

vector<int> adj[MxN];
int level[MxN], dp[MxN], cnt[MxN];

void dfs(int u, int p) {
	level[u] = level[p] + 1;
	dp[u] = level[u];
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
		dp[u] = max(dp[u], dp[v]);
	}
}

inline void solve() {
	int n;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int i=2; i<=n; ++i) {
		cnt[1]++;
		cnt[level[i]]--;
		cnt[dp[i] + 1]++;
	}
	for(int i=1; i<=n + 1; ++i) {
		cnt[i] += cnt[i - 1];
	}
	cout << *min_element(cnt + 1, cnt + n + 2) << "\n";
	for(int i=1; i<=n + 1; ++i) {
		adj[i].clear();
		cnt[i] = 0;
		dp[i] = 0;
		level[i] = 0;
	}
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
