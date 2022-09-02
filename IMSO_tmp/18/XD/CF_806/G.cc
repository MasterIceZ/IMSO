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
ll a[MxN], dp[MxN][33];
 
inline void solution(){
	int n;
	ll m, answer = 0ll;
	cin >> n >> m;
	memset(dp, 0, sizeof dp);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i][0] = dp[i - 1][0] + a[i] - m;
	}
	ll maxx = *max_element(a + 1, a + n + 1);
//	for(int state=1; state<=__lg(maxx); ++state){
//		dp[state][state] = dp[state - 1][state - 1] + (a[state] / (1 << ((ll)(state))));
//		for(int i=state + 1; i<=n; ++i){
//			ll now = (a[i] / (1 << ((ll)(state))));
//			dp[i][state] = max(dp[i - 1][state] + now - m, dp[i - 1][state - 1] + now);
//		}
//	}
	for(int i=1; i<=n; ++i){
		for(int state=1; state<=__lg(maxx); ++state){
			ll cur = a[i] / (1 << ((ll) state));
			dp[i][state] = max(dp[i - 1][state] + cur - m, dp[i - 1][state - 1] + cur);
		}
	}
	cout << *max_element(dp[n], dp[n] + 30);
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
