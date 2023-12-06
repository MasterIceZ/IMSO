#include <bits/stdc++.h>

using namespace std;

int dp[1 << 8];

int main() {
	int n, k;
	cin >> n >> k;
	for(int i=0; i<(1 << k); ++i) {
		dp[i] = 1e9 + 100;
	}
	dp[0] = 0;
	for(int i=1, v; i<=n; ++i) {
		cin >> v;
		int x = 0;
		for(int j=1, c; j<=k; ++j) {
			cin >> c;
			x = (x << 1) | c;
		}
		for(int b=0; b<(1 << k); ++b) {
			dp[b | x] = min(dp[b | x], dp[b] + v);
		}
	}
	cout << dp[(1 << k) - 1] << "\n";
	return 0;
}
