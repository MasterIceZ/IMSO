/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: New Year and Handle Change
 * ALGO		: Dynamic Programming, Search by Elimination [Alien Trick]
 * DATE		: 9 Jul 2023
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

const int MxN = 1000010;

int n, k, l, state[MxN];
string s;
pair<ll, int> dp[MxN];

inline pair<ll, int> calcAlien(ll lambda) {
	dbg("IN Alien");
	for(int i=1; i<=n + 1; ++i) {
		dp[i] = make_pair((ll) MxN, MxN);
	}
	dp[1] = make_pair(0, 0);
	for(int i=1; i<=n; ++i) {
		int right_side = min(n, i + l);
		pair<ll, int> do_this = make_pair(dp[i].first + lambda, dp[i].second + 1);
		dp[right_side] = min(dp[right_side], do_this);

		pair<ll, int> do_nothing = make_pair(dp[i].first + (state[i]), dp[i].second);
		dp[i + 1] = min(dp[i + 1], do_nothing);
	}
	return dp[n + 1];
}

inline ll calc() {
	if((ll) k * l >= n) {
		return 0ll;
	}

	ll l = 0ll, r = (ll) MxN;
	while(l < r) {
		ll mid = (l + r) >> 1ll;
		dbg(l, r, mid);
		pair<ll, int> try_this = calcAlien(mid);
		if(try_this.second <= k) {
			r = mid;
		}
		else {
			l = mid + 1ll;
		}
	}
	pair<ll, int> res = calcAlien(l);
	return res.first - l * k;
}

inline void solution(){
	cin >> n >> k >> l >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i) {
		state[i] = ('A' <= s[i] && s[i] <= 'Z');
	}
	ll answer = calc();
	for(int i=1; i<=n; ++i) {
		state[i] = !state[i];
	}
	answer = min(answer, calc());
	cout << answer;
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
