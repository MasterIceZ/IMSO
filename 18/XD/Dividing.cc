/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Dividing
 * ALGO		: Implementation
 * DATE		: 4 Sep 2022
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

const int MxN = 10010;
char a[MxN];
int c[MxN];

inline void solution(){
	int b, it = 1, now, tod = 0, len;
	cin >> (a + 1) >> b;
	len = strlen(a + 1);
	for(int i=1; i<=len; ++i){
		now = tod * 10 + (a[i] - '0');
		tod = now % b;
		c[i] = now / b;
	}
	for(;!c[it]; ++it);
	for(; it<=len; ++it){
		cout << c[it];
	}
	cout << " R " << tod;
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
