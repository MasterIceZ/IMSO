/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi18_constellation
 * ALGO		: Dynamic Programming
 * DATE		: 18 Aug 2022
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

const int MxN = 330;
const int MOD = 1e6 + 3;
char a[MxN][MxN];
int Choose[1010][1010], dp[2 * MxN];

int C(int n, int r){
	if(Choose[n][r] != -1){
		return Choose[n][r];
	}
	if(n == r || n == 1 || r == 1){
		return Choose[n][r] = 1;
	}
	return (C(n - 1, r - 1) + C(n - 1, r)) % MOD;
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				dp[i + j]++;
			}
		}
	}
	for(int i=1; i<=n + m; ++i){
		dp[i] = dp[i] + dp[i - 1];
	}

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
