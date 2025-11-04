#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

inline void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	s = " " + s;
	std::vector<int> last_pos(26, -1), dp(n + 1);
	for(int i=1; i<=n; ++i) {
		int c = s[i] - 'a';
		dp[i] = dp[i - 1] + 1;
		if(last_pos[c] != -1) {
			dp[i] = std::min(dp[i], dp[last_pos[c]] + 2);
		}
		last_pos[c] = i;
	}
	std::cout << dp[n] << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
