/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Safety
 * ALGO		: Slope Trick
 * DATE		: 5 May 2023
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
ll a[MxN], h;

struct slope_trick{
	multiset<ll> ms_l, ms_r;
	ll min_y = 0, lz_l = 0, lz_r = 0;
	bool state = false;
	inline void add_line(ll value){
		// real_value = insert_value + lazy
		// insert_value = real_value - lazy
		if(state){
			lz_l -= h; lz_r += h;
		}
		state = true;
		if(ms_l.empty() && ms_r.empty()){
			ms_l.emplace(value);
			ms_r.emplace(value);
		}	
		else if(value <= *ms_l.rbegin() + lz_l){
			min_y += (*ms_l.rbegin() + lz_l) - value;
			ms_r.emplace(*ms_l.rbegin() + lz_l - lz_r);
			ms_l.erase(--ms_l.end());
			ms_l.emplace(value - lz_l);
			ms_l.emplace(value - lz_l);
		}
		else if(value >= *ms_r.begin() + lz_r){
			min_y += value - (*ms_r.begin() + lz_r);
			ms_l.emplace(*ms_r.begin() + lz_r - lz_l);
			ms_r.erase(ms_r.begin());
			ms_r.emplace(value - lz_r);
			ms_r.emplace(value - lz_r);
		}
		else{
			ms_l.emplace(value - lz_l);
			ms_r.emplace(value - lz_r);
		}
	};
} dp;

inline void solution(){
	int n;
	cin >> n >> h;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		dp.add_line(a[i]);
		dbg(dp.min_y);
	}
	cout << dp.min_y;
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
