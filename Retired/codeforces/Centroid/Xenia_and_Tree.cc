/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Xenia and Tree
 * ALGO		: Centroid Decomposition
 * DATE		: 8 Jan 2023
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
const int LG = 20;

vector<int> adj[MxN];

struct centroid_decomposition{
	bitset<MxN> done;
	int dist[LG][MxN], level[MxN], ancestor[LG][MxN];
	int construct_size(int u, int p){
		subtree_size[u] = 1;
		for(auto x: adj[u]){
			if(done[x] || x == p){
				continue;
			}
			subtree_size[u] += construct_size(v, u);
		}
		return subtree_size[u];
	}
	int find_centroid(int u, int p, int n){
		for(auto x: adj[u]){
			if(done[u] || x == p || subtree_size[x] * 2 <= n){
				continue;
			}
			return find_centroid(x, u, n);
		}
		return u;
	}
	void construct_dist(int u, int p, int w){
		for(auto x: adj[u]){
			if(done[x] || x == p){
				continue;
			}
			dist[state][x] = dist[state][u] + 1;
			construct_dist(x, u, state);
		}
	}
	int build_centroid(int u, int p){
		int cen = find_centroid(u, -1, construct_size(u, -1));
		done[cen] = true;
		ancestor[0][c] = p;
		level[cen] = level[p] + 1;
		construct_dist(cen, p, level[c]);
		for(auto x: adj[cen]){
			if(done[x]){
				continue;
			}
			build_centroid(x, cen);
		}
		return cen;
	}
	int init(int n){
		int cen = build_centroid(1, 0);
		for(int state=1; state<LG; ++state){
			for(int i=1; i<=n; ++i){
				dist[
			}
		}
		return cen;
	}
};

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	while(q--){
		cin >> t >> x;
		if(t == 1){
			color_red(x);
		}
		else{
			cout << get_answer(x) << "\n";
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
