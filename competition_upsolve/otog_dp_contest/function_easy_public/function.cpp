#include <bits/stdc++.h>
#include "function.h"

using namespace std;

long long sum[1010], dp[1010][1010], opt[1010][22];

long long minPenguinValue(int N, int M, std::vector<int> A){
	for(int i=1; i<=N; ++i){
		sum[i] = sum[i - 1] + A[i - 1];
		dp[i][i] = A[i - 1] * A[i - 1];
	}
	for(int sz=2; sz<=N; ++sz){
		for(int l=1; l+sz-1<=N; ++l){
			int r = l + sz - 1;
			dp[l][r] = dp[l][r - 1] + A[r - 1] * (sum[r] - sum[l - 1]);
		}
	}
	memset(opt, 0x3f, sizeof opt);
	opt[0][0] = 0;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			for(int k=0; k<i; ++k){
				opt[i][j] = min(opt[i][j], opt[k][j - 1] + dp[k + 1][i]);
			}
		}
	}
    return opt[N][M];
}
