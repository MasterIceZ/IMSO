/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Circle
 * ALGO		: Math
 * DATE		: 26 Nov 2022
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

const int MxN = 330;
int a[MxN][3];

inline void solution(){
	int n;
	cin >> n;
	a[0][1] = 1; a[0][2] = 1;
	for(int i=1; i<=n; ++i){
		cin >> a[i][1];
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i][2];
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		int min_a = min(a[i][1], a[i - 1][1]);
		int max_a = max(a[i][1], a[i - 1][1]);
		int min_b = min(a[i][2], a[i - 1][2]);
		int max_b = max(a[i][2], a[i - 1][2]);
		pair<int, int> x, y;
		x = make_pair(min_a, max_a);
		y = make_pair(min_b, max_b);
		if(x > y){
			swap(x, y);
		}
		if(x == y){
			cnt++;
		}
		else if(x.first < y.first && y.first < x.second && x.second < y.second){
			cnt++;
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
