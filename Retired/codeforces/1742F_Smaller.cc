/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Smaller
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

int a[29][3];
ll sz[3];

inline void solution(){
	string x;
	int n, idx, k;
	cin >> n;
	memset(a, 0, sizeof a);
	memset(sz, 0ll, sizeof sz);
	a[1][1] = 1, a[1][2] = 1;
	sz[1] = 1ll, sz[2] = 1ll;
	while(n--){
		cin >> idx >> k >> x;
		for(auto c: x){
			a[c - 'a' + 1][idx] += k;
		}
		sz[idx] += x.size() * k;
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
