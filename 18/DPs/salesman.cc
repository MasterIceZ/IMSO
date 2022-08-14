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

const int MxN = 110;
const int MxD = 1010;
const ll MOD = 1e9 + 7;
ll dp[MxN][MxD];
vector<int> adj[MxN];

inline void solution(){
	int n, m, k, u, v;
	cin >> n >> m >> k;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[v].emplace_back(u);
	}
	for(int i=1; i<=n; ++i){
		adj[i].emplace_back(i);
	}
	dp[1][0] = 1ll;
	for(int day=1; day<=k; ++day){
		for(int i=1; i<=n; ++i){
			for(auto x: adj[i]){
				dp[i][day] = (dp[i][day] + dp[x][day - 1]) % MOD;
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int d, t;
		cin >> d >> t;
		cout << dp[t][d] << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
