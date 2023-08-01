/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Running Miles
 * ALGO		: Dynamic Programming
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

const int MxN = 100010;

int n, a[MxN], dp[2][MxN];

// (pref, suf)

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		dp[0][i] = max(dp[0][i - 1], a[i] + i);
	}
	for(int i=n; i>=1; --i) {
		dp[1][i] = a[i] - i;
		if(i == n) {
			continue;
		}
		dp[1][i] = max(dp[1][i], dp[1][i + 1]);
	}
	int answer = 0;
	for(int i=2; i<n; ++i) {
		answer = max(answer, a[i] + dp[0][i - 1] + dp[1][i + 1]);
	}
	cout << answer;
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
