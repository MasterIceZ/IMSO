/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Rose Transportation
 * ALGO		: Miniumum Spanning Tree, Binary Search
 * DATE		: 16 Aug 2022
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

class disjoint_set{
private:
	vector<size_t> parent, sz;
public:
	inline size_t find_root(size_t u){
		while(parent[u] != u){
			u = parent[u];
		}
		return u;
	}	
	inline size_t unite(size_t u, size_t v){
		size_t ru = find_root(u), rv = find_root(v);
		if(sz[ru] > sz[rv]){
			sz[ru] = sz[ru] + sz[rv];
			parent[rv] = ru;
			return ru;
		}
		sz[rv] = sz[ru] + sz[rv];
		parent[ru] = rv;
		return rv;
	}
	size_t operator [] (const size_t idx){
		return find_root(idx);
	}
	disjoint_set(size_t n){
		parent.resize(n + 16);
		sz.resize(n + 16, 1);
		iota(parent.begin() + 1, parent.begin() + n + 1, 1);
	}
};

struct Edge{
	int u, v;
	ll w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int _u, int _v, ll _w): u(_u), v(_v), w(_w) {}
};

const int MxN = 100100;
int a[MxN];
vector<Edge> edges;

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	disjoint_set dsu(n);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		edges.emplace_back(u, v, a[u] + a[v]);
	}
	ll sum = 0ll;
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = dsu.find_root(x.u), rv = dsu.find_root(x.v);
		if(ru == rv){
			continue;
		}
		sum += x.w;
		dsu.unite(ru, rv);
	}
	cout << sum;
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
