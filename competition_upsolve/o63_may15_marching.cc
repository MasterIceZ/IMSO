#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1550;

int n, m;
ll a[MxN][MxN], sum[2][MxN][MxN], dp[4][MxN][MxN];

int main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
			sum[0][i][j] = sum[0][i][j - 1] + a[i][j];
			sum[1][i][j] = sum[1][i - 1][j] + a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][1][0] = dp[0][0][1] = 0ll;
	dp[1][1][m + 1] = dp[1][0][m] = 0ll;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			dp[0][i][j] = min(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
		}
		for(int j=m; j>=1; --j) {
			dp[1][i][j] = min(dp[1][i - 1][j], dp[1][i][j + 1]) + a[i][j];
		}
	}
	dp[2][n][0] = dp[2][n + 1][1] = 0ll;
	dp[3][n + 1][m] = dp[3][n][m + 1] = 0ll;
	for(int i=n; i>=1; --i) {
		for(int j=1; j<=m; ++j) {
			dp[2][i][j] = min(dp[2][i + 1][j], dp[2][i][j - 1]) + a[i][j];
		}
		for(int j=m; j>=1; --j) {
			dp[3][i][j] = min(dp[3][i + 1][j], dp[3][i][j + 1]) + a[i][j];
		}
	}
	ll answer = 1e18 + 100ll;
	for(int i=1; i<=n; ++i) {
		ll cur = 1e18 + 100ll;
		for(int j=1; j<=m; ++j) {
			cur = min(cur, dp[0][i][j] + dp[2][i][j] - 2 * a[i][j] - sum[0][i][j - 1]);
			answer = min(answer, cur + dp[1][i][j] + dp[3][i][j] - 2 * a[i][j] + sum[0][i][j]);
		}
	}
	for(int j=1; j<=m; ++j) {
		ll cur = 1e18 + 100ll;
		for(int i=1; i<=n; ++i) {
			cur = min(cur, dp[0][i][j] + dp[1][i][j] - 2 * a[i][j] - sum[1][i - 1][j]);
			answer = min(answer, cur + dp[2][i][j] + dp[3][i][j] - 2 * a[i][j] + sum[1][i][j]);
		}
	}
	cout << answer << "\n";
	return 0;
}
