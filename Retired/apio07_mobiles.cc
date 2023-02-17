/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: apio07_mobiles
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 31 Jan 2023
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

const int MxN = 100010;
pair<int, int> adj[2 * MxN];
bitset<2 * MxN> leaf;
int bal[2 * MxN], lv[2 * MxN], dp[2 * MxN];

void dfs(int u){
	if(leaf[u]){
		lv[u] = 1;
		bal[u] = 1;
		return ;
	}
	dfs(adj[u].first); dfs(adj[u].second);
	lv[u] = max(lv[adj[u].first], lv[adj[u].second]) + 1;
	bal[u] = min(bal[adj[u].first], bal[adj[u].second]);
	dp[u] = dp[adj[u].first] + dp[adj[u].second];
	if(bal[u] < 0){
		return ;
	}
	if(!bal[adj[u].first] && !bal[adj[u].second]){
		bal[u] = -1;
		return ;
	}
	if(lv[adj[u].first] == lv[adj[u].second]){
		dp[u] = dp[u] + (bal[adj[u].first] < bal[adj[u].second]);
		return ;
	}
	bal[u] = 0;
	if(lv[adj[u].first] < lv[adj[u].second]){
		swap(adj[u].first, adj[u].second);
		dp[u]++;
	}
	if(lv[adj[u].first] > lv[adj[u].second] + 1){
		bal[u] = -1;
		return ;
	}
	if(!bal[adj[u].second]){
		bal[u] = -1;
	}
}

inline void solution(){
	int n;
	cin >> n;
	int it = n;
	for(int i=1; i<=n; ++i){
		cin >> adj[i].first >> adj[i].second;
		if(adj[i].first == -1){
			adj[i].first = ++it;
			leaf[adj[i].first] = true;
		}
		if(adj[i].second == -1){
			adj[i].second = ++it;
			leaf[adj[i].second] = true;
		}
	}
	dfs(1);
	cout << (bal[1] < 0 ? bal[1]: dp[1]);
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
