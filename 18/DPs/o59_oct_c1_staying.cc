/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Staying Salesman
 * ALGO		: Dynamic Programming
 * DATE		: 22 Sep 2022
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

const int MxN = 1010;
const ll MOD = 1e9 + 7;
vector<int> adj[5];
int can_stay[5];
// dp(date, town, stay, mask)
ll dp[MxN][5][MxN][1 << 3];

inline void solution(){
	int n;
	cin >> n;
	for(int i=0; i<3; ++i){
		cin >> can_stay[i];
	}
	dp[1][0][1][1] = 1ll;
	for(int day=2; day<=n; ++day){
		for(int mask=1; mask<(1 << 3); ++mask){
			for(int to=0; to<3; ++to){
				// stay here
				for(int stay=1; stay<=can_stay[to]; ++stay){
					dp[day][to][stay][mask | (1 << to)] = (dp[day][to][stay][mask | (1 << to)] + dp[day - 1][to][stay - 1][mask]) % MOD;
				}
				// travel from other
				for(auto from: adj[to]){
					for(int last_stay=1; last_stay<=can_stay[from]; ++last_stay){
						dp[day][to][1][mask | (1 << to)] = (dp[day][to][1][mask | (1 << to)] + dp[day - 1][from][last_stay][mask]) % MOD;
					}
				}
			}
		}
	}
	ll res = 0ll;
	for(int node=0; node<3; ++node){
		for(int stay=1; stay<=can_stay[node]; ++stay){
			res = (res + dp[n][node][stay][(1 << 3) - 1]) % MOD;
		}
	}
	cout << res;
	return ;
}

signed main(){
	
	adj[0].emplace_back(1);
	adj[1].emplace_back(2);
	adj[0].emplace_back(2);
	adj[2].emplace_back(0);

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
