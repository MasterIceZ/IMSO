/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: machikadomazoku
 * ALGO		: Floyd Warshall, Math
 * DATE		: 2 Dec 2022
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

const int MxN = 550;
ll dp[MxN][MxN], w, d;
int n, m, u, v;

inline void solution(){
	cin >> n >> m;
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=n; ++i){
		dp[i][i] = 0ll;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		u++, v++;
		dp[u][v] = dp[v][u] = min(dp[v][u], w);
	}
	cin >> d;
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	ll all = n * (n - 1ll) / 2ll;
	ll cnt = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			if(dp[i][j] <= d){
				cnt++;
			}
		}
	}
	dbg(cnt);
	if(cnt == 0){
		cout << "0/1";
		return ;
	}
	ll div = __gcd(all, cnt);
	cout << cnt / div << "/" << all / div;
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
