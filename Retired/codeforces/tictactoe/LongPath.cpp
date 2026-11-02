#include <iostream>

const long long MOD = 1e9 + 7ll;

long long dp[1010];

inline void solve() {
	int n;
	std::cin >> n;
	long long answer = 0ll;
	for(int i=1, p; i<=n; ++i) {
		std::cin >> p;
		dp[i] = 2;
		for(int j=p; j<i; ++j) {
			dp[i] = (dp[i] + dp[j]) % MOD;
		}
		answer = (answer + dp[i]) % MOD;
	}
	std::cout << answer << "\n";
	return ;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t = 1;
	//std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
