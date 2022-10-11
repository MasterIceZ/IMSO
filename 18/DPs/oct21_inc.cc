/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_inc
 * ALGO		: Dynamic Prgramming
 * DATE		: 10 Oct 2022
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

const int MxN = 1010;
int a[MxN], dp[MxN], from[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int maxx = 0, idx = -1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<i; ++j){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j]);
				if(dp[i] == dp[j]){
					from[i] = j;
				}
			}
		}
		dp[i]++;
		maxx = max(dp[i], maxx);
		if(maxx == dp[i]){
			idx = i;
		}
	}
	vector<int> v;
	while(from[idx] != 0){
		v.emplace_back(a[idx]);
		idx = from[idx];
	}
	v.emplace_back(a[idx]);
	reverse(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto x: v){
		cout << x << " ";
	}
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
