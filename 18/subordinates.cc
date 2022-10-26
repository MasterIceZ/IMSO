/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: subordinates
 * ALGO		: Dynamic Programming, Tree
 * DATE		: 26 Oct 2022
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

const int MxN = 200020;
int dp[MxN];
vector<int> adj[MxN];

void dfs(int u, int p){
	dbg(u);
	int sum = 1;
	for(auto x: adj[u]){
		dfs(x, u);
		sum = sum + dp[x];
	}
	dp[u] = sum;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=2, x; i<=n; ++i){
		cin >> x;
		adj[x].emplace_back(i);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i){
		cout << dp[i] - 1 << " ";
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
