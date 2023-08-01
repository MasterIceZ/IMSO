/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Frog 3
 * ALGO		: Dynamic Programming
 * DATE		: 15 Jul 2023
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

struct convex_hull_trick {
	struct line_t {
		ll m, c;
		line_t(ll _m, ll _c):
			m(_m), c(_c) {}
		ll query(ll x) {
			return m * x + c;
		}
	};
	deque<line_t> dq;
	inline bool isGood(line_t l1, line_t l2, line_t l3) {
		return 1.l * (l2.c - l1.c) * (l1.m - l3.m) < 1.l * (l3.c - l1.c) * (l1.m - l2.m);
	}
	inline void addLine(ll m, ll c) {
		line_t this_line(m, c);
		while((int) dq.size() > 1 && !isGood(dq[(int) dq.size() - 2], dq[(int) dq.size() - 1], this_line)) {
			dq.pop_back();
		}
		dq.emplace_back(this_line);
	}
	inline ll query(ll x) {
		while((int) dq.size() > 1 && dq[0].query(x) > dq[1].query(x)) {
			dq.pop_front();
		}
		return dq.front().query(x);
	}
	convex_hull_trick(ll m, ll c) {
		addLine(m, c);
	}
};

const int MxN = 200020;

int n;
ll c, h[MxN], dp[MxN];

inline void solution(){
	cin >> n >> c;
	for(int i=1; i<=n; ++i) {
		cin >> h[i];
	}
	dp[1] = 0;
	convex_hull_trick cht(-2ll * h[1], h[1] * h[1]);
	for(int i=2; i<=n; ++i) {
		dp[i] = c + h[i] * h[i] + cht.query(h[i]);
		cht.addLine(-2ll * h[i], dp[i] + h[i] * h[i]);
	}
	cout << dp[n];
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
