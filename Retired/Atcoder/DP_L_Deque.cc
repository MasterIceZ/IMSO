/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Deque
 * ALGO		: Dynamic Programming
 * DATE		: 4 Mar 2023
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

const int MxN = 3030;
ll dp[MxN][MxN], sum[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[i][i];
		sum[i] = sum[i - 1] + dp[i][i];
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			dp[l][r] = max(
				dp[l][l] + sum[r] - sum[l] - dp[l + 1][r], 
				dp[r][r] + sum[r - 1] - sum[l - 1] - dp[l][r - 1]
			);
		}
	}
	cout << dp[1][n] * 2ll - sum[n];
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
