/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_array
 * ALGO		: Segment Tree, Lazy Progagation
 * DATE		: 10 Sep 2022
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

struct query{
	int t, l, r, v;
	query(int _t, int _l, int _r, int _v):
		t(_t), l(_l), r(_r), v(_v) {}
	query(int _t, int _l, int _r):
		t(_t), l(_l), r(_r), v(-1) {}
};

vector<query> qry;
vector<int> c;

struct Segment_Tree{
	ll tree[MxN << 2];
};

inline void solution(){
	int n;
	cin >> n;
	while(q--){
		int opr;
		cin >> opr;
		if(opr == 1){
			int l, r;
			ll v;
			cin >> l >> r >> v;
			l++;
			qry.emplace_back(t, l, r, v);
			c.emplace_back(l); c.emplace_back(r);
		}
		else{
			int l, r;
			cin >> l >> r;
			l++; 
			qry.emplace_back(t, l, r);
			c.emplace_back(l); c.emplace_back(r);
		}
	}
	sort(c.begin(), c.end());
	c.resize(c.begin(), c.end());
	for(auto qr: qry){
		if(qr.t == 1){
			// query
		}
		else{
			// update
		}
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
