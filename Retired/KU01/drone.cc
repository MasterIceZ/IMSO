/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Drone
 * ALGO		: Greedy
 * DATE		: 12 Nov 2022
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

const int MxN = 1010;
int n, a[MxN], cnt[MxN];

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=400; ++i){
		cnt[i] = 1;
	}
	sort(a + 1, a + n + 1, greater<int> ());
	int current_drone = 1, res = 0;
	for(int i=1; i<=n; ++i){
		res = res + a[i] * current_drone;
		if(--cnt[current_drone] == 0){
			cnt[current_drone * 2] = cnt[current_drone * 2] + 9;
			current_drone++;
		}
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
