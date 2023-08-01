/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: ?
 * TASK		: CUSKIJA
 * ALGO		: 
 * DATE		: 5 June 2023
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

inline void solution(){
	int n;
	cin >> n;
	vector<int> cnt(3, 0);
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		cnt[x % 3]++;
	}
	bool can = false;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if((i + j) % 3 == 0){
				continue;
			}
			if(i == j){
				can |= (cnt[i] >= 2);
			}
			else{
				can |= (cnt[i] && cnt[j]);
			}
		}
	}
	cout << (can ? "possible": "impossible");
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
