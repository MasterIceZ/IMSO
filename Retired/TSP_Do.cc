/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: TSP_Do
 * ALGO		: Dynamic Programming
 * DATE		: 17 Feb 2023
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

const int MxN = 1550;
int n, a[MxN][MxN], dp[MxN][MxN];

int DP(int l, int r){
	if(dp[l][r] != -1 || dp[r][l] != -1){
		return dp[l][r];
	}
	if(r == n || l == n){
		return dp[l][r] = dp[r][l] = 0;
	}
	int nxt = max(l, r) + 1;
	return dp[l][r] = dp[r][l] = min(a[nxt][l] + DP(nxt, r), a[r][nxt] + DP(l, nxt));
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	cout << DP(1, 1);
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
