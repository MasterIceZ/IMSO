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

const int MxN = 100010;
vector<int> adj[MxN], rev[MxN];
bitset<MxN> closed, reach[3];

void dfs_adj(int u, int p){
	reach[1][u] = true;
	for(auto x: adj[u]){
		if(closed[x] || x == p || reach[1][x]){
			continue;
		}
		dfs_adj(x, u);
	}
}

void dfs_rev(int u, int p){
	reach[2][u] = true;
	for(auto x: rev[u]){
		if(closed[x] || x == p || reach[2][x]){
			continue;
		}
		dfs_rev(x, u);
	}
}

inline void solution(){
	int n, m, q, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		rev[v].emplace_back(u);
	}
	stack<pair<int, int>> qry;
	while(q--){
		int t, x;
		cin >> t >> x;
		qry.emplace(t, x);
		if(t == 1){
			closed[x] = true;
		}
	}
	dfs_adj(1, 0);
	dfs_rev(n, 0);
	vector<int> answer;
	while(!qry.empty()){
		pair<int, int> now = qry.top(); qry.pop();
		if(now.first == 2){
			answer.emplace_back(reach[1][now.second] && reach[2][now.second]);
			continue;
		}
		closed[now.second] = false;
		for(auto x: rev[now.second]){
			if(!reach[1][x]){
				continue;
			}
			dfs_adj(x, 0);
		}
		for(auto x: adj[now.second]){
			if(!reach[2][x]){
				continue;
			}
			dfs_rev(x, 0);
		}
	}
	reverse(answer.begin(), answer.end());
	for(auto x: answer){
		cout << x << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
