/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Salary Queries
 * ALGO		: Fenwick Tree
 * DATE		: 6 Jul 2022
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

const int MxN = 400040;
int a[MxN];
struct Fenwick{
	int tree[MxN];
	inline void update(int idx, int v){
		for(; idx<=400000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

struct Query{
	int t, x, y;
	Query(int a, int b, int c): t(a), x(b), y(c) {}
};

inline void solution(){
	char o;
	int n, q, x, y;
	cin >> n >> q;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		c.emplace_back(a[i]);
	}
	vector<Query> queries;
	for(int i=1; i<=q; ++i){
		cin >> o >> x >> y;
		if(o == '!'){
			queries.emplace_back(1, x, y);
			c.emplace_back(y);
		}
		else{
		//	if(x > y){
		//		swap(x, y);
		//	}
			queries.emplace_back(2, x, y);
			c.emplace_back(x);
			c.emplace_back(y);
		}
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
		fw.update(a[i], 1);
	}
	for(auto x: queries){
		if(x.t == 1){
			fw.update(a[x.x], -1);
			int idx = upper_bound(c.begin(), c.end(), x.y) - c.begin();
			a[x.x] = idx;
			fw.update(a[x.x], 1);
		}
		else{
			int idx_r = upper_bound(c.begin(), c.end(), x.y) - c.begin();
			int idx_l = lower_bound(c.begin(), c.end(), x.x) - c.begin();
			cout << fw.read(idx_r) - fw.read(idx_l) << "\n";
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
