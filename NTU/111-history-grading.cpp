#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 55;

int a[MxN], b[MxN], dp[MxN][MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, x;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> x;
		a[x] = i;
	}
	while(std::cin >> x) {
		b[x] = 1;
		for(int i=2; i<=n; ++i)	{
			std::cin >> x;
			b[x] = i;
		}
		memset(dp, 0, sizeof dp);
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(a[i] == b[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		std::cout << dp[n][n] << "\n";
	}
	return 0;
}
