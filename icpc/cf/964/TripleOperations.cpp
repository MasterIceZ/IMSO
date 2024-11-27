#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int dp[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	for(int i=1; i<MxN; ++i) {
		dp[i] = dp[i / 3] + 1;
	}
	for(int i=1; i<MxN; ++i) {
		dp[i] = dp[i - 1] + dp[i];
	}
	int t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] + dp[l] - dp[l - 1] << "\n";
	}
	return 0;
}
