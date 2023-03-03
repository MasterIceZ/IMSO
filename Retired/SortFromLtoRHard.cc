/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sort L to R (Hard)
 * ALGO		: Segment Tree
 * DATE		: 28 Feb 2023
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

struct Node{
	vector<int> data;
	Node() {}
} none;

const int MxN = 50050;
int a[MxN];

struct segment_tree{
	Node tree[MxN << 2];
	Node merge(Node l, Node r){
		Node t;
		int i = 0, j = 0;
		while(i < (int) l.data.size() && j < (int) r.data.size() && (int) t.data.size() != 10){
			if(l.data[i] < r.data[j]){
				t.data.emplace_back(l.data[i++]);
			}
			else{
				t.data.emplace_back(r.data[j++]);
			}
		}
		while(i < (int) l.data.size() && (int) t.data.size() != 10){
			t.data.emplace_back(l.data[i++]);
		}
		while(j < (int) r.data.size() && (int) t.data.size() != 10){
			t.data.emplace_back(r.data[j++]);
		}
		return t;
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx].data = {a[idx]};
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1],tree[idx << 1 | 1]);
	}
	Node query(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return none;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return merge(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

inline void solution(){
	int n, q, l, r;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	seg.build(1, n, 1);
	while(q--){
		cin >> l >> r;
		Node response = seg.query(1, n, l + 1, r + 1, 1);
		for(auto x: response.data){
			cout << x << " ";
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
