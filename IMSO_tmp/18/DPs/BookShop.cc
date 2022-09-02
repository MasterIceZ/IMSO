/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Book Shop
 * ALGO		: Dynamic Programming
 * DATE		: 10 Jul 2022
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

const int MxW = 100010;
const int MxN = 1010;
int dp[MxN][MxW], w[MxN], v[MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> w[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	for(int i=1; i<=n; ++i){
		memcpy(dp[i], dp[i - 1], sizeof dp[i - 1]);
		for(int j=0; j<=m; ++j){
			if(j - w[i] < 0){
				continue;
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[n][m];
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
