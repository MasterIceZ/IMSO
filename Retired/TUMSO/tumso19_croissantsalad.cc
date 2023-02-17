/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso19_croissantsalad
 * ALGO		: 
 * DATE		: 17 Jan 2023
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

int parent[MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return u = find_root(parent[u]);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	vector<pair<int, int>> edges;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		edges.emplace_back(u, v);
	}
	for(auto x: edges){
		int ru = find_root(x.first);
		int rv = find_root(x.second);
		if(ru == rv){
			continue;
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
