/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: nongkhai peeker
 * ALGO		: Divide and Conquer
 * DATE		: 27 Sep 2023
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

const int MxN = 300030;
vector<pair<ll, ll>> a;

inline ll getDist(pair<ll, ll> &a, pair<ll, ll> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool compareY(const pair<ll, ll> a, const pair<ll, ll> b) {
	return a.second < b.second;
}

ll divide(int l, int r) {
	ll res = 1e18 + 100ll;
	if(r - l + 1 <= 3) {
		for(int i=l; i<=r; ++i) {
			for(int j=i+1; j<=r; ++j) {
				res = min(res, getDist(a[i], a[j]));
			}
		}
		return res;
	}
	int mid = (l + r) >> 1;	
	ll left_divide = divide(l, mid);
	ll right_divide = divide(mid + 1, r);
	res = min(left_divide, right_divide);
	vector<pair<ll, ll>> strip;
	for(int i=l; i<=r; ++i) {
		if(abs(a[i].first - a[mid].first) >= res) {
			continue;
		}
		strip.emplace_back(a[i]);
	}
	sort(strip.begin(), strip.end(), compareY);
	for(int i=0; i<(int) strip.size(); ++i) {
		for(int j=i+1; j<(int) strip.size() && strip[j].second - strip[i].second < res; ++j) {
			res = min(res, getDist(strip[i], strip[j]));
		}
	}
	return res;
}

inline void solution(){
	int n;
	ll x, y;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> x >> y;
		a.emplace_back(x, y);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	cout << divide(0, (int) a.size() - 1);
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
