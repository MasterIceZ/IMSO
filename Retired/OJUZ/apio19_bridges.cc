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

const int MxE = 100010;
const int MxN = 50050;
const int SQ = 1000;

struct edge_t{
	int u, v, w;
};

struct query_t{
	int o, x, y;
	query_t(int _o, int _x, int _y):
		o(_o), x(_x), y(_y) {}
};

struct disjoint_set_t{
	vector<int> parent, sz;
	stack<pair<int, int>> operations; // (from, to)
	
	int find_root(int u){
		while(u != parent[u]){
			u = parent[u];
		}
		return u;
	}
	void unite(int u, int v){
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv){
			return ;
		}
		if(sz[rv] > sz[ru]){
			swap(ru, rv);
		}
		sz[ru] += sz[rv];
		parent[rv] = ru;
		st.emplace(rv, ru);
	}
	void rollback(){
		while(!st.empty()){
			pair<int, int> now = operations.top(); operations.pop();
			sz[now.second] -= sz[now.first];
			parent[now.first] = now.first;
		}
	}
	void init(int n){
		parent.resize(n + 1);
		sz.resize(n + 1);
		for(int i=1; i<=n; ++i){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	disjoint_set_t() {}
};

int n, m, q;
edge_t edges[MxE];
vector<query_t> queries;
bitset<MxQ> change;

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	cin >> q;
	for(int i=1; i<=q; ++i){
		cin >> o >> x >> y;
		queries.emplace_back(o, x, y);
	}
	for(int i=0; i<q; ++i){
		int l = i, r = min(q - 1, i + SQ - 1);
		change = 0;
		dsu.init();
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
