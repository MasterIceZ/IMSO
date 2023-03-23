/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Bonus
 * ALGO		: Search by Elimination
 * DATE		: 20 Mar 2023
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
int n, b, a[MxN];

inline bool ok(int mid){
	int res = 0;
	for(int i=1; i<=n; ++i){
		int cnt = a[i] / mid;
		if(a[i] % mid){
			cnt++;
		}
		res += cnt;
	}
	return res <= b;
}

inline void solution(){
	cin >> n >> b;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int l = 1, r = *max_element(a + 1, a + n + 1);
	while(l < r){
		int mid = (l + r) >> 1;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l;
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
