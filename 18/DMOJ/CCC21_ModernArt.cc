/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Modern Art
 * ALGO		:
 * DATE		: 25 Sep 2022
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

char o;

inline void solution(){
	int idx, n, m, k;
	cin >> n >> m >> k;
	vector<int> row(n + 1, 0), col(m + 1, 0);
	int cnt = 0;
	while(k--){
		cin >> o >> idx;
		if(o == 'R'){
			row[idx]++;
		}
		else{
			col[idx]++;
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cnt += (row[i] + col[j]) % 2;
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
