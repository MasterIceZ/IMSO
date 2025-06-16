#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
const long long MOD = 1e9 + 7ll;

int a[MxN], pre[MxN];
map<int, long long> dp;

inline void solve() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
	dp.clear();
	dp[0] = 1ll;
	for(int i=1; i<=n; ++i) {
		dp[pre[i - 1]] = (dp[pre[i - 1]] * 3ll) % MOD;
		long long to_add = (2ll * dp[pre[i]]) % MOD;
		dp[pre[i - 1]] = (dp[pre[i - 1]] + to_add) % MOD;
	}
	long long sum = 0ll;
	for(auto it: dp) {
		sum = (sum + it.second) % MOD;
	}
	printf("%lld\n", sum);
	return ;
}

signed main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}
