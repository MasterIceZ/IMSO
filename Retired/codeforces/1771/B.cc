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

inline void solution(){
	int n, m;
	cin >> n >> m;
	vector<int> l(n + 3);
	iota(l.begin(), l.end(), 0);
	vector<int> r(n + 3, n);
	for(int i=1, a, b; i<=m; ++i){
		cin >> a >> b;
		if(a > b){
			swap(a, b);
		}
		r[a] = min(r[a], b - 1);
		l[b] = max(l[b], a + 1);
	}
	ll res = 0ll;
	for(int i=1; i<=n; ++i){
		res += (r[i] - l[i] + 1ll);
	}
	cout << res;
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
