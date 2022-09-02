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

const ll MOD = 998244353;
ll a[110], dp[110][110][110];
int n;

// dp[i][j][k] => now @i, choose = j, mod = k

ll knapsack(ll Max_W){
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1ll;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=min(Max_W, (ll) i); ++j){
			dp[i][0][0] = dp[i - 1][0][0];
			for(int k=0; k<Max_W; ++k){
				dp[i][j][k] = dp[i - 1][j][k];
			}
			for(int k=0; k<Max_W; ++k){
				ll from = (k + Max_W - (a[i] % Max_W)) % Max_W;
				dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][from]) % MOD;
			}
		}
	}
	return dp[n][Max_W][0];
}

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll ways = 0ll;
	for(int sz=1; sz<=n; ++sz){
		ll from_knapsack = knapsack(sz);
		ways = (ways + from_knapsack) % MOD;
	}
	cout << ways;
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
