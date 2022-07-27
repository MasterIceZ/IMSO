/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lomsat Gelral
 * ALGO		: Disjoint Set Union, Sack Technique
 * DATE		: 22 Jul 2022
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

const int MxN = 1e5 + 10;
int color[MxN], answer[MxN];
vector<int> adj[MxN];

struct Node{
	map<int, int> cnt_colors;
	int cnt = 0;
	ll sum = 0ll;
};

inline Node merge(Node u, Node v){
	if(u.cnt_colors.size() > v.cnt_colors.size()){
		swap(u, v);
	}
	// update colors
	for(auto x: u.cnt_colors){
		v.cnt_colors[x.first] += x.second;
		if(v.cnt_colors[x.first] > v.cnt){
			v.cnt = v.cnt_colors[x.first];
			v.sum = x.first;
		}
		else if(v.cnt_colors[x.first] == v.cnt){
			v.sum += x.first;
		}
	}
	return v;
}

Node dfs(int u, int p){
	Node res;
	res.cnt_colors[color[u]]++;
	res.sum = color[u];
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		res = merge(dfs(x, u), res);
	}
	answer[u] = res.sum;
	return res;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> color[i];
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i){
		cout << answer[i] << " "[i == n];
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
