/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: slide
 * ALGO		: Fenwick Tree
 * DATE		: 16 Nov 2022
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

int t[MxN];

void update(int idx, int v){
	for(; idx<MxN; idx+=idx&-idx){
		t[idx] += v;
	}
}

int query(int idx){
	int r = 0;
	for(; idx; idx-=idx&-idx){
		r += t[idx];
	}
	return r;
}

inline void solution(){
	int n;
	cin >> n;
	vector<int> a(n + 1), c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] = -a[i];
		c.emplace_back(a[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	int cnt = 0;
	for(int i=n; i>=1; --i){
		int id = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
		cnt += query(id);
		update(id, 1);
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
