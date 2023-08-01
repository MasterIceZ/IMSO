/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: The Fair Nut and Rectangles
 * ALGO		: 
 * DATE		: 14 Jul 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct rectangle_t {
	ll x, y, a;
	bool operator < (const rectangle_t &o) const {
		return x < o.x;
	}
	rectangle_t(ll _x=0ll, ll _y=0ll, ll _a=0ll):
		x(_x), y(_y), a(_a) {}
};

struct convex_hull_trick {
	struct line_t {
		ll m, c;
		inline ll query(ll x) {
			return m * x + c;
		}
		line_t(ll _m, ll _c):
			m(_m), c(_c) {}
	};
	deque<line_t> dq;
	// checking l2 is Good
	inline bool isGood(line_t l1, line_t l2, line_t l3) {
		return (__int128_t)(l2.c - l1.c) * (l1.m - l3.m) < (__int128_t)(l3.c - l1.c) * (l1.m - l2.m);
	}
	inline void addLine(ll m, ll c) {
		line_t this_line(m, c);
		while((int) dq.size() > 1 && !isGood(dq[(int) dq.size() - 2], dq[(int) dq.size() - 1], this_line)) {
			dq.pop_back();
		}
		dq.emplace_back(this_line);
	}
	inline ll query(ll x) {
		while((int) dq.size() > 1 && dq[0].query(x) <= dq[1].query(x)) {
			dq.pop_front();
		}
		return dq.front().query(x);
	}
	convex_hull_trick() {
		addLine(0ll, 0ll);
	}
};

const int MxN = 1000010;

ll dp[MxN];
rectangle_t a[MxN];
convex_hull_trick cht;

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].a;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i) {
		dp[i] = -a[i].a + (a[i].x * a[i].y) + cht.query(-a[i].y);
		cht.addLine(a[i].x, dp[i]);
	}
	cout << *max_element(dp + 1, dp + n + 1);
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
