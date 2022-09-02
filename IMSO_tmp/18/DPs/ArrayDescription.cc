/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Array Description
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

// 0 denotes UNKONWN

const int MxM = 110;
const int MxN = 100010;
const ll MOD = 1e9 + 7;
int a[MxN];
ll dp[MxN][MxM];

inline void solution(){
	int n, ub;
	cin >> n >> ub;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}

	for(int i=1; i<=ub; ++i){
		dp[1][i] = (a[1] == 0 || a[1] == i);
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=ub; ++j){
			if(a[i] != 0 && a[i] != j){
				continue;
			}
			dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD + dp[i - 1][j + 1]) % MOD;
		}
	}
	ll res = 0ll;
	for(int i=1; i<=ub; ++i){
		res = (res + dp[n][i]) % MOD;
	}
	cout << res;
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
