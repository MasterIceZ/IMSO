/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Job Hopper
 * ALGO		: Search By Elimination
 * DATE		: 20 Nov 2022
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

const int MxN = 3030;
int n, m, dp[MxN];
pair<int, int> a[MxN];

inline bool ok(int x){
	memset(dp, 0, sizeof dp);
	for(int i=0; i<n; ++i){
		for(int j=i-1; j>=0; --j){
			if(a[i].first <= a[j].first){
				continue;
			}
			if(a[j].second < a[i].second && a[i].second - a[j].second <= x){
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if(a[j].second > a[i].second && a[i].second + n - a[j].second <= x){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return *max_element(dp, dp + n) >= m;
}

inline void solution(){
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	int l = 1, r = n - 1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(ok(mid)){
			r = mid;
		}
		else{
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
