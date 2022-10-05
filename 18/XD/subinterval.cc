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

const int MxN = 100010;
ll a[MxN], dp[3][MxN], sum_dp[3][MxN];

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		// front ladder
		dp[1][i] = dp[1][i - 1] + i * a[i]; // front ladder
		// sum front ladder (answer from 1 to i)
		sum_dp[1][i] = sum_dp[1][i - 1] + dp[1][i]; 
	}
	for(int i=n; i>=1; --i){
		// suffix sum
		dp[2][i] = dp[2][i + 1] + a[i];
		// back ladder
		sum_dp[2][i] = sum_dp[2][i + 1] + (n - i + 1) * a[i]; 
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		// answer(r) - answer(l - 1)
		ll pref_sum = sum_dp[1][r] - sum_dp[1][l - 1];
		// delete prefix bottom layer
		pref_sum = pref_sum - (r - l + 1ll) * dp[1][l - 1]; 
		// delete back
		pref_sum = pref_sum - (l - 1ll) * (sum_dp[2][l] - sum_dp[2][r + 1] - (n - r) * (dp[2][l] - dp[2][r + 1]));
		cout << pref_sum << "\n";
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
