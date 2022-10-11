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

const ll MOD = 1e9 + 7;
const int MxN = 1010;
int k[5];
vector<int> adj[5];
// day, mask, stay, town
ll dp[MxN][1 << 3][MxN][5];

inline void solution(){
	int n;
	cin >> n >> k[0] >> k[1] >> k[2];
	adj[0].emplace_back(1);
	adj[1].emplace_back(2);
	adj[0].emplace_back(2);
	adj[2].emplace_back(1);
	
	dp[1][1][0][1] = 1ll;
	for(int day=2; day<=n; ++day){
		for(int mask=0; mask<(1 << 3); ++mask){
			for(int to=0; to<3; ++to){
				for(int here=1; here<=k[to]; ++here){
					dp[day][mask | (1 << to)][here][to] = (dp[day][mask | (1 << to)][here][to] + dp[day - 1][mask | (1 << to)][here - 1][to]) % MOD;
				}
				for(auto `
			}
		}
	}
	cout << dp[n][(1 << 3) - 1];
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
