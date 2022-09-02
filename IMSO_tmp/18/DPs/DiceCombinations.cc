/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Dice Combination
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
ll dp[MxN];
const ll MOD = 1e9 + 7;

inline void solution(){
	int n;
	cin >> n;
	dp[0] = 1ll;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=6; ++j){
			if(i - j < 0){
				continue;
			}
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	cout << dp[n];
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
