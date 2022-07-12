/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Removing Digits
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

const int MxN = 1000010;
int dp[MxN];

int DP(int n){
	if(dp[n] != -1){
		return dp[n];
	}
	string s = to_string(n);
	int minn = 1e9 + 100;
	for(auto x: s){
		int nxt = n - (x - '0');
		if(nxt == n){
			continue;
		}
		minn = min(minn, DP(nxt) + 1);
	}
	return dp[n] = minn;
}

inline void solution(){
	int n;
	cin >> n;
	cout << DP(n);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
