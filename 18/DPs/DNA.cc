/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: DNA
 * ALGO		: Dynamic Programming
 * DATE		: 15 June 2022
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

const int MxN = 220;
int dp[MxN][MxN];
char s[MxN], t[MxN];

inline void solution(){
	cin >> (s + 1) >> (t + 1);
	int maxx = 0, n = strlen(s + 1), m = strlen(t + 1);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i] != t[j]){
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1] + 1;
			maxx = max(maxx, dp[i][j]);
		}
	}
	int pos = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(dp[i][j] == maxx){
				pos = i;
				break;
			}
		}
	}
	stack<char> st;
	while(maxx--){
		st.emplace(s[pos--]);
	}
	while(!st.empty()){
		cout << st.top(); st.pop();
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
