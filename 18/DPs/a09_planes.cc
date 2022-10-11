/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: a09_airplanes 
 * ALGO		: Dynamic Programming
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

const int MxN = 330;
int dp[MxN << 1][MxN << 1], v[MxN << 1][MxN << 1];
pair<int, int> a[MxN];

int DP(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l + 1 == r){
		return dp[l][r] = v[l][r];
	}
	int res = -1;
	for(int k=l+1; k<r; ++k){
		res = max(res, DP(l, k) + DP(k, r));
	}
	return dp[l][r] = res + v[l][r];
}

inline void solution(){
	memset(dp, -1, sizeof dp);
	memset(v, 0, sizeof v);
	int n;
	cin >> n;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
		c.emplace_back(a[i].first);
		c.emplace_back(a[i].second);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		int stp = upper_bound(c.begin(), c.end(), a[i].first) - c.begin();
		int edp = upper_bound(c.begin(), c.end(), a[i].second) - c.begin();
		v[stp][edp] = 1;
	}
	int maxx = c.size();
	cout << DP(1, maxx);
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
