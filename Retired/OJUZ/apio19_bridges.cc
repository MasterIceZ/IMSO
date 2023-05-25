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

struct query_t{
	int t, a, b;
	query_t(int _t, int _a, int _b):
		t(_t), a(_a), b(_b) {}
	bool operator < (const query_t & o) const {
		// compare ?
	}
};

const int MxN = 50050;
map<pair<int, int>, int> edge;
int parent[MxN], sz[MxN];

int find_root(int u){
	w
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		pair<int, int> currnet_edge = minmax(u, v);
		edge[current_edge] = w;
	}
	int q, t, a, b;
	cin >> q;
	int k = sqrt(q);
	for(int i=1; i<=q; ++i){
		cin >> t >> a >> b;
		if(i % k == 0){

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
