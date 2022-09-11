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
const int MxN = 100010;
ll dp[MxN][9][9];
vector<int> adj[10];

inline void solution(){
	int n;
	cin >> n;
	dp[0][1][0] = 1ll;
	dp[1][2][1] = 1ll;
	dp[1][4][1] = 1ll;
	dp[1][5][1] = 1ll;
	for(int i=2; i<=n; ++i){
		for(int last=1; last<=8; ++last){
			for(auto from: adj[last]){
				for(auto to: adj[from]){
					if(to == last){
						continue;
					}
					dp[i][to][from] = (dp[i][to][from] + dp[i - 1][from][last]) % MOD;
				}
			}
		}
	}
	ll ans_1 = 0ll, ans_2 = 0ll, ans_3 = 0ll, ans_4 = 0ll;
	// D D
	for(int i=1; i<=4; ++i){
		for(auto x: adj[i]){
			if(x > 4){
				continue;
			}
			ans_1 = (ans_1 + dp[n][i][x]) % MOD;
		}
	}
	// D U
	for(int i=1; i<=4; ++i){
		ans_2 = (ans_2 + dp[n][i][i + 4]) % MOD;
	}	
	// U D
	for(int i=5; i<=8; ++i){
		ans_3 = (ans_3 + dp[n][i][i - 4]) % MOD;
	}
	// U U
	for(int i=5; i<=8; ++i){
		for(auto x: adj[i]){
			if(x <= 4){
				continue;
			}
			ans_4 = (ans_4 + dp[n][i][x]) % MOD;
		}
	}
	dbg(ans_1, ans_2, ans_3, ans_4);
	ll res = 0ll;
	for(int i=5; i<=8; ++i){
		for(auto j: adj[i]){
			res = (res + dp[n][i][j]) % MOD;
		}
	}
	cout << res;
	return ;
}

signed main(){
	int nxt;
	for(int i=1; i<=4; ++i){
		// down
		nxt = (i + 1 == 5? 1: i + 1);
		adj[i].emplace_back(nxt);
		nxt = (i - 1 == 0? 4: i - 1);
		adj[i].emplace_back(nxt);
		adj[i].emplace_back(i + 4);
	}
	for(int i=5; i<=8; ++i){
		// top
		nxt = (i + 1 == 9? 5: i + 1);
		adj[i].emplace_back(nxt);
		nxt = (i - 1 == 4? 8: i - 1);
		adj[i].emplace_back(nxt);
		adj[i].emplace_back(i - 4);
	}
	
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
