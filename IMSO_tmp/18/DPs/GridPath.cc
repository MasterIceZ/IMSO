/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Grid Paths
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

const int MxN = 1010;
const ll MOD = 1e9 + 7;
char a[MxN][MxN];
ll dp[MxN][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}	
	}
	dp[1][1] = (a[1][1] == '.');
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i][j] == '*'){
				continue;
			}
			if(a[i - 1][j] == '.'){
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			}
			if(a[i][j - 1] == '.'){
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[n][n];
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
