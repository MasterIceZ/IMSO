/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Deilvery Boxes
 * ALGO		: Search by Elimination
 * DATE		: 11 Oct 2022
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
int a[MxN], b[MxN], c[MxN];
int n, k, it;

inline bool ok(int mid){
	int sum = 0, cnt = 1;
	for(int i=1; i<=n; ++i){
		sum = sum + a[i];
		if(sum > mid || c[b[i]] == it){
			it++;
			cnt++;
			sum = a[i];
		}
		c[b[i]] = it;
	}
	return cnt <= k;
}

inline void solution(){
	memset(c, 0, sizeof c);
	cin >> n >> k;
	bool able = true;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
		c[b[i]]++;
		if(c[i] > k){
			able = false;
		}
	}	
	if(!able){
		cout << "-1";
		return ;
	}
	int l = *max_element(a + 1, a + n + 1);
	int r = 1 + accumulate(a + 1, a + n + 1, 0);
	memset(c, 0, sizeof c);
	while(l < r){
		int mid = (l + r) >> 1;
		++it;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << (l > accumulate(a + 1, a + n + 1, 0) ? -1: l);
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
