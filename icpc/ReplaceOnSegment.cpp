#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN], dp[2][MxN][MxN][MxN];

inline void solve() {
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		for(int j=1; j<=x; ++j) {
			if(j == a[i]) {
				dp[0][i][i][j] = 0;
				dp[1][i][i][j] = 1;
			}
			else {
				dp[0][i][i][j] = 1;
				dp[1][i][i][j] = 0;
			}
		}
	}
	for(int sz=2; sz<=n; ++sz) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			for(int k=1; k<=x; ++k) {
				dp[0][l][r][k] = dp[1][l][r][k] = 1e9 + 100;
			}
			for(int m=l; m<r; ++m) {
				for(int k=1; k<=x; ++k) {
					dp[0][l][r][k] = min(dp[0][l][r][k], dp[0][l][m][k] + dp[0][m + 1][r][k]);
					dp[1][l][r][k] = min(dp[1][l][r][k], dp[1][l][m][k] + dp[1][m + 1][r][k]);
				}
			}
			for(int k=1; k<=x; ++k) {
				dp[0][l][r][k] = min(dp[0][l][r][k], dp[1][l][r][k] + 1);
			}
			pair<int, int> first_min = make_pair(1e9 + 100, -1);
			pair<int, int> second_min = make_pair(1e9 + 100, -1);
			for(int k=1; k<=x; ++k) {
				pair<int, int> cur = make_pair(dp[0][l][r][k], k);
				if(cur < first_min) {
					swap(cur, first_min);
				}
				if(cur < second_min) {
					swap(cur, second_min);
				}
			}
			for(int k=1; k<=x; ++k) {
				if(k == first_min.second) {
					dp[1][l][r][k] = min(dp[1][l][r][k], second_min.first);
				}
				else {
					dp[1][l][r][k] = min(dp[1][l][r][k], first_min.first);
				}
			}
		}
	}
	int res = 1e9 + 100;
	for(int k=1; k<=x; ++k) {
		res = min(res, dp[0][1][n][k]);
	}
	cout << res;
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
