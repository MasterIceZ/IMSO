/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sails
 * ALGO		: Fenwick Tree
 * DATE		: 17 Jul 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 100010;

struct fenwick_tree {
	ll t[MxN];
	inline void update(int idx, ll val) {
		for(; idx<MxN; idx+=idx&=idx) {
			t[idx] = t[idx] + val;
		}
	}
	inline ll query(int idx) {
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx) {
			res = res + t[idx];
		}
		return res;
	}
};

fenwick_tree fw;
ll current_value;
pair<ll, ll> p[MxN];

inline ll tryLeft(ll l, ll r) {
	ll res = l;
	while(l < r) {
		ll mid = (l + r) >> 1ll;
		ll query_mid = fw.query(mid);
		if(query_mid == current_value) {
			r = mid;
			res = mid;
		}
		else {
			l = mid + 1ll;
		}
	}
	return res;
}

inline ll tryRight(ll l, ll r) {
	ll res = r;
	while(l < r) {
		ll mid = (l + r) >> 1ll;
		ll query_mid = fw.query(mid);
		if(query_mid == current_value) {
			l = mid + 1ll;
			res = l;
		}
		else {
			r = mid;
		}
	}
	return res;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p + 1, p + n + 1);
	for(int i=1; i<=n; ++i) {
		ll middle = p[i].first - p[i].second + 1ll;
		current_value = fw.query(middle);
		ll go_left = tryLeft(1ll, middle);	
		ll go_right = tryRight(middle, p[i].first);
		dbg(go_left, go_right);
		fw.update(go_right + 1ll, 1ll);
		fw.update(p[i].first + 1ll, -1ll);
		fw.update(go_left, 1ll);
		fw.update(go_left + p[i].second - (p[i].first - go_right), -1ll);
	}
	ll res = 0ll;
	for(int i=1; i<MxN; ++i) {
		ll query_i = fw.query(i);
		res = res + ((query_i * (query_i - 1ll)) >> 1ll);
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
