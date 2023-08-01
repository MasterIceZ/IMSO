/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: TRESNJA
 * ALGO		: Implementation
 * DATE		: 13 Jul 2023
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

ll l, r, power[16];

// (state, digit)
ll dp[16][11];

inline ll get_intersection(int state, ll sum) {
	if(state < 0) {
		return 0ll;
	}
	ll lb = max(sum * power[state], l);
	ll rb = min((sum + 1ll) * power[state] - 1ll, r);
	return lb <= rb ? rb - lb + 1ll: 0ll;
}

ll DP(int state, ll current_digit, ll current_sum) {
	//dbg(state, current_digit);
	ll state_minimum = current_sum * power[state];
	ll state_maximum = (current_sum + 1) * power[state] - 1ll;
	if(state_minimum > r || state_maximum < l) {
		return 0ll;
	}
	if(dp[state][current_digit] != -1ll) {
		return dp[state][current_digit];
	}
	dp[state][current_digit] = 0ll;
	for(ll next_digit=0ll; next_digit<=9ll; ++next_digit) {
		if(next_digit == current_digit) {
			continue;
		}
		ll next_sum = current_sum;
		for(ll next_state=1ll; next_state<=state; ++next_state) {
			next_sum = next_sum * 10ll + next_digit;
			ll mul = next_digit * next_state * next_state;
			ll intersection = get_intersection(state - next_state, next_sum) - get_intersection(state - next_state - 1, next_sum * 10ll + next_digit);
			dp[state][current_digit] = dp[state][current_digit] + mul * intersection + DP(state - next_state, next_digit, next_sum);
		}
	}
	return dp[state][current_digit];
}

inline void solution(){
	cin >> l >> r;
	if(l > r) {
		swap(l, r);
	}
	memset(dp, -1, sizeof dp);
	cout << DP(15, 10ll, 0ll);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	power[0] = 1ll;
	for(int i=1; i<=15; ++i) {
		power[i] = power[i - 1] * 10ll;
	}
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
