#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;
const ll MOD = 1e9 + 7ll;

ll dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	dp[1][2] = dp[2][1] = 1ll;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(dp[i][j] != 0) {
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
			for(int ps=i-1; ps>=1; --ps) {
				if(i - ps > k) {
					break;
				}
				dp[i][j] = (dp[i][j] + dp[ps - 1][j - 1] + 1ll) % MOD;
			}
			for(int ps=j-1; ps>=1; --ps) {
				if(j - ps > k) {
					break;
				}
				dp[i][j] = (dp[i][j] + dp[i - 1][ps - 1] + 1ll) % MOD;
			}
		}
	}

	cout << dp[n][n] << "\n";

	return 0;
}
