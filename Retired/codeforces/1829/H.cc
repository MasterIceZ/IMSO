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

const ll MOD = 1e9 + 7;

inline void solution(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<vector<ll>> dp(2, vector<ll> (66, 0ll));
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	dp[0][63] = 1ll;
	for(int i=1; i<=n; ++i){
		dp[i & 1] = dp[i & 1 ^ 1];
		for(int state=0; state<64; ++state){
			dp[i & 1][state & a[i]] = (dp[i & 1][state & a[i]] + dp[i & 1 ^ 1][state]) % MOD;
		}
	}
	for(int i=0; i<=63; ++i){
		if(__builtin_popcount(i) == k){
			answer = (answer + dp[n & 1][i]) % MOD;
		}
	}
	if(k == 6){
		answer = ((answer + MOD) % MOD - 1ll) % MOD;
	}
	cout << answer;
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
