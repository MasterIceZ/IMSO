#include "stick.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 330;

int dp[MxN][MxN];

int DP(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	for(int x=l; x<=r; ++x){
		ok |= dp[l - 1][r];
		ok |= dp[l][r - 1]
	}
	return dp[l][r];
}

void init(int N, std::vector<int> X){
	for(int i=1; i<=N; ++i){
		a[i] = X[i - 1];
	}
	return ;
}

int max_length(int L,int R){
	return dp[L + 1][R + 1];
}
