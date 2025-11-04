#include <iostream>

const int MxN = 1000010;
const long long MOD = 1e9 + 7ll;

long long dp[MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	dp[0] = dp[1] = 1ll;
	for(int i=2; i<=n; ++i) {
		dp[i] = dp[i - 1];

	}
	return 0;
}
