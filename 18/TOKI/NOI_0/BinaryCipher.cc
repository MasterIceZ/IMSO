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

bool now_bin[22], k_bin[22];

inline void solution(){
	int q, k, x;
	cin >> q >> k;
	for(int i=0; i<=20; ++i){
		k_bin[i] = (k & (1 << i));
	}
	bool ok;
	while(q--){
		ok = true;
		cin >> x;
		if(x < k){
			cout << "-1\n";
		}
		else{
			for(int i=0; i<=20; ++i){
				now_bin[i] = (x & (1 << i));
			}
//			dbg(to_string(now_bin, 0, 20), to_string(k_bin, 0, 20));
			for(int i=0; i<=20; ++i){
				if(!now_bin[i] && k_bin[i]){
					dbg("NOT OK", i);
					ok = false;
				}
			}
			cout << (ok? x: -1) << "\n";
		}
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
