/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: numcode
 * ALGO		: Implementation
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

int n, t;

inline vector<int> get_one(vector<int> a){
	vector<int> b = a;
	b[1] = (a[1] != n - 1);
	for(int i=2; i<=n; ++i){
		if(a[i] == a[i - 1] + 1){
			b[i] = 1;
		}
		else{
			b[i] = 0;
		}
	}
	return b;
}

inline vector<int> get_two(vector<int> a){
	vector<int> b = a;
	b[1] = a[1];
	for(int i=2; i<=n; ++i){
		int tt = a[i] - b[i - 1];
		if(tt < b[i - 1]){
			b[i] = tt;
		}
		else{
			b[i] = a[i] - 2 * b[i - 1];
		}
	}
	return b;
}

inline void solution(){
	cin >> n >> t;
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	if(t == 2){
		a = get_two(a);
	}
	a = get_one(a);
	for(int i=1; i<=n; ++i){
		cout << a[i] << "\n";
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
