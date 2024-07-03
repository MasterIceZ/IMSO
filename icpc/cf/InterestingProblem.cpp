#include <bits/stdc++.h>

using namespace std;

const int MxN = 880;

int a[MxN], dp[MxN][MxN], opt[MxN];

inline void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		a[i] = i - a[i];
	}
	for(int i=1; i<=n; ++i) {
		opt[i] = 0;
		for(int j=1; j<=n; ++j) {
			dp[i][j] = 1e9 + 100;
		}
	}
	for(int i=1; i<n; ++i) {
		if(a[i] < 0 || a[i] % 2 == 1) {
			continue;
		}
		dp[i][i + 1] = a[i] / 2;
	}
	for(int sz=4; sz<=n; sz+=2) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			if(a[l] >= 0 && a[l] % 2 == 0 && a[l] / 2 >= dp[l + 1][r - 1]) {
				dp[l][r] = min(dp[l][r], a[l] / 2);
			}
			for(int m=l+1; m<r; m+=2) {
				dp[l][r] = min(dp[l][r], max(dp[l][m], dp[m + 1][r] - (m - l + 1) / 2));
			}
		}
	}
	for(int r=1; r<=n; ++r) {
		opt[r] = opt[r - 1];
		for(int l=r; l>=1; --l) {
			if(opt[l - 1] >= dp[l][r]) {
				opt[r] = max(opt[r], opt[l - 1] + (r - l + 1) / 2);
			}
		}
	}
	cout << opt[n] << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
