#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;
const ll MOD = 998244353ll;

int a[MxN];
ll pw2[MxN], dp[MxN][MxN], answer;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	pw2[0] = 1ll;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		pw2[i] = (pw2[i - 1] * 2ll) % MOD;
	}
	dp[1][1] = 1ll;
	for(int i=2; i<=n; ++i) {
		ll sum = 0ll;
		for(int j=1; j<=i; ++j) {
			if(a[i - 1] < a[i]) {
				sum = (sum + dp[i - 1][j]) % MOD;
				dp[i][j] = (sum * pw2[i - j - 1]) % MOD;
			}
			else {
				dp[i][j] = (sum * pw2[i - j - 1]) % MOD;
				sum = (sum + dp[i - 1][j]) % MOD;
			}
		}
	}
	for(int i=1; i<=n; ++i) {
		answer = (answer + dp[n][i]) % MOD;
	}
	cout << answer << "\n";
	return 0;
}
