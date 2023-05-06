/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Safety Subtask 4
 * ALGO		: Dynamic Programming
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
ll a[MxN];

struct slope_trick{
	multiset<ll> ms_l, ms_r;
	ll min_y = 0;
	inline void add_line(ll value){
		if(ms_l.empty() && ms_r.empty()){
			ms_l.emplace(value);
			ms_r.emplace(value);
		}	
		else if(value <= *ms_l.rbegin()){
			min_y += *ms_l.rbegin() - value;
			ms_r.emplace(*ms_l.rbegin());
			ms_l.erase(--ms_l.end());
			ms_l.emplace(value);
			ms_l.emplace(value);
		}
		else if(value >= *ms_r.begin()){
			min_y += value - *ms_r.begin();
			ms_l.emplace(*ms_r.begin());
			ms_r.erase(ms_r.begin());
			ms_r.emplace(value);
			ms_r.emplace(value);
		}
		else{
			ms_l.emplace(value);
			ms_r.emplace(value);
		}
	};
} dp;

inline void solution(){
	int n, h;
	cin >> n >> h;
	assert(h == 0);
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
