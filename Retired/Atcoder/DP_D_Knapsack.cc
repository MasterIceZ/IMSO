/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Knapsack 1
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

const int MxW = 100010;
const int MxN = 110;
ll dp[MxN][MxW], val;

inline void solution(){
	int n, w, wei;
	cin >> n >> w;
	for(int i=1; i<=n; ++i){
		cin >> wei >> val;
		memcpy(dp[i], dp[i - 1], sizeof (dp[i - 1]));
		for(int j=w; j>=wei; --j){
			dp[i][j] = max(dp[i][j], dp[i - 1][j - wei] + val);
		}
	}
	cout << dp[n][w];
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
