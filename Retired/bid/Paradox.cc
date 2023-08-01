/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

struct query_t {
	ll x, y;
	int i;
	query_t(ll _x=0ll, ll _y=0ll, int _i=-1):
		x(_x), y(_y), i(_i) {}
	bool operator < (const query_t& o) const {
		if(x != o.x) {
			return x < o.x;
		}
		if(y != o.y) {
			return y < o.y;
		}
		return i < o.i;
	}
};

const int MxN = 100010;
const int MxQ = 100010;

pair<ll, ll> h[MxN];
ll sum[MxN], answer[MxQ];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> h[i].first >> h[i].second;
		sum[i] = h[i].first + h[i].second;
	}
	sort(sum + 1, sum + n + 1);
	sum[0] = 1e18 + 1e18;
	sum[n + 1] = 1e18 + 1e18;
	ll x, y;
	for(int i=1; i<=m; ++i) {
		cin >> x >> y;
		int upper_idx = lower_bound(sum + 1, sum + n + 1, x + y) - (sum + 1);
		int lower_idx = upper_idx - 1;
		dbg(upper_idx, lower_idx);
		cout << min(abs(sum[upper_idx] - (x + y)), abs(sum[lower_idx] - (x + y))) << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
