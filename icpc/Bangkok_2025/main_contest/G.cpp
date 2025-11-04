#include <iostream>
#include <vector>

const int MxN = 200020;
const long long INF = 1e18 + 100ll;
const int MxS = 8;

struct point_t {
	long long x, y, z;
};

std::vector<std::pair<int, long long>> adj[MxN];
point_t pts[MxN];
long long answer = -INF, dp[MxS][MxN];

void dfs(int u, int p) {
	for(int state=0; state<MxS; ++state) {
		int i = (state & 4), j = (state & 2), k = (state & 1);
		long long s = 0ll;
		s += (i != 0 ? pts[u].x : -pts[u].x);
		s += (j != 0 ? pts[u].y : -pts[u].y);
		s += (k != 0 ? pts[u].z : -pts[u].z);
		dp[state][u] = s;
	}
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
		for(int state=0; state<MxS; ++state) {
			int state_2 = ((state & 4) ^ 4) | ((state & 2) ^ 2) | ((state & 1) ^ 1);
			answer = std::max(answer, dp[state][u] + dp[state_2][v] + w);
		}
		for(int state=0; state<MxS; ++state) {
			dp[state][u] = std::max(dp[state][u], dp[state][v] + w);
		}
	}
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int i=2, u, v, w; i<=n; ++i) {
		std::cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i) {
		std::cin >> pts[i].x >> pts[i].y >> pts[i].z;
	}
	dfs(1, 0);
	std::cout << answer << "\n";
	return 0;
}
