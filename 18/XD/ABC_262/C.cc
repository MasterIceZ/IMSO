/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
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

const int MxN = 500050;

int a[MxN];

inline void solution(){
	int n;
	cin >> n;
	ll cnt = 0ll;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == i){
			cnt++;
		}
	}
	ll res = (cnt * (cnt - 1ll)) / 2ll;
	cnt = 0ll;
	for(int i=1; i<=n; ++i){
		if(a[i] == i){
			continue;
		}
		int val_i = a[i];
		int val_j = a[val_i];
		cnt += (val_j == i);
	}
	cout << res + (cnt >> 1ll);
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
