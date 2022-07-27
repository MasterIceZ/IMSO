/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o57_apr26_orepi
 * ALGO		: Dynamic Programming
 * DATE		: 12 Jul 2022
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

const int MxN = 40040;
ll a[MxN], dp[2][MxN];

// dp[i][j] means cutted i times, with j size

void DP(int l, int r, int wl, int wr, int it){
	if(l > r){
		return ;
	}
	int mid = (l + r) >> 1;
	ll minn = -1e18 - 100;
	int idx = -1;
	for(int i=wl; i<=min(wr, mid); ++i){
		ll cur = dp[(it + 1) % 2][i] + ((a[mid] - a[i]) * (mid - i));
		if(minn > cur){
			minn = cur;
			idx = i;
		}
	}
	dp[it][mid] = minn;
	DP(1, mid - 1, wl, idx, it);
	DP(mid + 1, r, idx, wr, it);
}

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i=1; i<=n; ++i){
		dp[1][i] = a[i] * (ll) i;
	}
	for(int i=2; i<=k; ++i){
		DP(1, n, 1, n, i % 2);
	}
	cout << dp[k % 2][n];
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
