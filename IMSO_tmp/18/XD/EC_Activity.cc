/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Activity
 * ALGO		: Dynamic Programming
 * DATE		: 11 Jul 2022
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

const int MxN = 150050;
int dp[MxN][3], a[MxN][3];

inline void solution(){
	int n;
	cin >> n;
	vector<int> v = {0, 1, 2};
	for(int i=0; i<=2; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[j][i];
		}
	}
	int answer = 1e9 + 100;
	do{
		dp[1][0] = a[1][v[0]];
		dp[2][0] = dp[1][0] + a[2][v[0]]; dp[2][1] = dp[1][0] + a[2][v[1]];
		dp[3][0] = dp[2][0] + a[3][v[0]]; dp[3][1] = min(dp[2][0], dp[2][1]) + a[3][v[1]]; dp[3][2] = dp[2][1] + a[3][v[2]];
		for(int i=4; i<=n; ++i){
			dp[i][0] = dp[i - 1][0] + a[i][v[0]];
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i][v[1]];
			dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]) + a[i][v[2]];
		}
		answer = min(answer, dp[n][2]);
	}while(next_permutation(v.begin(), v.end()));
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
