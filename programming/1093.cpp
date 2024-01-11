#include <iostream>
#include <vector>

using namespace std;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	vector<int> dp(n + 1), new_dp(n + 1);
	for(int i=1; i<=n; ++i) {
		new_dp[0] = max(dp[0], dp[2] - a[i]);
		for(int j=1; j<=i; ++j) {
			new_dp[j] = max(dp[j + 2] - a[i], dp[j - 1] + a[i]);
		}
		dp = new_dp;
	}
	cout << dp[0] << "\n";
	return 0;
}
