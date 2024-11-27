#include <iostream>
#include <iomanip>

using namespace std;

const int MxN = 110;

double a[MxN], pref_sum[MxN], dp[MxN][MxN];

double DP(int l, int r) {
	if(l > r) {
		return dp[l][r] = 0;
	}
	if(l == r) {
		return dp[l][r] = a[l];
	}
	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	dp[l][r] = 1e19;
	for(int m=l; m<=r; ++m) {
		dp[l][r] = min(dp[l][r], DP(l, m - 1) + DP(m + 1, r));
	}
	dp[l][r] += pref_sum[r] - pref_sum[l - 1];
	return dp[l][r];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	while(cin >> n) {
		for(int i=1; i<=n; ++i) {
			cin >> a[i];
		}
		for(int i=1; i<=n; ++i) {
			pref_sum[i] = pref_sum[i - 1] + a[i];
			for(int j=1; j<=n; ++j) {
				dp[i][j] = -1;
			}
		}
		cout << fixed << setprecision(4) << DP(1, n) << "\n";
	}
	return 0;
}
