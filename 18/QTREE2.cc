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

const int MxN = 10010;
vector<pair<int, int>> adj[MxN];
int dp[MxN][15], dist[MxN][15];
string opr;

void dfs(int u, int p){
	lv[u] = lv[p] + 1;
	dp[u][0] = p;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x.first, u);
	}
}

int get_lca(int u, int v){
	if(lv[u] > lv[v]){
		swap(u, v);
	}
	for(int state=14; state>=0; --state){
		if(lv[u] > lv[dp[v][state]]){
			continue;
		}
		v = dp[v][state];
	}
	if(u == v){
		return u;
	}
	for(int state=14; state>=0; --state){
		if(dp[u][state] == dp[v][state]){
			continue;
		}
		u = dp[u][state];
		v = dp[v][state];
	}
	return dp[v][0];
}

inline void solution(){
	int n, m, u, v, w, k;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs(1, 0);
	for(int state=1; state<=14; ++state){
		for(int i=1; i<=n; ++i){
			dp[i][state] = dp[dp[i][state - 1]][state - 1];
		}
	}
	while(1){
		cin >> opr;
		if(opr == "DONE"){
			break;
		}
		else if(opr == "DIST"){
			cin >> u >> v;
			cout << get_lca(u, v);
		}
		else if(opr == "KTH"){
			cin >> u >> v >> k;
			cout << get_kth(u, v, k);
		}
		cout << "\n";
	}
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
