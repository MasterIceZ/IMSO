/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi18_garden
 * ALGO		: Fenwick Tree, Dynamic Programming
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

const int MxN = 200020;

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
} fw[2];

int dp[2][MxN], a[MxN];

inline void solution(){
	int n, q;
	cin >> n >> q;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		c.emplace_back(a[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
	}
	for(int i=1; i<=n; ++i){
		int t = fw[0].query(a[i] - 1);
		fw[0].update(a[i], t + 1);
		dp[0][i] = t;
	}
	for(int i=n; i>=1; --i){
		int t = fw[1].query(a[i] - 1);
		fw[1].update(a[i], t + 1);
		dp[1][i] = t;
	}
	while(q--){
		int idx;
		cin >> idx;
		idx++;
		cout << min(dp[0][idx], dp[1][idx]) << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
