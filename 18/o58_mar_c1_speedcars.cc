/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Speedcars
 * ALGO		: Greedy
 * DATE		: 27 Aug 2022
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
pair<ll, ll> a[MxN];

bool cmp(const pair<ll, ll> a, const pair<ll, ll> b){
	if(a.first != b.first){
		return a.first < b.first;
	}
	return a.second > b.second;
}

inline void solution(){
	int n, cnt = 0;
	ll t, v, stp, edp;
	cin >> n >> t;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> v;
		a[i].second = a[i].first + v * t;
	}
	sort(a + 1, a + n + 1, cmp);
	stp = edp = -1;
	for(int i=1; i<=n; ++i){
		if(a[i].second < edp){
			continue;
		}
		if(a[i].second == edp && a[i].first > stp){
			continue;
		}
		cnt += 1;
		stp = a[i].first;
		edp = a[i].second;
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
