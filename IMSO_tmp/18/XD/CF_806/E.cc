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
char a[MxN][MxN], b[MxN][MxN], c[MxN][MxN], d[MxN][MxN];

map<pair<int, int>, pair<int, int>> mp[5];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> (a[i] + 1);
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			b[i][j] = a[j][n - i + 1];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			c[i][j] = b[j][n - i + 1];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			d[i][j] = c[j][n - i + 1];
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			int cnt = (int)(a[i][j] + b[i][j] + c[i][j] + d[i][j]) - 4 * '0';
			answer += min(cnt, 4 - cnt);
		}
	}
	cout << (answer / 4);
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
