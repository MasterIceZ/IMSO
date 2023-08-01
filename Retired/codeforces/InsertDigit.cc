/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

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
	vector<int> a(n), b(n);
	for(auto &x: a){
		cin >> x;
	}
	for(auto &x: b){
		cin >> x;
	}
	int cnt = 0;
	if(a == b){
		cout << 0;
		return ;
	}
	for(int i=0; i<n; ++i){
		if(a[i] != b[i]){
			cnt++;
		}
	}
	if(accumulate(a.begin(), a.end(), 0) == accumulate(b.begin(), b.end(), 0)) {
		cout << 1;
		return ;
	}
	cout << min(cnt, abs(accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0)) + 1);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
