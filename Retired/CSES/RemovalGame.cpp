#include <iostream>

const int MxN = 5050;

long long a[MxN], dp[MxN][MxN];
bool done[MxN][MxN];

long long DP(int l, int r) {
	if(l > r) {

	}
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	std::cout << DP(1, n);
	return 0;
}
