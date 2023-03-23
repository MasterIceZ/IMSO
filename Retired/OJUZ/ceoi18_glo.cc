/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Global Warming 
 * ALGO		: Dynamic Programming
 * DATE		: 23 Mar 2023
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
int lis[MxN], lds[MxN], lds_size[MxN], lis_size[MxN], a[MxN];

inline void solution(){
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sz = 0;
	for(int i=n; i>=1; --i){
		int idx = lower_bound(lds, lds + sz, -a[i]) - lds;
		if(idx == sz){
			sz++;
		}
		lds[idx] = -a[i];
		lds_size[i] = idx + 1;
	}
	sz = 0;
	int res = 0;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(lis, lis + sz, a[i] + x) - lis;
		res = max(res, lds_size[i] + idx);
		idx = lower_bound(lis, lis + sz, a[i]) - lis;
		if(idx == sz){
			sz++;
		}
		lis[idx] = a[i];
		lis_size[i] = sz;
	}
	cout << max(res, lis_size[n]);
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
