/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Dynamic Range Minimum Queries
 * ALGO		: Segment Tree
 * DATE		: 6 Jul 2022
 * */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 200020;
int tree[4 * MxN];

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		cin >> tree[idx];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
}

void update(int l, int r, int id, int v, int idx){
	if(l > r || l > id || r < id){
		return ;
	}
	if(l == r){
		tree[idx] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, id, v, idx << 1);
	update(mid + 1, r, id, v, idx << 1 | 1);
	tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
}

int query(int l, int r, int wl, int wr, int idx){
	if(l > r || l > wr || r < wl){
		return 1e9 + 100;
	}
	if(wl <= l && r <= wr){
		return tree[idx];
	}
	int mid = (l + r) >> 1;
	return min(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
}

inline void solution(){
	int n, q, a, b, opr;
	cin >> n >> q;
	build(1, n, 1);
	while(q--){
		cin >> opr >> a >> b;
		if(opr == 1){
			update(1, n, a, b, 1);
		}
		else{
			cout << query(1, n, a, b, 1) << "\n";
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
