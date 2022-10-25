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

const int MxC = 100010;
const int MxN = 330;
int c, n, m, room[MxC];
ll t[MxC], dp[MxN][MxN];

inline bool ok(ll mid){
	bool alive = true;
	ll time_left = t[1];
	for(int i=2; i<=c; ++i){
		ll use_time = dp[room[i - 1]][room[i]] * mid;
		ll minimum_arrive = max(0ll, use_time - time_left);
		dbg(use_time, time_left, minimum_arrive);
		if(t[i] - minimum_arrive <= 0){
			alive = false;
			break;
		}
		else{
			time_left = t[i] - minimum_arrive;
		}
		dbg(time_left);
	}
	dbg(alive);
	return alive;
}

inline void solution(){
	cin >> c >> n >> m;
	for(int i=1; i<=c; ++i){
		cin >> room[i];
	}
	for(int i=1; i<=c; ++i){
		cin >> t[i];
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=n; ++i){
		dp[i][i] = 0ll;
	}
	for(int i=1; i<=m; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		dp[u][v] = dp[v][u] = min(dp[v][u], w);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	ll l = 1, r = 1e12;
	while(l < r){
		ll mid = (l + r + 1ll) >> 1ll;
		dbg(l, mid, r);
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1ll;
		}
	}
	cout << l;
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
