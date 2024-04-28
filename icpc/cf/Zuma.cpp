#include <bits/stdc++.h>

using namespace std;

const int MxN = 550;

int c[MxN], dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int l=1; l<=n; ++l) {
		for(int r=1; r<l; ++r) {
			dp[l][r] = 1;
		}
		for(int r=l; r<=n; ++r) {
			dp[l][r] = 1e9 + 100;
		}
	}
	for(int i=1; i<=n; ++i) {
		cin >> c[i];
		dp[i][i] = 1;
	}
	for(int sz=2; sz<=n; ++sz) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			if(c[l] == c[r]) {
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
			for(int m=l; m<r; ++m) {
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
			}
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
