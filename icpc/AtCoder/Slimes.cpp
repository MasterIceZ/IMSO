#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 440;

ll dp[MxN][MxN], a[MxN], pref_sum[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			dp[i][j] = 1e18 + 100ll;
		}
	}
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		dp[i][i] = 0;
		pref_sum[i] = pref_sum[i - 1] + a[i];
	}
	for(int sz=2; sz<=n; ++sz) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			for(int m=l; m<r; ++m) {
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + pref_sum[r] - pref_sum[l - 1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
