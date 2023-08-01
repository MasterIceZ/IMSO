/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Trail Maintenance
 * ALGO		: Minimum Spanning Tree
 * DATE		: 11 Jul 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct edge_t {
	int u, v, w;
	bool operator < (const edge_t& o) const {
		return w < o.w;
	}
	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

const int MxN = 220;
int n, parent[MxN];
vector<edge_t> edges;

int find_root(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

inline void solution(){
	int u, v, w, cnt = 0, sum = 0;
	cin >> u >> v >> w;
	edges.emplace_back(u, v, w);
	sort(edges.begin(), edges.end());
	for(auto x: edges) {
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv) {
			continue;
		}
		cnt++;
		sum += x.w;
		parent[ru] = rv;
	}
	cout << (cnt == n - 1 ? sum: -1);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q;
	cin >> n >> q;
	while(q--){
		iota(parent + 1, parent + n + 1, 1);
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
