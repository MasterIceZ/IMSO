/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: CCTV
 * ALGO		: Minimum Spanning Tree
 * DATE		: 22 Aug 2022
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
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

inline void solution(){
	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, n - 1);
	disjoint_set dsu(n);
	vector<Edge> edges, uses;	
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(++u, ++v, w);
	}
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = dsu[x.u], rv = dsu[x.v];
		if(ru == rv){
			continue;
		}
		dsu.unite(ru, rv);
		uses.emplace_back(x);
	}
	dbg(uses.size());
		sort(uses.begin(), uses.end());
	int cnt = 0;
	for(int i=n-2; i>=0 && cnt < k; --i){
		dbg(uses[i].w);
		uses[i].w >>= 1;
		cnt++;
	}
	int res = 0;
	for(auto x: uses){
		res += x.w;
		dbg(x.w);
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
