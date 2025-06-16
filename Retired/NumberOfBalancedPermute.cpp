#include <bits/stdc++.h>

using namespace std;

const int MxD = 10;
const int MxN = 88;
const int MxS = 9 * MxN;
const long long MOD = 1e9 + 7ll;

int n, cnt[MxD], sum = 0;
long long fac[MxN], inv_fac[MxN], dp[MxD][MxN][MxS];

long long bin_pow(long long a, long long b) {
	long long res = 1ll;
	for(; b>0ll; b>>=1ll, a=(a * a) % MOD, b>>=1ll) {
		if(b & 1ll) {
			res = (res * a) % MOD;
		}
	}
	return res;
}

long long DP(int digit, int used, int cur_sum) {
	if(digit >= MxD) {
		if(used == n / 2 && cur_sum == sum) {
			return (fac[n / 2] * fac[(n + 1) / 2]) % MOD;
		}
		else {
			return 0ll;
		}
	}
	if(dp[digit][used][cur_sum] != -1ll) {
		return dp[digit][used][cur_sum];
	}
	dp[digit][used][cur_sum] = 0ll;
	for(int i=0; i<=min(cnt[digit], n / 2 - used); ++i) {
		long long to_add = ((DP(digit + 1, used + i, cur_sum + i * digit) * inv_fac[cnt[digit] - i] % MOD) * inv_fac[i]) % MOD;
		dp[digit][used][cur_sum] = (dp[digit][used][cur_sum] + to_add) % MOD;
	}
	return dp[digit][used][cur_sum];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	fac[0] = 1ll;
	for(int i=1; i<MxN; ++i) {
		fac[i] = (fac[i - 1] * (long long) i) % MOD;
	}
	inv_fac[MxN - 1] = bin_pow(fac[MxN - 1], MOD - 2ll);
	for(int i=MxN - 2; i>=0; --i) {
		inv_fac[i] = (inv_fac[i + 1] * (long long) (i + 1)) % MOD;
	}

	cerr << "D: " << fac[10] << " " << inv_fac[10] << "\n";

	string s;
	cin >> s;
	n = (int) s.size();
	for(auto c: s) {
		cnt[c - '0']++;
		sum += c - '0';
	}
	if(sum % 2 == 0) {
		cout << "0\n";
		exit(0);
	}
	sum /= 2;
	memset(dp, -1ll, size(dp));
	cout << DP(0, 0, 0) << "\n";
	return 0;
}
