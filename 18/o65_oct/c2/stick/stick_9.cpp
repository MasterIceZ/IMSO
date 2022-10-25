#include "stick.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
int a[MxN];
int dp[MxN][10];

inline int get_in_range(int l, int r){
	int res = -1;
	for(int i=l; i<=r; ++i){
		for(int j=i+1; j<=r; ++j){
			for(int k=j+1; k<=r; ++k){
				int all = a[i] + a[j] + a[k];
				int two = all - max({a[i], a[j], a[k]});
				int maxx = all - two;
				if(maxx < two){
					res = max(res, all);
				}
			}
		}
	}
	return res;
}

void init(int N, std::vector<int> X){
	memset(dp, -1, sizeof dp);
	for(int i=1; i<=N; ++i){
		a[i] = X[i - 1];
	}
	for(int sz=3; sz<=9; ++sz){
		for(int r=sz; r<=N; ++r){
			int l = r - sz + 1;
			dp[r][sz] = get_in_range(l, r);
		}
	}
	return ;
}

int max_length(int L,int R){
	return dp[R + 1][(R - L + 1)];
}
