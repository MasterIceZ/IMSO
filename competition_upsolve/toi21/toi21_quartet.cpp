#include <iostream>
#include <vector>

const int MxN = 200020;
const long long MOD = 1000000007ll;

int n, m;
std::vector<int> adj[MxN];
long long dp[4][MxN];

void dfs(int u, int p) {
	if(u <= n) {
		dp[0][u] = 1ll;
		return ;
	}
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
		for(int i=3; i>=1; --i) {
			long long to_add = (dp[i - 1][u] * dp[0][v]) % MOD;
			dp[i][u] = (dp[i][u] + to_add) % MOD;
		}
		dp[0][u] = (dp[0][u] + dp[0][v]) % MOD;
	}
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	for(int i=1, u, v; i<=n+m-1; ++i) {
		std::cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(n + 1, 0);
	long long answer = 0ll;
	for(int i=n+1; i<=n+m; ++i) {
		answer = (answer + dp[3][i]) % MOD;
		long long to_add = (dp[2][i] * ((long long) (n) - dp[0][i])) % MOD;
		answer = (answer + to_add) % MOD;
	}
	std::cout << answer << "\n";
	return 0;
}
