/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_1221
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

const int MxN = 550;
int a[MxN];
pair<int, int> dp[MxN][MxN];

pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b){
	return make_pair(a.first + b.first, a.second + b.second);
}

inline void solution(){
	int n, m, q, u, v, w;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			dp[i][j] = dp[j][i] = make_pair(a[i] + a[j], 2);
		}
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		dp[u][v].first = dp[v][u].first = min(dp[u][v].first, w);
	}
	for(int rest_node=1; rest_node<=n; ++rest_node){
		for(int from=1; from<=n; ++from){
			for(int to=1; to<=n; ++to){
				if(dp[from][to].first > dp[from][rest_node].first + dp[rest_node][to].first){
					dp[from][to] = dp[from][rest_node] + dp[rest_node][to];
				}
				else if(dp[from][to].first == dp[from][rest_node].first + dp[rest_node][to].first){
					dp[from][to].second = max(dp[from][to].second, dp[from][rest_node].second + dp[rest_node][to].second);
				}
			}
		}
	}
	while(q--){
		cin >> u >> v;
		cout << dp[u][v].first << " " << dp[u][v].second << "\n";
	}
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
