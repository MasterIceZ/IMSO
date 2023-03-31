/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Gem
 * ALGO		: ?
 * DATE		: 30 Mar 2023
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
string res;
int p[2 * MxN], w[2 * MxN], sz[2 * MxN];

int find_root(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = find_root(p[u]);
}

inline void unite(int u, int v){
	if(u == v){
		return ;
	}
	if(sz[v] > sz[u]){
		swap(u, v);
	}
	p[v] = u;
	w[u] += w[v];
	sz[u] += sz[v];
}

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		p[i] = i;
		p[i + m] = i + m;
		w[i] = 0;
		w[i + m] = 1;
		sz[i] = 1;
		sz[i + m] = 1;
	}
	for(int i=1; i<=n; ++i){
		cin >> u >> v;
		int ru = find_root(u);
		int rv = find_root(v);
		int rmu = find_root(m + u);
		int rmv = find_root(m + v);
		//p[rmv] = ru;
		//p[rmu] = rv;
		unite(ru, rmv);
		unite(rv, rmu);
	}
	for(int i=1; i<=m/2; ++i){
		cin >> u >> v;
		int ru = find_root(u);
		int rv = find_root(v);
		int rmu = find_root(m + u);
		int rmv = find_root(m + v);
		//p[rv] = rmu;
		//p[ru] = rmv;
		unite(rmu, rv);
		unite(rmv, ru);
	}
	for(int i=1; i<=m; ++i){
		find_root(i);
		find_root(i + m);
	}
	for(int i=1; i<=m; ++i){
		int ri = p[i];
		int rmi = p[i + m];
		dbg(i, ri, rmi, w[ri], w[rmi]);
		if(i == p[i] && (w[ri] == m || w[rmi] == m)){
			dbg("root", i);
			res += "N";
			return ;
		}
	}
	res += "Y";
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 5;
//	cin >> q;
	while(q--){
		solution();
	}
	cout << res << "\n";
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
