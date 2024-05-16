#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int dp[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		dp[l]++, dp[r]--;
	}
	int maxx = 0, idx = 1;
	for(int i=1; i<=100000; ++i) {
		dp[i] += dp[i - 1];
		if(dp[i] > maxx) {
			maxx = dp[i];
			idx = i;
		}
	}
	cout << (maxx == n ? "yes": "no") << " " << idx << "\n";
	return 0;
}
