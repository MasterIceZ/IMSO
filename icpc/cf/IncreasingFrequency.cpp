#include <bits/stdc++.h>

using namespace std;

const int MxN = 500050;

int sum[MxN], a[MxN], dp[MxN], last[MxN];

auto main(int argc, char *argv[]) -> int {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + (a[i] == c);
	}
	int answer = sum[n];
	for(int i=1; i<=n; ++i) {
		if(a[i] == c) {
			continue;
		}
		dp[i] = max(0, dp[last[a[i]]] - (sum[i] - sum[last[a[i]]])) + 1;
		answer = max(answer, sum[n] + dp[i]);
		last[a[i]] = i;
	}
	cout << answer << "\n";
	return 0;
}
