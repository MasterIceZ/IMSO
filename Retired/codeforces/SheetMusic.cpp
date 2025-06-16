#include <iostream>

const int MxN = 1000010;
const long long MOD = 998244353ll;

long long factorial[MxN], inverse_factorial[MxN], dp[MxN];

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

	int n, k;
	std::cin >> n >> k;
	dp[0] = 1ll;
	for(int i=1; i<k; ++i) {
		dp[i] = (dp[i - 1] * 2ll) % MOD;
	}
	dp[k] = (((((dp[k - 1] * 2ll) % MOD) - 2ll) % MOD) + MOD) % MOD;
	for(int i=k+1; i<=n; ++i) {
		dp[i] = (((((2ll * dp[i - 1]) % MOD) - dp[i - k]) % MOD) + MOD) % MOD;
	}
	long long answer = 0ll;
	for(int i=1; i<=n; ++i) {
		long long to_add = (C(n - 1, i - 1) * dp[i]) % MOD;
		answer = (answer + to_add) % MOD;
	}
	std::cout << answer << "\n";
	return 0;
}
