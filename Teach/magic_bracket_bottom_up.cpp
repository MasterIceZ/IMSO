#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;
const ll MOD = 1e9 + 7ll;

string s;
ll dp[MxN][MxN];

inline ll valid(char l, char r) {
	if(l == '?') {
		if(r == '?') {
			return 2ll;
		}
		return (r == ']' || r == ')');
	}
	if(l == '[') {
		return (r == ']' || r == '?');
	}
	if(l == '(') {
		return (r == ')' || r == '?');
	}
	return 0ll;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	if(n & 1) {
		cout << "0\n";
		return 0;
	}
	s = " " + s;
	for(int i=1; i<n; ++i) {
		for(int j=1; j<=i; ++j) {
			dp[i][j] = 1;
		}
		dp[i][i + 1] = valid(s[i], s[i + 1]);
	}
	for(int sz=4; sz<=n; sz+=2) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			dp[l][r] = 0ll;
			for(int m=l+1; m<=r; m += 2) {
				ll to_add = (dp[l + 1][m] * dp[m + 1][r]) % MOD;
				to_add = (to_add * valid(s[l], s[m])) % MOD;
				dp[l][r] = (dp[l][r] + to_add) % MOD;
			}
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
