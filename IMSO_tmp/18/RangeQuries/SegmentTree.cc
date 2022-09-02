/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segment Tree
 * ALGO		: Sparse Segment Tree
 * DATE		: 25 Aug 2022
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

class Node{
public:
	Node *l, *r;
	int value;
	Node(Node* _l=NULL, Node* _r=NULL, int _value=0): l(_l), r(_r), value(_value) {}
};

class SpaseSegTree{
public:
	void build(int l, int r, Node* now){
		if(l == r){
			now->value = 0;
			return ;
		}
		int mid = (l + r) >> 1;
		now->l = new Node();
		now->r = new Node();
		build(l, mid, now->l);
		build(mid + 1, r, now->r);
		now->value = max(now->l->value, now->r->value);
	}
	
	void update(int l, int r, int idx, int v, Node* now){
		if(l < idx || idx > r){
			return ;
		}
		if(l == r){
			now->value = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, idx, v, now->l); update(mid + 1, r, idx, v, now->r);
		now->value = max(now->l->value, now->r->value);
	}

	int read(int l, int r, int wl, int wr, Node* now){
		if(l > wr || r < wl){
			return -1e9 - 100;
		}
		if(wl <= l && r <= wr){
			return now->value;
		}
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, now->l), read(mid + 1, r, wl, wr, now->r));
	}
} seg;

inline void solution(){
	int n, q, idx, v, l, r, x;
	char opr;
	cin >> n >> q;
	Node* root = new Node(NULL, NULL, 0);
	seg.build(1, n, root);
	for(int i=1; i<=q; ++i){
		cin >> opr;
		if(opr == 'U'){
			cin >> idx >> x;
			seg.update(1, n, idx, x, root);
		}
		else{
			cin >> l >> r;
			cout << seg.read(1, n, l, r, root) << "\n";
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
