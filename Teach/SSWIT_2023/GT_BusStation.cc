/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: GT_Bus Station
 * ALGO		: 
 * DATE		: 4 May 2023
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

struct event_t{
	int l, r;
	bool operator < (const event_t &o) const {
		if(l != o.l){
			return l < o.l;
		}
		return r < o.r;
	}
};

const int MxN = 100010;
const int MxQ = 1010;

vector<event_t> line, query;

inline void solution(){
	int n, m, q, l, r, maxx = 0, minn = 1e9 + 100;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(min(l, r), max(l, r));
		maxx = max(maxx, max(l, r));
		minn = min(minn, min(l, r));
	}
	for(int i=1; i<=q; ++i){
		cin >> l >> r;
		query.emplace_back(min(l, r), max(l, r));
		maxx = max(maxx, max(l, r));
		minn = min(minn, min(l, r));
	}
	for(int i=0; i<n; ++i){
		if(current >= 
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
