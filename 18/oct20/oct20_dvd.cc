/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_dvd
 * ALGO		: 
 * DATE		: 6 Oct 2022
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
int p[MxN];

struct Node{
	int minn, maxx;
	Node(int _minn, int _maxx): 
		minn(_minn), maxx(_maxx) {}
	Node():
		minn(0), maxx(0) {}
};

struct Segment_Tree{
	Node tree[MxN << 2];
	Node merge(Node a, Node b){
		return Node(min(a.minn, b.minn), max(a.maxx, b.maxx));
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = Node(l, l);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void update(int l, int r, int id, int v, int idx){
		if(l > r || l > id || id < r){
			return ;
		}
		if(l == r){
			tree[idx] = Node(v, v);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	Node read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return Node(1e9 + 100, -1e9 - 100);
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return merge(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

inline void solution(){
	int n, q, t, l, r;
	cin >> n >> q;
	seg.build(1, n, 1);
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	while(q--){
		cin >> t >> l >> r;
		++l, ++r;
		if(t == 0){
			swap(p[l], p[r]);
			seg.update(1, n, l, p[l], 1);
			seg.update(1, n, r, p[r], 1);
		}
		else{
			Node now = seg.read(1, n, l, r, 1);
			cout << (now.minn == l && now.maxx == r ? "YES": "NO") << "\n";			
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
