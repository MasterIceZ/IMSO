/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: all for one
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

const int MxN = 200020;
ll a[MxN];

struct fenwick_tree{
	ll tree[MxN];
	void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	ll query(int idx){
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	void build(){
		for(int i=1; i<MxN; ++i){
			tree[i] += a[i];
			int nxt_i = i&-i;
			if(nxt_i < MxN){
				tree[nxt_i] += tree[i];
			}
		}
	}
} fw;

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	fw.build(n);
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
