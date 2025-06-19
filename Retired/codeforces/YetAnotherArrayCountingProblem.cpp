#include <iostream>
#include <stack>
#include <vector>

const int MxN = 200020;
const long long MOD = 1e9 + 7ll;

int n, m, a[MxN], l[MxN], r[MxN], root;
std::vector<std::vector<long long>> dp;

inline void build_cartesian_tree() {
	std::stack<int> st;
	root = -1;
	for(int i=1; i<=n; ++i) {
		l[i] = r[i] = 0;
	}
	for(int i=1; i<=n; ++i) {
		while(!st.empty() && a[st.top()] < a[i]) {
			l[i] = st.top();
			st.pop();
		}
		if(st.empty()) {
			root = i;
		}
		else {
			r[st.top()] = i;
		}
		st.emplace(i);
	}
}

void dfs(int u) {
	if(l[u] != 0) {
		dfs(l[u]);
	}
	if(r[u] != 0) {
		dfs(r[u]);
	}
	for(int i=1; i<=m; ++i) {
		long long val = (dp[l[u]][i - 1] * dp[r[u]][i]) % MOD;
		dp[u][i] = (dp[u][i - 1] + val) % MOD;
	}	
}

inline void solve() {
	std::cin >> n >> m;
	dp = std::vector<std::vector<long long>> (n + 1, std::vector<long long> (m + 1, 0ll));
	dp[0] = std::vector<long long> (m + 1, 1ll);
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	build_cartesian_tree();
	dfs(root);
	std::cout << dp[root][m] << "\n";
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
