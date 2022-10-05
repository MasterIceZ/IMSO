/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Collect Fruits
 * ALGO		: Dynamic Programming
 * DATE		: 30 Sep 2022
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

const int MxN = 10010;
ll a[MxN], dp[MxN][4];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	dp[1][1] = a[1];
	for(int i=2; i<=n; ++i){
		dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
		dp[i][1] = dp[i - 1][0] + a[i];
		dp[i][2] = dp[i - 1][1] + a[i];
		dp[i][3] = dp[i - 1][2] + a[i];
	}
	cout << *max_element(dp[n], dp[n] + 4);
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
