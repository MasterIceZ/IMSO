/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_carte
 * ALGO		: Dynamic Programming
 * DATE		: 7 Jan 2023
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

const int MxN = 440;
int dp[MxN][MxN], a[MxN];

inline int solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i][i] = 1;
	}
	for(int sz=2; sz<=n; ++sz){
		for(int i=1; i+sz-1<=n; ++i){
			int j = i + sz - 1;
			dp[i][j] = 1e9 + 10;
			for(int k=i; k<j; ++k){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
			dp[i][j] -= (a[i] == a[j]);
		}
	}
	dbg(dp[1][n]);
	return dp[1][n];
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1, k;
	cin >> q >> k;
	int answer = 0;
	while(q--){
		answer = max(answer, solution());
	}
	cout << answer << "\n";
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
