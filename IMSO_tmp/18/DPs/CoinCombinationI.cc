/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Coin Combination I
 * ALGO		: Dynamic Programming
 * DATE		: 10 May 2022
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
const int MxD = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll dp[MxD];
int a[MxN];

inline void solution(){
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	dp[0] = 1;
	for(int i=1; i<=x; ++i){
		for(int j=1; j<=n; ++j){
			if(i - a[j] < 0){
				continue;
			}
			dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
		}
	}
	cout << dp[x];
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
