/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fence
 * ALGO		: Segment Tree, Dynamic Programming
 * DATE		: 26 Nov 2022
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

const int MxN = 440;
int a[MxN][MxN];
pair<int, int> minn[200020], maxx[200020];
bitset<200020> found;
int dp[200020], n, m, q;

using pip = pair<pair<int, int>, pair<int, int>> ;

struct SegTree{
	pip t[200020 << 2];
	pip merge_node(pip a, pip b){
		pair<int, int> aa, bb;
		aa.first = min({a.first.first, b.first.first});
		aa.second = min({a.first.second, b.first.second});
		bb.first = max({a.second.first, b.second.first});
		bb.second = max({a.second.second, b.second.second});
		return make_pair(aa, bb);
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			t[idx] = make_pair(minn[l], maxx[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
	}
	pip query(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return make_pair(make_pair(n, m), make_pair(1, 1));
		}
		if(wl <= l && r <= wr){
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return merge_node(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

inline int get_answer(pair<int, int> a, pair<int, int> b){
	return (abs(a.second - b.second) + 1) * 2 + (abs(a.first - b.first) + 1) * 2;
}

inline void solution(){
	cin >> n >> m >> q;
	for(int i=0; i<=200000; ++i){
		minn[i] = make_pair(n, m);
		maxx[i] = make_pair(1, 1);
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			maxx[a[i][j]].first = max(maxx[a[i][j]].first, i);
			maxx[a[i][j]].second = max(maxx[a[i][j]].second, j);
			minn[a[i][j]].first = min(minn[a[i][j]].first, i);
			minn[a[i][j]].second = min(minn[a[i][j]].second, j);
			found[a[i][j]] = true;
		}
	}
	if(found[0]){
		dp[0] = 1;
	}
	for(int i=1; i<=200000; ++i){
		dp[i] = dp[i - 1] + (found[i] ? 1: 0);
	}
	seg.build(1, 200000, 1);
	while(q--){
		int t, k;
		cin >> t >> k;
		if(t == 1){
			dbg(minn[k], maxx[k]);
			if(!found[k]){
				cout << "0\n";
			}
			else{
				cout << get_answer(maxx[k], minn[k]) << "\n";
			}
		}
		else{
			if(k != 0 && dp[200000] - dp[k - 1] == 0){
				cout << "0\n";
			}
			else if(k == 0){
				cout << get_answer(make_pair(n, m), make_pair(1, 1));
			}
			else{
				pip now = seg.query(1, 200000, k, 200000, 1);
				cout << get_answer(now.first, now.second) << "\n";
			}
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
