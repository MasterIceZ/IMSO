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

const int MxN = 262144 + 100;
pair<int, int> a[MxN];

inline void solution(){
	int n, it = 0;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x == a[it].first){
			a[it].second++;
		}
		else{
			a[++it].first = x;
			a[it].second = 1;
		}
	}
	stack<pair<int, int>> st;
	for(int i=1; i<=it; ++i){
		if(st.empty() && a[i].first < st.top().first){
			st.emplace(a[i]);
			continue;
		}
	}
	cout << res << "\n";
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
