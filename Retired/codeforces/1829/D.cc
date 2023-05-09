/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 10000100;
int dp[MxN], idx;

void cal(int n){
	if(dp[n] == idx){
		return ;
	}
	dp[n] = idx;
	if(n % 3 != 0){
		return ;
	}
	int nx = n / 3;
	cal(nx);
	cal(nx + nx);
}

inline void solution(){
	++idx;
	int n, m;
	cin >> n >> m;
	cal(n);
	if(n <= 10){
		dbg(to_string(dp, 1, n));
	}
	cout << (dp[m] == idx ? "YES": "NO");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
