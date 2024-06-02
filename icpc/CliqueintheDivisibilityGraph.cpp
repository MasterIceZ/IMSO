#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;

int cnt[MxN], dp[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		cnt[x]++;
	}

	int answer = 0;
	for(int i=1; i<=1000000; ++i) {
		for(int j=i+i; j<=1000000; j += i) {
			dp[j] = max(dp[j], cnt[i] + dp[i]);
		}
		answer = max(answer, dp[i] + cnt[i]);
	}

	cout << answer << "\n";

	return 0;
}
