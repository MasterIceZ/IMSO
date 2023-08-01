/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tenzing and Ball
 * ALGO		: 
 * DATE		: 1 Aug 2023
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

const int MxN = 200020;

int n, a[MxN], dp[MxN], slide_min[MxN];

inline void solution(){
	cin >> n;
	dp[0] = 0;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		slide_min[i] = 1e9 + 100;
	}
	for(int i=1; i<=n; ++i) {
		dp[i] = min(dp[i - 1] + 1, slide_min[a[i]]);
		slide_min[a[i]]  = min(slide_min[a[i]], dp[i - 1]);
	}
	cout << n - dp[n];
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
