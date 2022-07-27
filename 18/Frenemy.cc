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

const int MxN = 1010;
const ll MOD = 1e9 + 7;
string s[MxN];
ll dp[MxN][MxN][5];

inline void solution(){
	int n, m;
	cin >> n;
	m = n;
	for(int i=1; i<=n; ++i){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	dp[1][1][1] = 1;
	dp[1][m][2] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i][j] == '0'){
				continue;
			}
			dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1] + dp[i][j - 1][1]) % MOD;
		}
		for(int j=m; j>=1; --j){
			if(s[i][j] == '0'){
				continue;
			}
			dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j][2] + dp[i][j + 1][2]) % MOD;
		}
	}
	dp[n][1][3] = 1;
	dp[n][n][4] = 1;
	for(int i=n; i>=1; --i){
		for(int j=1; j<=m; ++j){
			if(s[i][j] == '0'){
				continue;
			}
			dp[i][j][3] = (dp[i][j][3] + dp[i + 1][j][3] + dp[i][j - 1][3]) % MOD;
		}
		for(int j=m; j>=1; --j){
			if(s[i][j] == '0'){
				continue;
			}
			dp[i][j][4] = (dp[i][j][4] + dp[i + 1][j][4] + dp[i][j + 1][4]) % MOD;
		}
	}
	ll answer = 0ll;
	// dp[1] = dr
	// dp[2] = dl
	// dp[3] = ul
	// dp[4] = ur
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i][j] == '0'){
				continue;
			}
			ll A = (dp[i][j - 1][1] * dp[i][j + 1][3]) % MOD;
			ll B = (dp[i - 1][j][2] * dp[i + 1][j][4]) % MOD;
			dbg(i, j, A, B);
			answer = (answer + ((A * B) % MOD)) % MOD;
			A = (dp[i - 1][j][1] * dp[i + 1][j][3]) % MOD;
			B = (dp[i][j + 1][2] * dp[i][j - 1][4]) % MOD;
			dbg(i, j, A, B);
			answer = (answer + ((A * B) % MOD)) % MOD;
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
