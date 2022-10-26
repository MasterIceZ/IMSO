/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi11_segitiga
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

const int MxN = 660;
ll a[MxN], qs[MxN], dp[MxN][MxN], opt_k[MxN][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] = -a[i];
		qs[i] = qs[i - 1] + a[i];
	}
	for(int i=n; i>=1; --i){
		dp[i][i] = 0;
		opt_k[i][i] = i;
		for(int j=i+1; j<=n; ++j){
			dp[i][j] = 1e18;
			for(int k=opt_k[i][j - 1]; k<opt_k[i + 1][j]; ++k){
				ll l = qs[j] - qs[k];
				ll r = qs[k] - qs[i - 1];
				int next_v = -(max(l, r) + 2 * min(l, r) + dp[i][k] + dp[k + 1][j]);
				if(dp[i][j] > next_v){
					dp[i][j] = next_v;
					opt_k[i][j] = k;
				}
			}
		}
	}
	cout << -dp[1][n];
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
