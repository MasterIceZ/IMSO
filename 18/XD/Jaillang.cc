/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jaillang
 * ALGO		: Dynamic Programming
 * DATE		: 7 Sep 2022
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
char a[MxN][MxN];
int from_left[MxN][MxN], from_top[MxN][MxN];
int zero_left[MxN][MxN], zero_top[MxN][MxN];

inline bool ok_1(int a, int b, int c, int d, int sz){
	int cnt_0 = zero_left[c][d] - zero_left[a][b - 1];
	int cnt_len = from_left[c][d] - from_left[a][b - 1];
	return (cnt_0 == 0 && cnt_len == sz);
}

inline bool ok_2(int a, int b, int c, int d, int sz){
	int cnt_0 = zero_top[c][d] - zero_top[a][b - 1];
	int cnt_len = from_top[c][d] - from_top[a][b - 1];
	return (cnt_0 == 0 && cnt_len == sz);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 'O'){
				from_left[i][j] = 0;
				zero_left[i][j]++;
			}
			else{
				from_left[i][j] = from_left[i][j - 1] + 1;
			}
			zero_left[i][j] += zero_left[i][j - 1];
		}
	}
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i){
			if(a[i][j] == 'O'){
				from_top[i][j] = 0;
				zero_top[i][j]++;
			}
			else{
				from_top[i][j] = from_top[i - 1][j] + 1;
			}
			zero_top[i][j] += zero_top[i - 1][j];
		}
	}
	int maxx = 0, le, ri, tp, dn;
	bool able, current_able;
	for(int sz=1; sz<=min(n, m); ++sz){
		able = false;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				// (i, j) ... (i, j + sz - 1)
				// ...
				// (i + sz - 1, j) ... (i + sz - 1, j + sz - 1)
				// ...
				// (i + 2 * sz - 2, j) ... (i + 2 * sz - 2, j + sz - 1)
				if(
						ok_1(i, j, i, j + sz - 1, sz) && 
						ok_2(i, j, i + sz - 1, j, sz) &&
						ok_1(i + sz - 1, j, i + sz - 1, j + sz - 1, sz) &&
						ok_2(i + sz - 1, j + sz - 1, i + 2 * sz - 2, j + sz - 1, sz) &&
						ok_1(i + 2 * sz - 2, j, i + 2 * sz - 2, j + sz - 1, sz)
				){
					able = true;
				}
			}
		}
		if(able){
			maxx = sz;
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
