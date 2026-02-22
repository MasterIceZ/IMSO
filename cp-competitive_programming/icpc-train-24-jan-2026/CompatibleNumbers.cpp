#include <iostream>

const int MxS = 22;
const int MxN = 1000100;

int dp[1 << MxS], a[MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
		dp[a[i]] = a[i];
	}

	int max_mask = (1 << MxS) - 1;
	for(int mask=0; mask<=max_mask; ++mask) {
		for(int bit=0; bit<MxS; ++bit) {
			int cur_bit_mask = (1 << bit);
			if(!(cur_bit_mask & mask) || !dp[mask ^ cur_bit_mask]) {
				continue;
			}
			dp[mask] = dp[mask ^ cur_bit_mask];
		}
	}

	for(int i=1; i<=n; ++i) {
		std::cout << (dp[a[i] ^ max_mask] ? dp[a[i] ^ max_mask] : -1) << " ";
	}

	return 0;
}
