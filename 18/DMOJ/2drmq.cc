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

const int MxN = 1010;
int sparse[15][MxN][15][MxN];

void init(std::vector<std::vector<int>> arr){
	int lg = __lg((int) arr[i].size());
	for(int i=0; i<arr.size(); ++i){
		for(int j=0; j<arr[i].size(); ++j){
			sparse[0][i][0][j] = arr[i][j];
		}
		for(int state_j=1; state_j<=lg; ++state_j){
			for(int j=0; j+(1 << state - 1)<arr[i].size(); ++j){
		}
	}
}

int query(int a, int b, int c, int d){
	return 
}
