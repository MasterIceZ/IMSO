/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct18_rocks
 * ALGO		: Dynamic Programming
 * DATE		: 11 Oct 2022
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

const int MxN = 55;
int a[MxN << 1];
int dp[MxN << 1][MxN << 1]; 
// (i, choose [l, r])

int DP(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l > r){
		return dp[l][r] = 0;
	}
	if(l == r){
		return dp[l][r] = a[l];
	}
	int res = 0;
	res = max(res, DP(l, r - 2) + a[r]);
	res = max(res, DP(l + 2, r) + a[l]);
	res = max(res, DP(l + 1, r - 1) + max(a[l], a[r]));
	return dp[l][r] = res;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=2 * n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << DP(1, 2 * n);
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
