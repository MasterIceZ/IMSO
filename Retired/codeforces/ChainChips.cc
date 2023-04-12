/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Chain Chips
 * ALGO		: 
 * DATE		: 7 Apr 2023
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

const int MxN = 200020;

struct Node{
	ll v[2][2];
	Node(){
		v[0][0] = v[1][0] = v[0][1] = v[1][1] = 1e18 + 100;
	}
	inline void init(int idx, int n
};

struct segment_tree{
	Node tree[MxN << 2];
	Node merge_node(Node a, Node b){
		Node res;
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){

		}
		int mid = (l + r) >> 1;

	}
} seg;

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<n; ++i){
		cin >> a[i];
	}
	seg.build(1, n - 1, 1);
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
