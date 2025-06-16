#include <bits/stdc++.h>

using namespace std;

const int MxN = 440;

long long a[MxN << 1], dp[MxN][MxN];

inline void solve() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%lld", &a[i]);
		a[i + n] = a[i];
	}
	memset(dp, 0ll, sizeof dp);
	for(int sz=3; sz<=n; ++sz) {
		for(int l=1; l<=n; ++l) {
			int r = l + sz - 1;
			for(int m=l; m<r; ++m) {
				dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
			}
			for(int m=l+1; m<r; ++m) {
				dp[l][r] = max(dp[l + 1][m - 1] + dp[m + 1][r - 1] + a[l] * a[m] * a[r], dp[l][r]);
			}
		}
	}
	long long answer = 0ll;
	for(int i=1; i<=n; ++i) {
		for(int j=i; j<=2*n; ++j) {
			answer = max(answer, dp[i][j]);
		}
	}
	printf("%lld\n", answer);
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
