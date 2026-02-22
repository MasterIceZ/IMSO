#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 100010;
const int MxS = 333;

int a[MxN], b[MxN], dp[MxS][MxN], min_dp[MxS];
std::vector<int> p[MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, s, e, answer = 0;
	std::cin >> n >> m >> s >> e;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	for(int i=1; i<=m; ++i) {
		std::cin >> b[i];
		p[b[i]].emplace_back(i);
	}
	memset(dp, 0x3f, sizeof dp);
	memset(min_dp, 0x3f, sizeof min_dp);
	dp[0][0] = 0;
	min_dp[0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=std::min(i, s / e); ++j) {
			auto it = std::upper_bound(p[a[i]].begin(), p[a[i]].end(), min_dp[j - 1]);
			if(it == p[a[i]].end()) {
				continue;
			}
			dp[j][i] = *it;
			if(j * e + dp[j][i] + i <= s) {
				answer = std::max(answer, j);
			}
		}
		for(int j=1; j<=std::min(i, s / e); ++j) {
			min_dp[j] = std::min(min_dp[j], dp[j][i]);
		}
	}
	std::cout << answer << "\n";
	return 0;
}
