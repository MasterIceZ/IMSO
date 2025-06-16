#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MxN = 550;
const long long MOD = 998244353ll;

long long factorial[MxN], inverse_factorial[MxN];

inline long long mod_of_power(long long a, long long b) {
	long long res = 1ll;
	for(; b>0; a=(a*a)%MOD, b>>=1ll) {
		if(b & 1ll) {
			res = (res * a) % MOD;
		}
	}
	return res;
}

inline long long C(int n, int r) {
	if(n < r || r < 0) {
		return 0ll;
	}
	return (((factorial[n] * inverse_factorial[r]) % MOD) * inverse_factorial[n - r]) % MOD;
}

inline void solve() {
	int n, k;
	std::string s;
	std::cin >> n >> k >> s;
	std::reverse(s.begin(), s.end());
	s = " " + s;
	std::vector<long long> dp(k + 1);
	dp[0] = 1ll;
	for(int state=1; state<=n; ++state) {
		std::vector<long long> new_dp(k + 1);
		int status = (s[state] == '0');
		for(int i=0; i<=k; ++i) {
			for(int j=0; j<=i; ++j) {
				int remains = i - j;
				long long to_add = (dp[j] * C((i + status) / 2, remains)) % MOD;
				new_dp[i] = (new_dp[i] + to_add) % MOD;
			}
		}
		dp = new_dp;
	}
	std::cout << dp[k] << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	factorial[0] = 1ll;
	for(long long i=1ll; i<(long long) MxN; ++i) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	inverse_factorial[MxN - 1] = mod_of_power(factorial[MxN - 1ll], MOD - 2ll);
	for(long long i=(long long) MxN - 2ll; i>=0ll; --i) {
		inverse_factorial[i] = (inverse_factorial[i + 1] * (i + 1ll)) % MOD;
	}

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
