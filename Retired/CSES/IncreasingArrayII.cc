/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Increasing Array
 * ALGO		: Slope Trick
 * DATE		: 9 May 2023
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
	multiset<ll> ms;
	ll min_y = 0ll;
	inline void add_line(ll value){
		if(ms.empty()){
			ms.emplace(value);
			return ;
		}
		ms.emplace(value);
		min_y += *ms.rbegin() - value;
		ms.erase(--ms.end());
		ms.emplace(value);
	}
} dp;

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		dp.add_line(a[i]);
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
