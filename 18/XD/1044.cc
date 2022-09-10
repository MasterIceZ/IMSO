/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Road Cut
 * ALGO		: Dynamic Programming
 * DATE		: 5 Sep 2022
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

const int MxN = 111;
int n[3], a[MxN][MxN], qs[3][MxN], ad[3][MxN], all = 0;

inline void solution(){
	cin >> n[1] >> n[2];
	for(int i=1; i<=n[1]; ++i){
		for(int j=1; j<=n[2]; ++j){
			cin >> a[i][j];
			qs[1][i] = qs[1][i] + a[i][j];
			qs[2][j] = qs[2][j] + a[i][j];
			all = all + a[i][j];
		}
	}
	for(int i=1; i<=n[1]; ++i){
		for(int j=1, x; j<=n[2]; ++j){
			cin >> x;
			ad[1][i] = ad[1][i] + x;
			ad[2][j] = ad[2][j] + x;
		}
	}
	int maxx = 0;
	for(int state=1; state<=2; ++state){
		for(int i=1; i<=n[state]; ++i){
			maxx = max(maxx, all - qs[state][i] + ad[state][i - 1] + ad[state][i + 1]);
		}
	}
	cout << maxx;
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
