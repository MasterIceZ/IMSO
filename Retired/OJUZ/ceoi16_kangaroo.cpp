#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MxN = 2020;
const ll MOD = 1e9 + 7;

ll dp[MxN][MxN]; // dp(i, j) = 1 to i with j components

signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, stp, edp;
	cin >> n >> stp >> edp;
	dp[1][1] = 1ll;
	for(int i=2; i<=n; ++i) {
		for(ll j=1; j<=(ll) i; ++j) {
			if(i == stp || i == edp) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
			else {
				ll r = j;
				if(i > stp) {
					r -= 1ll;
				}
				if(i > edp) {
					r -= 1ll;
				}
				dp[i][j] = (dp[i - 1][j - 1] * r) % MOD;
				dp[i][j] = (dp[i][j] + (dp[i - 1][j + 1] * j)) % MOD; 
			}
		}
	}
	cout << dp[n][1] << "\n";	
	return 0;
}
