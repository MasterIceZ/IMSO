#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

const int MxN = 100010;

int n, m;
vector<int> adj[MxN];
map<pair<int, int>, bool> have;
pair<int, int> dp[MxN];
bitset<MxN> done;

void dfs(int u, int p) {
	done[u] = true;
	dp[u] = make_pair(adj[u].size(), adj[u].size());
	for(auto x: adj[u]) {
		if(x == u || done[x]) {
			continue;
		}
		dfs(x, u);
		dp[u] = make_pair(
			min(dp[u].first, dp[x].first),
			max(dp[u].second, dp[x].second)
		);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		pair<int, int> t = minmax(u, v);
		if(have[t]) {
			continue;
		}
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		have[t] = true;
	}
	int answer = 0;
	for(int i=1; i<=n; ++i) {
		if(done[i]) {
			continue;
		}
		dfs(i, 0);
		answer = max(answer, dp[i].second - dp[i].first);
	}
	cout << answer;
	return 0;
}
