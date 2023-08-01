/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: B-Partition
 * ALGO		: Search by Elimination
 * DATE		: 13 Jul 2023
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

const int MxN = 1010;

int n, k;
int a[MxN];

inline bool check(int mid) {
	int cnt = 1, sum = a[1];
	for(int i=2; i<=n; ++i) {
		if(sum + a[i] > mid) {
			cnt = cnt + 1;
			sum = a[i];
		}
		else {
			sum = sum + a[i];
		}
	}
	return (cnt <= k);
}

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	int l = *max_element(a + 1, a + n + 1);
	int r = accumulate(a + 1, a + n + 1, 0);
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}	
		else {
			l = mid + 1;
		}
	}
	cout << l;
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
