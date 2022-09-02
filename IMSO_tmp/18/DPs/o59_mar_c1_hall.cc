/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_mar_c1_hall
 * ALGO		: Dynamic Programming
 * DATE		: 12 Jul 2022
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

const int MxN = 10010;
int n, a[MxN], b[MxN << 1], dp[2][MxN << 1];

int gen_dp(){
	int answer = 0;
	for(int i=1; i<=(n << 1); ++i){
		for(int j=i+1; j<=(n << 1); ++j){
			if(b[i] != b[j] || j == i + n){
				dp[i % 2][j] = 0;
				continue;
			}
			dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			answer = max(answer, dp[i % 2][j]);
		}
	}
	return answer;
}

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		b[i + n] = b[i] = a[i];
	}
	int answer = gen_dp();
	reverse(b + 1, b + 2 * n + 1);
	memset(dp, 0, sizeof dp);
	answer = max(answer, gen_dp());
	cout << (answer > n? -1: answer);
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
