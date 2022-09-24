/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_mar_c1_longbanner
 * ALGO		: Segment Tree
 * DATE		: 23 Sep 2022
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
int a[MxN], b[MxN];

template<typename T> 
class segment_tree{
private:
	unsigned int sz;
	T *tree;
	void update(int l, int r, int id, int v, int idx){
		if(l > r || l > id || r < id){
			return ;
		}
		if(l == r){
			tree[idx] = tree[idx] + v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	T read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return 0;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return read(l, mid, wl, wr, idx << 1) + read(mid + 1, r, wl, wr, idx << 1 | 1);
	}
public:
	void update(int idx, int v){
		update(1, sz, idx, v, 1);
		return ;
	}
	T read(int wl, int wr){
		return read(1, sz, wl, wr, 1);
	}
	segment_tree(const unsigned int _sz){
		unsigned int tmp_size = _sz + (1 << 4);
		tree = (T *) calloc(tmp_size << 2, sizeof(T));
		sz = _sz;
	}
};

inline void solution(){
	int n, h, l, it = 1, answer = 0;
	cin >> n >> h >> l;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
		c.emplace_back(b[i]);
	}
	c.push_back(0);
	sort(c.begin(), c.end());
	segment_tree<int> seg(n);
	for(int i=1; i<=n; ++i){
		while(it <= n && a[it] - a[i] <= h){
			int idx = lower_bound(c.begin(), c.end(), b[it]) - c.begin();
			dbg("UPD", it, i);
			seg.update(idx, 1);
			it++;
		}
		for(int j=b[i]-l; j<=b[i]; ++j){
			int idx_1 = lower_bound(c.begin(), c.end(), j) - c.begin();
			int idx_2 = upper_bound(c.begin(), c.end(), j + l) - c.begin() - 1;
			dbg("QRY", i, seg.read(idx_1, idx_2));
			answer = max(answer, seg.read(idx_1, idx_2));
		}
		int idx = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
		seg.update(idx, -1);
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
