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

const int MxN = 2000020;
const int MxA = 1000010;

int a[MxN];
bitset<MxA> have;

inline void solution(){
	int n, all = 0;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		have[a[i]] = true;
	}
	for(int i=1; i<=1000000; ++i) {
		int current_gcd = -1;
		for(int j=i; j<=1000000; j += i) {
			if(!have[j]) {
				continue;
			}
			if(current_gcd == -1) {
				current_gcd = j;
			}
			else {
				current_gcd = __gcd(current_gcd, j);
			}
		}
		// check that can all `i` to the array
		if(current_gcd != i) {
			continue;
		}
		all += 1;
	}
	cout << all - n;
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
