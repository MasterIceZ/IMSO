#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN][MxN], dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	auto check = [&](int mid) {
		dp[1][1] = mid + a[1][1];
		if(dp[1][1] <= 0) {
			return false;
		}
		for(int i=2; i<=n; ++i) {
			dp[i][1] = dp[i - 1][1] + a[i][1];
			if(dp[i][1] <= 0) {
				dp[i][1] = -1e9 - 100;
			}
		}	
		for(int j=2; j<=m; ++j) {
			dp[1][j] = dp[1][j - 1] + a[1][j];
			if(dp[1][j] <= 0) {
				dp[1][j] = -1e9 - 100;
			}
		}
		for(int i=2; i<=n; ++i) {
			for(int j=2; j<=m; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
				if(dp[i][j] <= 0) {
					dp[i][j] = -1e9 - 100;
				}
			}
		}
		return dp[n][m] >= 1;
	};
	int l = 1, r = 1e9 + 100;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << "\n";
	return 0;
}
