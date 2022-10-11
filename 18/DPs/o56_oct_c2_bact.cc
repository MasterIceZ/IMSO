/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o56_oct_c2_bact
 * ALGO		: Dynamic Programming
 * DATE		: 9 Oct 2022
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

const int MxN = 33;
int v[MxN][MxN], dp[MxN][MxN][MxN][MxN];
int n, m, k, cnt[MxN * MxN][MxN][MxN], all[MxN * MxN], cnt_now[MxN * MxN];

int divide(int a, int b, int c, int d){
	if(dp[a][b][c][d] != -1){
		return dp[a][b][c][d];
	}
	if(a == c || b == d){
		int ct = 0;
		for(int i=1; i<=k; ++i){
			cnt_now[i] = 0;
		}
		for(int i=a; i<=c; ++i){
			for(int j=b; j<=d; ++j){
				cnt_now[v[i][j]]++;
			}
		}
		for(int i=1; i<=k; ++i){
			if(all[i] == cnt_now[i]){
				ct++;
			}
		}
		return dp[a][b][c][d] = ct;
	}
	int A = divide(a + 1, b, c, d) + divide(a, b, a, d);
	int B = divide(a, b + 1, c, d) + divide(a, b, c, b);
	int C = divide(a, b, c - 1, d) + divide(c, b, c, d);
	int D = divide(a, b, c, d - 1) + divide(a, d, c, d);
	return dp[a][b][c][d] = max({A, B, C, D});
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
//			cnt[v[i][j]][i][j]++;
			all[v[i][j]]++;
		}
	}
//	for(int state=1; state<=k; ++state){
//		for(int i=1; i<=n; ++i){
//			for(int j=1; j<=m; ++j){
//				cnt[state][i][j] = cnt[state][i][j] + cnt[state][i - 1][j] + cnt[state][i][j - 1] - cnt[state][i - 1][j - 1];
//			}
//		}
//	}
	cout << divide(1, 1, n, m);
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
