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

const int MxN = 110;
int a[MxN], k, dp[MxN][MxN];
pair<int, int> v[MxN];

int DP(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	for(int x=l; x<r; ++x){
		dp[l][r] = min(dp[l][r], DP(l, x) + DP(x + 1, r) + (a[l] == a
	}
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n >> k;
	int it = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == a[i - 1]){
			v[it].second = v[it].second + 1;
		}
		else{
			v[++it] = make_pair(a[i], 1);
		}
	}
	cout << DP(1, it);
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
