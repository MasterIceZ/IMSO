#include <bits/stdc++.h>

using namespace std;

const int MxN = 55;
const int MxA = 100010;
const int MxS = MxN * MxA;

int dp[MxN][MxS], a[MxN], b[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i] >> b[i];
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int w=0; w<MxS; ++w) {
			dp[i][w] = dp[i - 1][w] + b[i];
		}
		for(int w=0; w<MxS-a[i]; ++w) {
			dp[i][w + a[i]] = min(dp[i][w + a[i]], dp[i - 1][w]);
		}
	}

	int answer = 1e9 + 100;
	for(int w=1; w<MxS; ++w) {
		answer = min(answer, dp[n][w]);
	}

	cout << answer << "\n";

	return 0;
}
