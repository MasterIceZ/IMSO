/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Disaster Dragon
 * ALGO		: Fenwick Tree
 * DATE		: 6 Jan 2023
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

struct fenwick_tree{
	ll t[MxN];
	void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			t[idx] = t[idx] + v;
		}
	}
	ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res = res + t[idx];
		}
		return res;
	}
} fw;

ll d;

inline void solution(){
	int n, q, a, b, x, c;
	cin >> n >> q >> a >> b;
	for(int i=1; i<=q; ++i){
		cin >> d >> x >> c;
		if(d == 1){
			fw.update(1, c);
			fw.update(x + 1, -c);
		}
		else{
			fw.update(x, -c);
			fw.update(n + 1, c);
		}
		int l = 1, r = n, le = 1, ri = n;
		while(l < r){
			int mid = (l + r + 1) >> 1;
			dbg(l, mid, r);
			(fw.read(mid) >= a) ? (l = mid): (r = mid - 1);
		}
		if(l && fw.read(l) >= a){
			ri = l;
		}
		else{
			ri = 0;
		}
		l = 1, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			dbg(l, mid, r);
			(fw.read(mid) <= b) ? (r = mid): (l = mid + 1);
		}
		if(l != n + 1 && fw.read(l) <= b){
			le = l;
		}
		else{
			le = n + 1;
		}
		dbg(le, ri);
		if(ri < le){
			cout << "-1\n";
		}
		else{
			if(le == ri){
				cout << le << "\n";
			}
			else{
				cout << le << " " << ri << "\n";
			}
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
