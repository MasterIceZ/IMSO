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
vector<pair<int, int>> adj[MxN];
int subtree_size[MxN];
vector<int> cut;
bool can = true;

void dfs(int u, int p){
	subtree_size[u] = 1;
	int cutting = -1;
	for(auto x: adj[u]){
		if(x.first == p){
			cutting = x.second;
			continue;
		}
		dfs(x.first, u);
		subtree_size[u] += subtree_size[x.first];
	}
	if(subtree_size[u] == 3){
		if(cutting != -1){
			cut.emplace_back(cutting);
		}
		subtree_size[u] -= 3;
	}
	if(subtree_size[u] > 3){
		can = false;
	}
}

inline void solution(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v, i - 1);
		adj[v].emplace_back(u, i - 1);
	}
	if(n < 3){
		cout << -1;
	}
	else{
		dfs(1, 0);
		if(subtree_size[1] == 1 || subtree_size[1] == 2){
			can = false;
		}
		if(can == false){
			cout << -1;
		}
		else{
			cout << cut.size() << "\n";
			for(auto x: cut){
				cout << x << " ";
			}
		}
	}
	can = true;
	cut.clear();
	for(int i=1; i<=n; ++i){
		adj[i].clear();
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
