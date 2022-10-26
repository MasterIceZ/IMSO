/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_pair
 * ALGO		: Fenwick Tree
 * DATE		: 26 Oct 2022
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
pair<int, int> a[MxN];

struct fenwick_tree{
	ll tree[MxN];
	void update(int idx, ll v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] = tree[idx] + v;
		}
	}
	ll query(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw, cnt;

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].second >> a[i].first;
	}
	sort(a + 1, a + n + 1);
	ll res = 0ll;
	for(int i=1; i<=n; ++i){
		res = res + a[i].second * (fw.query(100000) - fw.query(a[i].second));
		res = res + cnt.query(100000) - cnt.query(a[i].second);
		fw.update(a[i].second, 1ll);
		cnt.update(a[i].second, a[i].second);
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
