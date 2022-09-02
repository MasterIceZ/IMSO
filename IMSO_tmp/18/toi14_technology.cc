/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi14_technology
 * ALGO		: Depth First Search
 * DATE		: 5 Jul 2022
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
vector<int> adj[MxN], level[MxN];
bitset<MxN> in, out;
int t; 

void dfs(int u){
	if(in[u]){
		t = 0;
		return ;
	}
	in[u] = true;
	for(auto x: adj[u]){
		if(out[x]){
			continue;
		}
		dfs(x);
	}
	out[u] = true;
	t = t - 1;
}

inline void solution(){
	int n, k, l, p;
	cin >> n >> k >> t;
	for(int i=1; i<=n; ++i){
		cin >> l >> p;
		level[l].emplace_back(i);
		for(int j=1, x; j<=p; ++j){
			cin >> x;
			adj[i].emplace_back(x);
		}
	}
	int idx;
	for(idx=1; idx<=k; ++idx){
		for(auto x: level[idx]){
			if(!out[x]){
				dfs(x);
			}
		}
		if(t <= 0){
			break;
		}
	}
	idx -= (t < 0);
	cout << (idx == 0? -1: idx);
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
