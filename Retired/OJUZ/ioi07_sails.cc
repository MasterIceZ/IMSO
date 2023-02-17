/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sails
 * ALGO		: Fenwick Tree
 * DATE		: 21 Jan 2023
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
	void update(ll idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			t[idx] = t[idx] + v;
		}
	}
	ll query(ll idx){
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx){
			res = res + t[idx];
		}
		return res;
	}
} fw;

pair<ll, ll> a[MxN];

ll get_idx(ll x){
	int l = 0, r = MxN;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		dbg(l, mid, r);
		if(fw.query(mid) >= x){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return l;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		int k = a[i].first - a[i].second;
		fw.update(a[i].first, 1);
		if(k == 0){
			continue;
		}
		ll l = min(a[i].first, get_idx(k));
		ll r = get_idx(fw.query(k) + 1ll);
		fw.update(l, -1ll);
		fw.update(r, -1ll);
		fw.update(r + a[i].second - (a[i].first - l), 1ll);
		dbg(i, "FINISHED");
	}
	ll answer = 0ll;
	for(int i=1; i<MxN; ++i){
		ll now = fw.query(i);
		answer += now * (now - 1) / 2;
	}
	cout << answer;
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
