#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;
const ll MOD = 1e9 + 7;

string s;
ll dp[MxN][MxN];

inline int valid(char a, char b) {
	if(a == '[') {
		return (b == ']' || b == '?');
	}
	if(a == '(') {
		return (b == ')' || b == '?');
	}
	if(a == '?') {
		if(b == '?') {
			return 2;
		}
		return (b == ']' || b == ')');
	}
	return 0;
}

ll DP(int l, int r) {
	if(l >= r) {
		return 1ll;
	}
	if(dp[l][r] != -1ll) {
		return dp[l][r];
	}
	dp[l][r] = 0;
	for(int m=l+1; m<=r; m+=2) {
		ll to_add = (valid(s[l], s[m]) * DP(l + 1, m)) % MOD;
		to_add = (to_add * DP(m + 1, r)) % MOD;
		dp[l][r] = (dp[l][r] + to_add) % MOD;
	}
	return dp[l][r];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	s = " " + s;
	memset(dp, -1, sizeof dp);
	cout << DP(1, n) << "\n";
	return 0;
}
