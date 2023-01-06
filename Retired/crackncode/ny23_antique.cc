/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Antique
 * ALGO		: Dynamic Programming
 * DATE		: 31 Dec 2022
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

map<pair<int, int>, int> dp;
map<pair<int, int>, bool> done;
int n, k, a, b;

int DP(pair<int, int> expected){
	dbg(expected);
	if(done[expected]){
		return dp[expected];
	}
	for(int i=1; i*i<=expected.second; ++i){
		if(expected.second % i){
			continue;
		}
		for(int from_1=0; from_1<=k; ++from_1){
			for(int from_2=0; from_2<=k; ++from_2){
				// :(
				if((from_1 * from_2) % k != expected.first){
					continue;
				}
				pair<int, int> OwO = make_pair(from_1, i);
				pair<int, int> UwU = make_pair(from_2, expected.second / i);
				if(dp.find(OwO) == dp.end() || dp.find(UwU) == dp.end()){
					continue;
				}
				dbg(OwO, UwU);
				dp[expected] = max(dp[expected], DP(OwO) + DP(UwU));
			}
		}
	}
	done[expected] = true;
	return dp[expected];
}

inline void solution(){
	cin >> n >> k >> a >> b;
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		dp[make_pair(a, b)] = 1;
	}
	cout << DP(make_pair(a, b));
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
