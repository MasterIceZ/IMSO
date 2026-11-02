#include <iostream>
#include <vector>

const int MxA = 101;
const long long INF = 1e18 + 100ll;

inline long long cost(long long x) {
	return x * x * x;
}

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(auto &x: a) {
		std::cin >> x;
	}
	std::vector<long long> dp(MxA, -INF);
	dp[a[0]] = 0;
	for(int i=1; i<n; ++i) {
		std::vector<long long> new_dp = dp;
		for(int j=1; j<MxA; ++j) {
			new_dp[a[i]] = std::max(new_dp[a[i]], dp[j] + cost(std::abs(a[i] + j)));
		}
		dp = new_dp;
	}
	std::cout << dp[a[n-1]] << std::endl;
	return 0;
}
