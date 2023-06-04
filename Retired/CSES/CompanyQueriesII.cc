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

const int MxN = 200020;
const int MxS = 19;

vector<int> adj[MxN];
int level[MxN], lift[MxS][MxN];

void dfs(int u, int p){
	level[u] = level[p] + 1;
	lift[0][u] = p;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
	}
}

inline int lca(int u, int v){
	if(level[u] > level[v]){
		swap(u, v);
	}
	for(int state=MxS-1; state>=0; --state){
		if(level[u] > level[lift[state][v]]){
			continue;
		}
		v = lift[state][v];
	}
	if(u == v){
		return u;
	}
	for(int state=MxS-1; state>=0; --state){
		if(lift[state][u] != lift[state][v]){
			u = lift[state][u];
			v = lift[state][v];
		}
	}
	return lift[0][u];
}

inline void solution(){
	int n, q, u, v;
	cin >> n >> q;
	for(int i=2, x; i<=n; ++i){
		cin >> x;
		adj[i].emplace_back(x);
		adj[x].emplace_back(i);
	}
	dfs(1, 0);
	for(int state=1; state<MxS; ++state){
		for(int i=1; i<=n; ++i){
			lift[state][i] = lift[state - 1][lift[state - 1][i]];
		}
	}
	while(q--){
		cin >> u >> v;
		cout << lca(u, v) << "\n";
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
