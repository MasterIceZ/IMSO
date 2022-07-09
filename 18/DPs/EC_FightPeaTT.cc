/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Fight PeaTT
 * ALGO		: Dynamic Programming, Tree, Game Theory
 * DATE		: 9 Jul 2022
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

// Too lazy to write sieve :)
// might be 100% sol but maybe 50%
// Precompute O(nsqrt(n))
// Query O(n) -> Topdown
// O(Nsqrt(N) + N + Q)

// Must change to Sieve :(

const int MxN = 500050;
int dp[MxN];
// if player play this state he will win or lose
vector<int> adj[MxN], mem;
ll sum[MxN];

inline int DP(int u){
	// done
	if(dp[u] != -1){
		return dp[u];
	}
	// only lose in this state
	if(adj[u].size() == 1){
		return dp[u] = 0;
	}
	bool way = false;
	// if there is at least 1 way to make next state lose we go!
	for(auto x: adj[u]){
		if(DP(x) == 0){
			way = true;
		}
	}
	return dp[u] = way;
}

inline void solution(){
	int x;
	cin >> x;
	cout << (DP(x)? "1": "2");
	return ;
}

// create Graph :)
inline void factor(int n){
	int N = n;
	ll sum = 0ll;
	mem.clear();
	for(int i=2; i*i<=N; ++i){
		if(n % i){
			continue;
		}
		while(n % i == 0){
			n /= i;
		}
		sum += (ll) i;
		mem.emplace_back(i);
	}
	if(n != 1){
		sum += (ll) n;
		mem.emplace_back(n);
	}
	for(auto x: mem){
		adj[N].emplace_back(sum - x);
	}
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	

	memset(dp, -1, sizeof dp);
	dp[1] = 0;

	for(int i=2; i<=50000; ++i){
		// factor
		factor(i);	
	}

	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
