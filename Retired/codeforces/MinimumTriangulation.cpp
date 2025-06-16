#include <algorithm>
#include <iostream>

const int MxN = 550;
const long long INF = 1e18 + 100ll;

long long dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int sz=3; sz<=n; ++sz) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			dp[l][r] = INF;
			for(int m=l+1; m<r; ++m) {
				long long cur_val = ((long long) l) * ((long long) r) * ((long long) m);
				dp[l][r] = std::min(dp[l][r], dp[l][m] + dp[m][r] + cur_val);
			}
		}
	}
	std::cout << dp[1][n] << "\n";
	return 0;
}
