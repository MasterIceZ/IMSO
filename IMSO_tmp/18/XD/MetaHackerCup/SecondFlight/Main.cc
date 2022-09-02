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
unordered_map<int, ll> adj[MxN], answer[MxN];

inline void solution(){
	int n, m, q, start_node, end_node, u, v;
	ll w, res;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u][v] = adj[v][u] = w;
	}
	int sq = sqrt(m);
	for(int start_node=1; start_node<=n; ++start_node){
		if((int) adj[start_node].size() <= sq){
			continue;
		}
		for(auto middle_node: adj[u]){
			for(auto end_node: adj[middle_node.first]){
				if(start_node == end_node.first){
					continue;
				}
				answer[start_node][end_node.first] = answer[start_node][end_node.first] + min(middle_node.second, end_node.second);
			}
		}
	}
	while(q--){
		cin >> start_node >> end_node;
		if(adj[start_node].size() > adj[end_node].size()){
			swap(start_node, end_node);
		}
		if(adj[start_node].count(end_node)){
			res = adj[start_node][end_node] + adj[start_node][end_node];
		}
		if((int) adj[start_node].size() > sq){
			res = res + answer[start_node][end_node];
		}
		else{
			for(auto middle_node: adj[start_node]){
				if(!adj[middle_node.first].count(end_node)){
					continue;
				}
				res = res + min(middle_node.second, adj[middle_node.first][end_node]);
			}
		}
		cout << res << " ";
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear(); answer[i].clear();
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
//	freopen("output.txt", "w", stdout);
	int q = 1;
	cin >> q;
	for(int tt=1; tt<=q; ++tt){
		dbg(tt);
		cout << "Case #" << tt << ": ";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
