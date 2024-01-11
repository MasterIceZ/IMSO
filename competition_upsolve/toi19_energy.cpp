#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MxN = 330;
const ll MOD = 1e9 + 7ll;

ll d, a[MxN], pref_sum[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k >> d;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		pref_sum[i] = pref_sum[i - 1] + a[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0ll)), new_dp(n + 1, vector<ll> (n + 1, 0ll));
	for(int i=1; i<=n; ++i) {
		for(int j=i; j<=n; ++j) {
			dp[i][j] = 1ll;
		}
	}
	for(int state=2; state<=k; ++state) {
		for(int sz=1; sz<=n; ++sz) {
			for(int l=1; l+sz-1<=n; ++l) {
				int r = l + sz - 1;
				new_dp[l][r] = 0ll;
				for(int m=l; m<r; ++m) {
					ll left_sum = pref_sum[m] - pref_sum[l - 1];
					ll right_sum = pref_sum[r] - pref_sum[m];
					if(abs(left_sum - right_sum) <= d) {
						ll mul = (dp[l][m] * dp[m + 1][r]) % MOD;
						new_dp[l][r] = (new_dp[l][r] + mul) % MOD;
					}
				}
			}
		}
		dp = new_dp;
	}
	cout << dp[1][n] << "\n";
	return 0;
}
