#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	int n, x, bit;
	scanf("%d", &n);
	int max_mask = (1 << n);
	vector<int> dp(max_mask, 1e9 + 100);
	dp[0] = 0;
	for(int i=0; i<=n-1; ++i) {
		for(int j=0; j<=n-1; ++j) {
			scanf("%d", &x);
			bit = (1 << j);
			for(int mask=0; mask<=max_mask; ++mask) {
				if((mask & bit) == 0 || __builtin_popcount(mask) != i + 1) {
					continue;
				}
				dp[mask] = min(dp[mask], dp[mask ^ bit] + x);
				printf("dp[%d] = min(dp[%d], dp[%d ^ %d] + %d\n", mask, mask, bit, x);
				printf("dp[%d ^ %d] = %d\n", mask, bit, dp[mask ^ bit]);
			}
		}
	}
	printf("%d\n", dp[max_mask]);
	return 0;
}
