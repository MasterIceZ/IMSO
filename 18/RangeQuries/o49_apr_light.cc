/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Light
 * ALGO		: 
 * DATE		: 7 Oct 2022
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

vector<int> c;
int x[MxN];

struct tree_node{
	int v, sum;
	tree_node(int _v, int _sum):
		v(_v), sum(_v) {}
	tree_node():
		v(0), sum(0) {}
};

struct segment_tree{
	tree_node tree[MxN << 2];
	bool lazy[MxN << 2];
	tree_node merge(tree_node a, tree_node b){
		return tree_node(a.v + b.v, a.sum + b.sum);
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = tree_node(c[l] - c[l - 1], c[l] - c[l - 1]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void push_lazy(int l, int r, int idx){
		if(!lazy[idx]){
			return ;
		}
		tree[idx].v = tree[idx].sum - tree[idx].v;
		lazy[idx] = false;
		if(l == r){
			return ;
		}
		lazy[idx << 1] ^= true;
		lazy[idx << 1 | 1] ^= true;
	}
	void update(int l, int r, int wl, int wr, int idx){
		if(l > r || l < wr || r > wl){
			return ;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr){
			lazy[idx] = true;
			push_lazy(l, r, idx);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, idx << 1);
		update(mid + 1, r, wl, wr, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
} seg;

inline void solution(){
	int l, n;
	cin >> l >> n;
	c.emplace_back(0);
	for(int i=1; i<=n; ++i){
		cin >> x[i];
		c.emplace_back(x[i]);
	}
	c.emplace_back(l);
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	seg.build(1, n + 1, 1);
	for(int i=1; i<=n; ++i){
		x[i] = upper_bound(c.begin(), c.end(), x[i]) - c.begin();
	}
	for(int i=1; i<=n; ++i){
		seg.update(1, n + 1, x[i], n + 1, 1);
		cout << seg.tree[1].v << "\n";
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
