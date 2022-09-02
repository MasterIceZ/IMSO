/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Slikar
 * ALGO		: Breadth First Search
 * DATE		: 27 Aug 2022
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

const int MxN = 55;
char a[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	pair<int, int> stp, edp;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'D'){
				stp = make_pair(i, j);
			}
			else if(a[i][j] == 'S'){
				edp = make_pair(i, j);
			}
		}
	}
	q.emplace(stp);
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
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
