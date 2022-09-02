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
ll dp[MxN][10], a;
vector<pair<int, ll>> timer[MxN];

inline void solution(){
	int n, t, x, max_t = 0;
	cin >> n;
	memset(dp, -0x3f, sizeof dp);
	for(int i=1; i<=n; ++i){
		cin >> t >> x >> a;
		timer[t].emplace_back(x, a);
		max_t = max(max_t, t);
	}
	dp[0][0] = 0;
	for(int i=1; i<=max_t; ++i){
		for(int state=0; state<=4; ++state){
			dp[i][state] = dp[i - 1][state];
		}
		for(auto x: timer[i]){
			ll maxx = -1e18;
			int fromm = -1;
			for(int from=0; from<=4; ++from){
				int steps = abs(x.first - from);
				if(i - steps < 0){
					continue;
				}
				if(dp[i - steps][from] < 0ll){
					continue;
				}
				maxx = max(maxx, dp[i - steps][from] + x.second);
				dbg(i, from, dp[i - steps][from] + x.second);
				if(maxx == dp[i - steps][from] + x.second){
					fromm = from;
				}
			}
			dp[i][x.first] = maxx;
			dbg(i, x.first, fromm, maxx);
		}
	}
	cout << *max_element(dp[max_t], dp[max_t] + 5);
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
