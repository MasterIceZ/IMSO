/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Longest Increasing Subsequence
 * ALGO		: Dynamic Programming, Fenwick Tree
 * DATE		: 28 Oct 2022
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

const int MxN = 100010;

struct fenwick_tree{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<MxN; idx+=idx&-idx){
			tree[idx] = max(tree[idx], v);
		}
	}
	int query(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res = max(res, tree[idx]);
		}
		return res;
	}
} fw;

inline void solution(){
	int n, answer = 0;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		int t = fw.query(x - 1);
		fw.update(x, t + 1);
		answer = max(answer, t + 1);
	}
	cout << answer;
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
