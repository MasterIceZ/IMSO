#include <bits/stdc++.h>

using namespace std;

const int MxN = 10010;
const int MxK = 11;

vector<pair<int, int>> adj[MxN];
int u[MxK], v[MxK], w[MxK], dp[2][MxN];
set<int> st;

void dfs(int u, int p) {
	dp[0][u] = dp[1][u] = 0;
	int maxx = 0;
	for(auto x: adj[u]) {
		if(x.first == p) {
			continue;
		}
		dfs(x.first, u);
		dp[0][u] += max(dp[0][x.first], dp[1][x.first]);	
		maxx = max(maxx, x.second + dp[0][x.first] - dp[1][x.first]);
	}
	if(st.count(u)) {
		dp[1][u] = dp[0][u];
		dp[0][u] = -1e9 - 100;
	}
	else {
		dp[1][u] = dp[0][u] + maxx;
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=2, u, v, w; i<=n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=0; i<=k-1; ++i) {
		cin >> u[i] >> v[i] >> w[i];
	}
	int max_mask = (1 << k) - 1, answer = 0;
	for(int mask=0; mask<=max_mask; ++mask) {
		bool ok = true;
		st.clear();
		int cst = 0;
		for(int b=0; b<k; ++b) {
			int this_mask = (1 << b);
			if(!(mask & this_mask)) {
				continue;
			}
			if(st.count(u[b]) || st.count(v[b])) {
				ok = false;
				break;
			}
			st.emplace(u[b]);
			st.emplace(v[b]);
			cst += w[b];
		}
		if(!ok) {
			continue;
		}
		dfs(1, 0);
		answer = max(answer, max(dp[0][1], dp[1][1]) + cst);
	}
	cout << answer << "\n";
	return 0;
}
