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

const int MxN = 200020;
int dp[MxN][3], a[MxN];

inline void solution(){
	int n, base_answer = 0;
	string s;
	cin >> n >> s;
	reverse(s.begin(), s.end());
	s = "0" + s;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	reverse(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		if(s[i - 1] == '0' && s[i] == '0'){
			dp[i][0] = dp[i - 1][0];
		}
		else if(s[i - 1] == '1' && s[i] == '0'){
			dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
		}
		else if(s[i - 1] == '1' && s[i] == '1'){
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
			dp[i][1] = dp[i - 1][1] + a[i];
		}
		else if(s[i - 1] == '0' && s[i] == '1'){
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][0] + a[i];
		}
	}
	cout << max(dp[n][0], dp[n][1]);
	memset(dp, 0, sizeof dp);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
