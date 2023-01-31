/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pair
 * ALGO		: Fenwick Tree
 * DATE		: 1 Feb 2023
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
pair<ll, ll> a[MxN];

struct fenwick_tree{
	ll t[MxN];
	void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			t[idx] = t[idx] + v;
		}
	}
	ll query(int idx){
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx){
			res = res + t[idx];
		}
		return res;
	}
} fw[2];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].second >> a[i].first;
	}
	sort(a + 1, a + n + 1);
	ll res = 0ll;
	for(int i=1; i<=n; ++i){
		res = res + a[i].second * (fw[0].query(MxN - 1) - fw[0].query(a[i].second));
		res = res + fw[1].query(MxN - 1) - fw[1].query(a[i].second);
		fw[0].update(a[i].second, 1);
		fw[1].update(a[i].second, a[i].second);
	}
	cout << res;
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
