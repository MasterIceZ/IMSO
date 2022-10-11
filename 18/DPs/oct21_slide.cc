/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_slide
 * ALGO		: Dynamic Programming
 * DATE		: 8 Oct 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 110;
int a[MxN][MxN << 1], qs[MxN][MxN << 1];
int sum[MxN][MxN << 1], dp[MxN][MxN << 1][MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=2 * i - 1; ++j){
			cin >> a[i][j];
			if(j < i){
				qs[i][j] = qs[i - 1][j] + a[i][j];
				sum[i][j] = sum[i][j - 1] + a[i][j];
			}
			else if(j > i){
				qs[i][j] = qs[i - 1][j - 2] + a[i][j];
			}
			else if(i == 1 && j == 1){
				qs[i][j] = a[i][j];
				sum[i][j] = 1;
			}
		}
		for(int j=2 * i - 1; j>i; --j){
			sum[i][j] = sum[i][j + 1] + a[i][j];
		}
	}
	dp[1][1][0] = a[1][1];
	for(int state=0; state<=k; ++state){
		for(int i=2; i<=n; ++i){
			// copy from last step
			int sum_now = 0;
			for(int j=1; j<i; ++j){
				dp[i][j][state] = dp[i][j][state - 1] + a[i][j];
				sum_now += a[i][j];
				dp[i][i][state] = max(dp[i][j][state] + (sum[i][i - 1] - sum[i][j - 1]) + a[i][i], dp[i][i][state]);
			}
			for(int j=i+1; j<=2*n-1; ++j){
				dp[i][j][state] = dp[i][j - 2][state - 1] + a[i][j];
				dp[i][i][state] = max(dp[i][j][state] + (sum[i][i + 1] - sum[i][j + 1]) + a[i][i], dp[i][i][state]);
			}
		}
	}
	int answer = 0;
	for(int state=0; state<k; ++state){
		for(int j=1; j<=2 * n - 1; ++j){
			answer = max(answer, dp[n][j][state]);
		}
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
