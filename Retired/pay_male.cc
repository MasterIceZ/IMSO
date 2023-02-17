/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pay Male
 * ALGO		: Dynamic Programming
 * DATE		: 4 Feb 2023
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

const int MxN = 110;
const ll MOD = 100003;
ll dp[MxN][MxN][MxN][3];

inline void solution(){
	int a, b, c;
	cin >> a >> b >> c;
	memset(dp, 0ll, sizeof dp);
	if(a > 0){
		dp[1][0][0][0] = 1ll;
	}
	if(b > 0){
		dp[0][1][0][1] = 1ll;
	}
	if(c > 0){
		dp[0][0][1][2] = 1ll;
	}
	for(int i=0; i<=a; ++i){
		for(int j=0; j<=b; ++j){
			for(int k=0; k<=c; ++k){
				if(i == 0 && j == 0 && k == 0){
					continue;
				}
				if(i != 0){
					dp[i][j][k][0] = (dp[i][j][k][0] + dp[i - 1][j][k][1]) % MOD;
					dp[i][j][k][0] = (dp[i][j][k][0] + dp[i - 1][j][k][2]) % MOD;
				}
				if(j != 0){
					dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j - 1][k][0]) % MOD;
					dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j - 1][k][2]) % MOD;
				}
				if(k != 0){
					dp[i][j][k][2] = (dp[i][j][k][2] + dp[i][j][k - 1][0]) % MOD;
					dp[i][j][k][2] = (dp[i][j][k][2] + dp[i][j][k - 1][1]) % MOD;
				}
			}
		}
	}
	ll answer = (dp[a][b][c][0] + dp[a][b][c][1]) % MOD;
	answer = (answer + dp[a][b][c][2]) % MOD;
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
