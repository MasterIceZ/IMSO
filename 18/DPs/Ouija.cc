/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Ouija
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

const int MxN = 220;
const ll MOD = 1e9 + 7;
ll dp[MxN][MxN][2 * MxN]; // be at row (i, j) at {k}th step
ll mem[2 * MxN][2 * MxN];

ll C(int n, int r){
	if(mem[n][r] != -1){
		return mem[n][r];
	}
	if(n == 1 || n == r){
		return mem[n][r] = 1;
	}
	return mem[n][r] = (C(n - 1, r) + C(n - 1, r - 1)) % MOD;
}

inline void solution(){
	int r, c;
	cin >> r >> c;
	dp[1][1][0] = 1ll;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=r; ++j){
			for(int k=1; k<=r+c; ++k){
				if(k < max(i, j) - 1){
					continue;
				}
				if(i != j){
					dp[i][j][k] = (dp[i][j][k - 1] + dp[i - 1][j][k - 1]) % MOD;
					dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1]) % MOD;
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1]) % MOD;
				}
				else{
					dp[i][j][k] = (dp[i - 1][j][k - 1] + dp[i][j - 1][k - 1]) % MOD;
				}
			}
		}
	}
	cout << dp[r][r][r + c - 2];
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
