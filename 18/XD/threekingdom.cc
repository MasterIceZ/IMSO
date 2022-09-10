/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Three Kingdoms
 * ALGO		: Disjoint Set Union
 * DATE		: 7 Sep 2022
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

int mem[MxN], mem2[MxN];

struct segment_tree{
	int tree[4 * MxN];
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = mem2[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int read(int l, int r, int wl, int wr, int idx){
		if(l > r || r < wl || l > wr){
			return 0;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

class disjoint_set{
public:
	vector<size_t> sz;
	vector<size_t> parent;
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
	size_t get_depth(size_t u){
		if(parent[u] == u){
			return 1;
		}
		return get_depth(parent[u]) + 1;
	}
	disjoint_set(size_t n){
		parent.resize(n + 16);
		sz.resize(n + 16, 1);
		iota(parent.begin() + 1, parent.begin() + n + 1, 1);
	}
};

disjoint_set dsu(MxN);

inline void merge(int a, int b, int c, int tt){
	int ra = dsu[a], rb = dsu[b], rc = dsu[c];
	int sz_a = dsu.sz[ra], sz_b = dsu.sz[rb], sz_c = dsu.sz[rc];
	if(sz_a < sz_b){
		swap(sz_a, sz_b);
		swap(ra, rb);
	}
	if(sz_a < sz_c){
		swap(sz_a, sz_c);
		swap(ra, rc);
	}
	if(ra != rb){
		mem[rb] = tt;
		dsu.sz[ra] = max(dsu.sz[ra], dsu.sz[rb] + 1);
		dsu.parent[rb] = ra;
	}
	if(ra != rc){
		mem[rc] = tt;
		dsu.sz[ra] = max(dsu.sz[ra], dsu.sz[rc] + 1);
		dsu.parent[rc] = ra;
	}
}

inline void solution(){
	int n, m, q;
	cin >> n >> m >> q;
	seg.build(1, n, 1);
	for(int i=1, a, b, c; i<=m; ++i){
		cin >> a >> b >> c;
		merge(a, b, c, i);
	}
	for(int i=1; i<n; ++i){
		// lca
		int a = i, b = i + 1;
		if(dsu[a] != dsu[b]){
			mem2[i] = 1e9 + 100;
			continue;
		}
		if(dsu.get_depth(a) > dsu.get_depth(b)){
			swap(a, b);
		}
		int yr_a = mem[a], yr_b = mem[b];
		bool edited = false;
		while(dsu.get_depth(a) < dsu.get_depth(b)){
			if((int) dsu.parent[b] == a){
				edited = true;
				mem2[i] = yr_b;
				break;
			}
			b = dsu.parent[b];
			yr_b = max(yr_b, mem[b]);
		}
		if(edited){
			continue;
		}
		while(dsu.parent[a] != dsu.parent[b]){
			a = dsu.parent[a]; b = dsu.parent[b];
			yr_a = max(yr_a, mem[a]); yr_b = max(yr_b, mem[b]);
		}
		mem2[i] = max(yr_a, yr_b);
	}
	seg.build(1, n - 1, 1);
	for(int i=1, l, r; i<=q; ++i){
		cin >> l >> r;
		int res = seg.read(1, n - 1, l, r - 1, 1);
		if(res >= 1e9 + 100){
			cout << "-1";
		}
		else{
			cout << res;
		}
		cout << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
