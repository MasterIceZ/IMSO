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

const int MxN = 110;
int v[MxN], cnt[MxN];

inline void solution(){
	int n, k, maxx = 0;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		maxx = max(maxx, ++cnt[v[i]]);
	}
	if(k + k < n || maxx > 2){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	memset(cnt, 0, sizeof cnt);	
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	freopen("output.txt", "w", stdout);
	int q = 1;
	cin >> q;
	for(int tt=1; tt<=q; ++tt){
		cout << "Case #" << tt << ": ";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
