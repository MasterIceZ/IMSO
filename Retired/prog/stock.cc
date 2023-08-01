/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Stock
 * ALGO		: Dynamic Programming
 * DATE		: 4 Jul 2023
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

const int MxN = 1000010;

int a[MxN], sum[MxN];

inline void solution(){
	int n, q, l, r;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		if(i == 1) {
			continue;
		}
		sum[i] = sum[i - 1] + max(a[i] - a[i - 1], 0);
	}
	cin >> q;
	while(q--) {
		cin >> l >> r;
		cout << sum[r] - sum[l] << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
