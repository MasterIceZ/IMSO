/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sheep and Coyotes (Hard)
 * ALGO		:
 * DATE		: 25 Sep 2022
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
pair<int, int> a[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	auto cmp = [&](pair<int, int> a, pair<int, int> b){
		if(a.second != b.second){
			return a.second < b.second;
		}
		return a.first < b.first;
	};
	sort(a + 1, a + n + 1, cmp);
	int it = 1, wanted = a[1].second;
	while(a[it].second == wanted){
		it++;
	}
	for(int i=1; i<it; ++i){
		cout << "The sheep at (" << a[i].first << ", " << a[i].second << ") might be eaten.\n";
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
