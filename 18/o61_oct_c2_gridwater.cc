/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_oct_c2_gridwater
 * ALGO		: 
 * DATE		: 14 Oct 2022
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

struct Edge{
	int u, v, w;
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
};

const int MxN = 440 * 440;
const int LgN = __lg(MxN) + 10;
int n, m, max_id, parent[MxN], dp[MxN][LgN], wei[MxN][LgN], level[MxN];
vector<Edge> edges, out;
vector<pair<int, int>> adj[MxN];

inline int get_id(int i, int j){
	max_id = max(max_id, i * 400 + j);
	return i * 400 + j;
}

int find_root(int u){
	return u == parent[u] ? u: parent[u] = find_root(parent[u]);
}

void dfs_level(int u, int p, int w){
	level[u] = level[p] + 1;
	wei[u][0] = w;
	dp[u][0] = p;
	for(auto x: adj[u]){
		if(x.first == p || level[u]){
			continue;
		}
		dfs_level(x.first, u, x.second);
	}
}

inline int get_lca(int u, int v){
	if(level[u] > level[v]){
		swap(u, v);
	}
	int res = 0;
	for(int state=20; state>=0; --state){
		if(level[u] < level[dp[v][state]]){
			continue;
		}
		res = max(res, wei[v][state]);
		v = dp[v][state];
	}
	if(v == u){
		return res;
	}
	for(int state=20; state>=0; --state){
		if(dp[u][state] == dp[v][state]){
			continue;
		}
		res = max({res, wei[v][state], wei[u][state]});
		u = dp[u][state];
		v = dp[v][state];
	}
	return max({res, wei[v][0], wei[u][0]});
}

inline void solution(){
	cin >> m >> n;
	for(int i=0, x; i<2*n-1; ++i){
		if(i % 2){
			for(int j=0; j<m; ++j){
				cin >> x;
				edges.emplace_back(get_id(i / 2, j), get_id(i / 2 + 1, j), x);
			}
		}
		else{
			for(int j=0; j<n-1; ++j){
				cin >> x;
				edges.emplace_back(get_id(i / 2, j), get_id(i / 2, j + 1), x);
			}
		}
	}
	sort(edges.begin(), edges.end());
	iota(parent, parent + MxN, 0);
	for(auto x: edges){
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv){
			out.emplace_back(x);
			continue;
		}
		adj[x.u].emplace_back(x.v, x.w);
		adj[x.v].emplace_back(x.u, x.w);
		parent[ru] = rv;
	}
	dfs_level(0, 0, 0);
	for(int state=0; state<=20; ++state){
		for(int i=0; i<max_id; ++i){
			dp[i][state] = dp[dp[i][state - 1]][state - 1];
			wei[i][state] = max(wei[dp[i][state - 1]][state - 1], wei[i][state - 1]);
		}
	}
	int res = 0;
	for(auto x: out){
		res = max(res, x.w - get_lca(x.u, x.v));
	}
	cout << res;
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
