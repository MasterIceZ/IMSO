/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Delivery
 * ALGO		: 
 * DATE		: 3 Oct 2022
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

const int MxN = (1 << 16) * 2 + 10;
const int LgN = __lg(MxN) + 3;
vector<int> adj[MxN];
set<pair<int, int>> have_edge;
int lift[LgN][MxN], level[MxN];

inline void add_edge(int u, int v){
	if(!have_edge.count(make_pair(u, v))){
		adj[u].emplace_back(v);
		have_edge.emplace(u, v);
	}
	if(!have_edge.count(make_pair(v, u))){
		adj[v].emplace_back(v, u);
		have_edge.emplace(v, u);
	}
}

void dfs(int u, int p){
	level[u] = level[p] + 1;
	lift[0][u] = p;
	for(auto x: adj[u]){
		if(x == p || level[x]){
			continue;
		}
		dfs(x, u);
	}
}

inline void solution(){
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int k, q, l;
	cin >> k >> q >> l;
	int back_tree_offset = (1 << k);
	for(int i=1; i<(1 << (k - 1)); ++i){
		add_edge(i, i << 1);
		add_edge(i, i << 1 | 1);
		add_edge(i + back_tree_offset, (i << 1) + back_tree_offset);
		add_edge(i + back_tree_offset, (i << 1 | 1) + back_tree_offset);
	}
	dfs(1, 0);
	dfs(next_tree + 1, 0);
	for(int state=1; state<LgN; ++state){
		for(int i=1; i<(1 << k); ++i){
			int front_tree = i;
			int back_tree = i + back_tree_offset;
			lift[state][front_tree] = lift[state - 1][lift[front_tree][state - 1]];
			lift[state][back_tree] = lift[state - 1][lift[back_tree][state - 1]];
		}
	}
	vector<pair<int, int>> bridges;
	for(int i=1, u, v; i<=n; ++i){
		cin >> u >> v;
		add_edge(u, v);
		bridges.emplace_back(u, v);
	}
	for(int idx=1, state=0; idx<=l; ++idx, ++state){
		
	}
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
