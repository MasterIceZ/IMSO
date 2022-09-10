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
int nawtang, nawnone, a[MxN][MxN], b[MxN][MxN];
int dpa_nawtang[MxN], dpa_nawnone[MxN];
int dpb_nawtang[MxN], dpb_nawnone[MxN];

inline void solution(){
	cin >> nawtang >> nawnone;
	int all = 0;
	for(int i=1; i<=nawnone; ++i){
		for(int j=1; j<=nawtang; ++j){
			cin >> a[i][j];
			dpa_nawnone[i] += a[i][j];
			dpa_nawtang[j] += a[i][j];
			all = all + a[i][j];
		}
	}
	for(int i=1; i<=nawnone; ++i){
		for(int j=1; j<=nawtang; ++j){
			cin >> b[i][j];
			dpb_nawnone[i] += b[i][j];
			dpb_nawtang[j] += b[i][j];
		}
	}
	int maxx = 0;
	for(int i=1; i<=nawnone; ++i){
		maxx = max(maxx, all - dpa_nawnone[i] + dpb_nawnone[i - 1] + dpb_nawnone[i + 1]);
	}
	for(int i=1; i<=nawtang; ++i){
		maxx = max(maxx, all - dpa_nawtang[i] + dpb_nawtang[i - 1] + dpb_nawtang[i + 1]);
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
