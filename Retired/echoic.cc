/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Echoic
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

const int MxN = 10010;
const ll MOD = 1e9 + 7;
int a[MxN];
ll dp[2][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	if(a[1] > 0){
		cout << 0;
		return ;
	}
	dp[1][0] = 1ll;
	for(int i=2; i<=n; ++i){
		memset(dp[i & 1], 0, sizeof dp[i & 1]);
		if(a[i] == -1){
			//dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			dp[i & 1][0] = (dp[(i & 1) ^ 1][0] + dp[(i & 1) ^ 1][1]) % MOD;
			for(int j=1; j<=i; ++j){
				//dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
				//dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
				dp[i & 1][j] = (dp[(i & 1) ^ 1][j] + dp[(i & 1) ^ 1][j + 1]) % MOD;
				dp[i & 1][j] = (dp[i & 1][j] + dp[(i & 1) ^ 1][j - 1]) % MOD;
			}
		}
		else{
			//dp[i][a[i]] = (dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
			dp[i & 1][a[i]] = (dp[(i & 1) ^ 1][a[i]] + dp[(i & 1) ^ 1][a[i] + 1]) % MOD;
			if(a[i] != 0){
				//dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % MOD;
				dp[i & 1][a[i]] = (dp[i & 1][a[i]] + dp[(i & 1) ^ 1][a[i] - 1]) % MOD;
			}
		}
	}
	cout << dp[n & 1][0];
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
