/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sonya and Problem Wihtout a Legend
 * ALGO		: 
 * DATE		: 5 May 2023
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
ll a[MxN];

struct slope_trick{
	multiset<ll> ms;
	ll min_y = 0;
	inline void add_line(ll value, int idx){
		if(ms.empty()){
			ms.emplace(value);
		}
		else{
			ms.emplace(value);
			ms.emplace(value);
			min_y += *ms.rbegin() - value;
			while(!ms.empty() && (int) ms.size() > idx){
				ms.erase(--ms.end());
			}
		}
	}
} dp;

// ms stores data structure for f[i](x) and g[i](x) when update i-th line

// f[i](x) = minimum cost to make A[i] = x and A[j] <= A[j + 1] when j < i
// g[i](x) = minimum cost to make A[i] <= x and A[j] <= A[j + 1] when j < i
// f[i](x) = |A[i] - x| + min(f[i - 1](k)) ; k <= x
// g[i](x) = min(f[i - 1](k)) ; k <= x
// f[i](x) = |A[i] - x| + g[i](x)

// in graph
// when slope of f[i](x) = +1
// g[i](x) will be flat since it use most left that optimal

// so that g[i](x) will stores exactly i elements

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] -= i;
	}
	for(int i=1; i<=n; ++i){
		dp.add_line(a[i], i);
	}
	cout << dp.min_y;
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
