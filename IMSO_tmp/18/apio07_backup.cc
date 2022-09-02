/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: APIO'07 Backup
 * ALGO		: Linked list, Greedy
 * DATE		: 4 Jul 2022
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

struct Node{
	int l, r, v;
	bool operator < (const Node &o) const {
		return v > o.v;
	}
	Node(int a, int b, int c): l(a), r(b), c(v) {}
};

const int MxN = 100010;
int a[MxN], v[MxN];

inline void solution(){
	int n, k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		v[i] = a[i] - a[i - 1];
	}
	for(int i=1; i<n; ++i){
		pq.emplace(v[i], i);

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
