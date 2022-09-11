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

const int MxN = 1e6 + 10;
int p[MxN];
ll v[MxN], dp[MxN], answer;

inline void solution(){
	int n, m, l, u;
	cin >> n >> m >> l >> u;
	for(int i=1; i<=m; ++i){
		cin >> p[i] >> v[i];
		dp[p[i]] = v[i];
	}
	for(int i=1; i<=n; ++i){
		dp[i] = dp[i - 1] + dp[i];
	}
	deque<pair<int, int>> dq; // (idx, value)
	dq.emplace_back(0, 0);
	for(int i=1; i<=n; ++i){
		while(!dq.empty() && dq.back().second < dp){

		}
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
