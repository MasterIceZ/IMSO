#include <bits/stdc++.h>
#include "function.h"

using namespace std;

long long sum[500050], sum_2[500050];
long long dp[500050][22]; // (index, number of chunks)

inline long long get_value(int l, int r){
	 return (sum_2[r] - sum_2[l - 1]) - (sum[l - 1] * (sum[r] - sum[l - 1]));
}

void divide(int l, int r, int opt_l, int opt_r, int chunks){
	if(l > r){
		return ;
	}
	int mid = (l + r) >> 1;
	pair<long long, int> best = make_pair(LLONG_MAX, -1);
	for(int k=opt_l; k<=min(mid, opt_r); ++k){
		best = min(best, make_pair(dp[k][chunks - 1] + get_value(k + 1, mid), k));
	}
	dp[mid][chunks] = best.first;
	divide(l, mid - 1, opt_l, best.second, chunks);
	divide(mid + 1, r, best.second, opt_r, chunks);
}

long long minPenguinValue(int N, int M, std::vector<int> A){
	for(int i=1; i<=N; ++i){
		sum[i] = sum[i - 1] + A[i - 1];
		sum_2[i] = sum_2[i - 1] + (A[i - 1] * sum[i]);
	}
	for(int i=1; i<=N; ++i){
		dp[i][1] = get_value(1, i);
	}
	for(int j=2; j<=M; ++j){
		divide(1, N, 1, N, j);
	}
	return dp[N][M];
}
