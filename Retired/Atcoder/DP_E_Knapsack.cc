/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Knapsack 2
 * ALGO		: Dynamic Programming
 * DATE		: 4 Mar 2023
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

const int MxV = 100010;
const int MxN = 110;
ll dp[MxV], wei[MxN], w;
int val[MxN];

inline void solution(){
	int n;
	cin >> n >> w;
	for(int i=1; i<=n; ++i){
		cin >> wei[i] >> val[i];
	}
	int sum_val = accumulate(val + 1, val + n + 1, 0);
	memset(dp, 0x3f, sizeof dp);	
	dp[0] = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=sum_val; j>=val[i]; --j){
			dp[j] = min(dp[j], dp[j - val[i]] + wei[i]);
		}
	}
	int idx = -1;
	for(int i=0; i<=sum_val; ++i){
		if(dp[i] <= w){
			idx = i;
		}
	}
	cout << idx;
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
