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

const int MxN = 1010;
int a[MxN][MxN];
pair<int, int> dp[MxN][MxN];
// dp[i][j] = {sum, number of ways}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j].first;
			dp[1][j].second = 1;
		}
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(i % 2 == 0){
				int maxx = max(dp[i - 1][j].first, dp[i - 1][j + 1].first);
				dp[i][j].first += maxx;
				if(maxx == dp[i - 1][j].first){
					dp[i][j].second += dp[i - 1][j].second;
				}
				if(maxx == dp[i - 1][j + 1].first){
					dp[i][j].second += dp[i - 1][j + 1].second;
				}
			}
			else{
				int maxx = max(dp[i - 1][j].first, dp[i - 1][j - 1].first);
				dp[i][j].first += maxx;
				if(maxx == dp[i - 1][j].first){
					dp[i][j].second += dp[i - 1][j].second;
				}
				if(maxx == dp[i - 1][j - 1].first){
					dp[i][j].second += dp[i - 1][j - 1].second;
				}
			}
		}
	}
	int max_sum = 0, ways = 0;
	for(int i=1; i<=m; ++i){
		if(dp[n][i].first > max_sum){
			max_sum = dp[n][i].first;
			ways = 0;
		}
		if(dp[n][i].first == max_sum){
			ways = ways + dp[n][i].second;
		}
	}
	cout << max_sum << " " << ways;
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
