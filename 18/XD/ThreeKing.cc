/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: threeking
 * ALGO		: Disjoint Set Union, Segment Tree, Lowest Common Ancestor, Sack Technique
 * DATE		: 10 Sep 2022
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

class disjoint_set{
public:
	vector<size_t> parent, hei;
	inline size_t find_root(size_t u){
		while(parent[u] != u){
			u = parent[u];
		}
		return u;
	}
	inline void dfs(size_t u){
		int cnt = 0;
		while(parent[u] != u){
			cnt++;
		}
		return cnt;
	}
	size_t operator [] (const size_t idx){
		return find_root(idx);
	}
	disjoint_set(size_t n){
		parent.resize(n + 16);
		hei.resize(n + 16, 1);
		iota(parent.begin() + 1, parent.begin() + n + 1, 1);
	}
};
disjoint_set dsu(MxN);
int l_r[MxN], merge_time[MxN];

inline void merge(int a, int b, int c, int idx){
	int ra = dsu[a], rb = dsu[b], rc = dsu[c];
	if(dsu.sz[ra] < dsu.sz[rb]){
		swap(ra, rb);
	}
	if(dsu.sz[ra] < dsu.sz[rc]){
		swap(ra, rc);
	}
	if(ra != rb){
		merge_time[rb] = idx;
		dsu.hei[ra] = max(dsu.hei[ra], dsu.hei[rb] + 1);
		dsu.parent[rb] = ra;
	}
	if(ra != rc){
		merge_time[rc] = idx;
		dsu.hei[ra] = max(dsu.hei[ra], dsu.hei[rc] + 1);
		dsu.parent[rc] = ra;
	}
}

inline void solution(){
	int n, m >> q;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> a >> b >> c;
		merge(a, b, c, i);
	}
	for(int i=1; i<n; ++i){
		int a = i, b = i + 1;
		if(dsu[a] != dsu[b]){
			l_r[i] = 1e9 + 100;
			continue;
		}
		if(dsu.dfs(a) > dsu.dfs(b)){
			swap(a, b);
		}
		int year_a = merge_time[a], year_b = merge_time[b];
		// lca
		bool done = false;
		if(dsu.dfs(a) < dsu.dfs(b)){
			if((int) dsu.parent[b] == a){
				done = true;
				l_r[i] = year_b;
				break;
			}
			b = dsu.parent[b];
			year_b = max(year_b, merge_time[b]);
		}
		if(done){
			continue;
		}
		while(dsu.parent[a] != dsu.parent[b]){
			a = dsu.parent[a]; b = dsu.parent[b];
			year_a = max(year_a, merge_time[a]); year_b = max(year_b, merge_time[b]);
		}
		l_r[i] = max(year_a, year_b);
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
