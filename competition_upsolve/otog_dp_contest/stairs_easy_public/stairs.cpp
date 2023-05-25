#include <vector>
#include <cstdlib>
#include "stairs.h"

const int MOD = 1e9 + 7;
int *dp;

int countWays(int N, int M, std::vector<int> S){
	dp = (int *) calloc(N + 1, sizeof(int));
	dp[0] = 1;
	for(int i=0; i<=N; ++i){
		for(auto x: S){
			if(i + x > N){
				continue;
			}
			dp[i + x] = (dp[i + x] + dp[i]) % MOD;
		}
	}
    return dp[N];
}
