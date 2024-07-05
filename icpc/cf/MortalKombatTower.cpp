#include <bits/stdc++.h>

using namespace std;

auto solve() -> void {
	int n;
	cin >> n;
	int *a = (int *) calloc(n + 1, sizeof(int));
	int **dp = (int **) calloc(2, sizeof(int *));
	dp[0] = (int *) calloc(n + 1, sizeof(int));
	dp[1] = (int *) calloc(n + 1, sizeof(int));
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=0; i<=n; ++i) {
		dp[0][i] = dp[1][i] = 1e9 + 100;
	}
	dp[1][0] = 0;
	dp[0][1] = a[1];
	for(int i=2; i<=n; ++i) {
		dp[0][i] = a[i] + minmax(dp[1][i - 1], dp[1][i - 2] + a[i - 1]).first;
		dp[1][i] = minmax(dp[0][i - 1], dp[0][i - 2]).first;
	}
	cout << minmax(dp[0][n], dp[1][n]).first << "\n";
	return ;
}

auto main(int argc, char *argv[]) -> int {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
