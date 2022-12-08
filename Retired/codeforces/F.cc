/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
int n, d;
ll c, a[MxN], x[MxN];

inline bool ok(int m){
	memset(x, 0ll, sizeof x);
	for(int i=1; i<=n; ++i){
		x[i] = max(a[i], x[i]);
	}
	ll sum = 0ll;
	for(int i=1; i<=d; ++i){
		sum += x[i];
		if(i + m + 1 > d){
			continue;
		}
		x[i + m + 1] = 
	}
}

inline void solution(){
	cin >> n >> c >> d;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int> ());
	if(*max_element(a + 1, a + n + 1) >= c){
		cout << "Infinity";
		return ;
	}
	if(*max_element(a + 1, a + n + 1) * d < c){
		cout << "Impossible";
		return ;
	}
	ll l = 0, r = 200000;
	while(l < r){
		ll mid = (l + r + 1ll) / 2ll;
		bool _ok = ok(mid);
		if(_ok){
			l = mid;
		}
		else{
			r = mid - 1ll;
		}
	}
	dbg(l, r);
	cout << (ok(l) ? to_string(l): "Infinity");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
