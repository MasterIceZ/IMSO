/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso16_game
 * ALGO		: Dynamic Programming
 * DATE		: 17 Feb 2023
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

const int MxN = 1000010;
int v[5], dp[MxN];

inline void solution(){
	int n;
	cin >> n;
	cout << (dp[n] ? "gorn": "lang");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	cin >> v[2] >> v[3] >> v[4];
	v[1] = 1;
 	for(int i=1; i<MxN; ++i){
 		for(int state=1; state<=4; ++state){
 			if(i - v[state] >= 0 && !dp[i - v[state]]){
 				dp[i] = true;
 			}
 		}
 	}
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
