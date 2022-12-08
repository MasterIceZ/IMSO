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
int a[MxN];
bitset<MxN> u, d;

inline void solution(){
	int n;
	cin >> n;
	memset(a, 0, sizeof a);
	d = 0, u = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	if(n == 1){
		cout << "YES";
		return ;
	}
	a[0] = a[n + 1] = 1e9 + 1;
	for(int i=1; i<=n; ++i){
		if(a[i - 1] <= a[i]){
			u[i] = true;
		}
	}	
	for(int i=n; i>=1; --i){
		if(a[i + 1] >= a[i]){
			d[i] = true;
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		if(u[i] && d[i]){
			cnt++;
		}
	}
	cout << (cnt > 1 ? "NO" : "YES");
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
