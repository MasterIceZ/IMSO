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

const int MxN = 5050;
int n, m;

struct Segment_Tree{
	int tree[MxN << 2], lazy[MxN << 2];
	int merge(int a, int b){
		return min(a, b);
	}
	void build(int l, int r, int idx){
		if(l > r || l > idx || r < idx){
			return ;
		}	
		if(l == r){
			tree[idx] = 0;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void push_lazy(int l, int r, int idx){
		if(lazy[idx] && l != r){
			lazy[idx << 1] = lazy[idx];
			lazy[idx << 1 | 1] = lazy[idx];
			tree[idx << 1] = lazy[idx];
			tree[idx << 1 | 1] = lazy[idx];
			lazy[idx] = 0;
		}
	}
	void update(int l, int r, int wl, int wr, int v, int idx){
		if(l > r || l > wr || r < wl){
			return ;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr){
			tree[idx] = v;
			lazy[idx] = v;
			return ;
		}
		push_lazy(l, r, idx);
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, idx << 1);
		update(mid + 1, r, wl, wr, v, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return 1e9 + 100;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		push_lazy(l, r, idx);
		int mid = (l + r) >> 1;
		return merge(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
	void build(){
		build(1, m, 1);
	}
	void update_point(int idx, int v){
		update(1, m, idx, idx, v, 1);
	}
	void update_range(int l, int r, int v){
		update(1, m, l, r, v, 1);
	}
	int read_point(int idx){
		return read(1, m, idx, idx, 1);
	}
	int read_range(int l, int r){
		return read(1, m, l, r, 1);
	}
} seg[330];

inline void solution(){
	int q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		seg[i].build();
	}
	while(q--){
		int o;
		cin >> o;
		if(o == 1){
			int r, c, x;
			cin >> r >> c >> x;
			seg[r].update_point(c, x);
		}
		else if(o == 2){
			int r, x;
			cin >> r >> x;
			seg[r].update_range(1, m, x);
		}
		else if(o == 3){
			int r, c;
			cin >> r >> c;
			int res = 1e9 + 100;
			res = min(res, seg[r].read_point(c));
			cout << (res == 1e9 + 100 ? 0: res) << "\n";
		}
		else{
			int res = 1e9 + 100;
			for(int i=1; i<=n; ++i){
				res = min(res, seg[i].read_range(1, m));
			}
			cout << (res == 1e9 + 100 ? 0: res) << "\n";
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
