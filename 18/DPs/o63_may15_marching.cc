/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Marching
 * ALGO		: Dynamic Programming
 * DATE		: 17 Sep 2022
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

const int MxN = 1550;
ll a[MxN][MxN], dp[5][MxN][MxN], ps[3][MxN][MxN];

inline void solution(){
	memset(dp, 0x3f, sizeof dp);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			ps[1][i][j] = ps[1][i][j - 1] + a[i][j];
			ps[2][i][j] = ps[2][i - 1][j] + a[i][j];
		}
	}
	dp[1][1][0] = dp[1][0][1] = 0ll;
	dp[2][1][m + 1] = dp[2][0][m] = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[1][i][j] = min(dp[1][i - 1][j], dp[1][i][j - 1]) + a[i][j];
		}
		for(int j=m; j>=1; --j){
			dp[2][i][j] = min(dp[2][i - 1][j], dp[2][i][j + 1]) + a[i][j];
		}
	}
	dp[3][n][0] = dp[3][n + 1][1] = 0ll;
	dp[4][n + 1][m] = dp[4][n][m + 1] = 0ll;
	for(int i=n; i>=1; --i){
		for(int j=1; j<=m; ++j){
			dp[3][i][j] = min(dp[3][i + 1][j], dp[3][i][j - 1]) + a[i][j];
		}
		for(int j=m; j>=1; --j){
			dp[4][i][j] = min(dp[4][i + 1][j], dp[4][i][j + 1]) + a[i][j];
		}
	}
	ll answer = 1e18 + 100ll;
	// horizontal
	for(int i=1; i<=n; ++i){
		ll slideMin = 1e18 + 100ll;
		for(int j=1; j<=m; ++j){
			slideMin = min(slideMin, dp[1][i][j] + dp[3][i][j] - 2 * a[i][j] - ps[1][i][j - 1]);
			answer = min(answer, slideMin + dp[2][i][j] + dp[4][i][j] - 2 * a[i][j] + ps[1][i][j]);
		}
	}
	// vertical
	for(int j=1; j<=m; ++j){
		ll slideMin = 1e18 + 100ll;
		for(int i=1; i<=n; ++i){
			slideMin = min(slideMin, dp[1][i][j] + dp[2][i][j] - 2 * a[i][j] - ps[2][i - 1][j]);
			answer = min(answer, slideMin + dp[3][i][j] + dp[4][i][j] - 2 * a[i][j] + ps[2][i][j]);
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
