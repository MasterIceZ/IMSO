#include <bits/stdc++.h>

using namespace std;

const int MxN = 5050;

int dp[MxN][MxN];
bitset<MxN> is_palin[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = (int) s.size();
	s = " " + s;
	for(int l=n; l>=1; --l) {
		dp[l][l] = 1;
		is_palin[l][l] = true;
		for(int r=l+1; r<=n; ++r) {
			is_palin[l][r] = ((is_palin[l + 1][r - 1] || r - l + 1 == 2) && (s[l] == s[r]));
			dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + is_palin[l][r];
		}
	}
	int q, l, r;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
	return 0;
}
