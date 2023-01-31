/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Defense
 * ALGO		: Dynamic Prgramming
 * DATE		: 2 Jan 2022
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

const int MxN = 3030;
ll a[MxN], dp[MxN][MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<k; ++i){
		for(int j=i+1; j<=k; ++j){
			dp[i][j] = a[i] + a[j];
		}
	}
	for(int i=2; i<=n; ++i){
		ll minn = 1e18;
		for(int j=n; j>i; --j){
			if(j - k >= i || j - k <= 0){
				continue;
			}
			minn = min(minn, dp[j - k][i]);
			dp[i][j] = min(dp[i][j], minn + a[j]);
		}
	}
	ll answer = 1e18;
	for(int i=n-k+1; i<n; ++i){
		for(int j=i+1; j<=n; ++j){
			answer = min(answer, dp[i][j]);
		}
	}
	cout << answer;
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
