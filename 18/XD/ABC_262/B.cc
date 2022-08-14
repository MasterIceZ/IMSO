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
bool mat[MxN][MxN];

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		mat[u][v] = mat[v][u] = true;
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			for(int k=j+1; k<=n; ++k){
				if(mat[i][j] && mat[i][k] && mat[j][k]){
					cnt++;
				}
			}
		}
	}
	cout << cnt;
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
