/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c2_dslope
 * ALGO		: 
 * DATE		: 11 Mar 2023
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

const int MxN = 80080;
const int MxK = 44;
const ll MOD = 1e9 - 1ll;

struct fenwick_tree{
	ll t[MxN];
	void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			t[idx] = (t[idx] + v) % MOD;
		}
	}
	ll query(int idx){
		ll r = 0ll;
		for(; idx>0; idx-=idx&-idx){
			r = (r + t[idx]) % MOD;
		}
		return r;
	}
} dp[MxK];
int a[MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		dp[1].update(a[i], 1);
		for(int state=2; state<=k; ++state){
			ll upd = (dp[state - 1].query(n) - dp[state - 1].query(a[i]) + MOD) % MOD;
			dp[k].update(a[i], upd);
		}
	}
	cout << dp[k].query(n);
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
