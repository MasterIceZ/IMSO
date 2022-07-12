/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Tile Square
 * ALGO		: Dynamic Programming
 * DATE		: 8 Jul 2022
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

int dp[355][355];

int DP(int w, int h){
	dbg(w, h);
	if(dp[w][h] != -1){
		return dp[w][h];
	}
	if(w == 0 || h == 0){
		return dp[w][h] = 0;
	}
	if(w == h){
		return dp[w][h] = 1;
	}
	int sum = 1e9 + 100;
	for(int i=0; i<=w; ++i){
		for(int j=0; j<=h; ++j){
			int q_1 = DP(i, j), q_2 = DP(w - i, j);
			int q_3 = DP(i, h - j), q_4 = DP(w - i, h - j);
			dbg(q_1, q_2, q_3, q_4);
			sum = min(sum, q_1 + q_2 + q_3 + q_4);
		}
	}
	return dp[w][h] = sum;
}

inline void solution(){
	int w, h;
	cin >> w >> h;
	cout << DP(w, h);	
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	memset(dp, -1, sizeof dp);
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
