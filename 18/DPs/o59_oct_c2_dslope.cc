/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Downward Slope
 * ALGO		: Fenwick Tree, Dynamic Programming
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

const ll MOD = 1e9 - 1;
const int MxN = 80080;
const int MxK = 44;
int n, k, a[MxN];

struct fenwick_tree{
	ll tree[MxN];
	void update(int idx, ll v){
		for(; idx<=n; idx+=idx&-idx){
			tree[idx] = (tree[idx] + v) % MOD;
		}
	}
	ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res = (res + tree[idx]) % MOD;
		}
		return res;
	}
} fw[MxK];

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		fw[1].update(a[i], 1);
		for(int state=2; state<=k; ++state){
			ll last_value = (((fw[state - 1].read(n) - fw[state - 1].read(a[i])) % MOD) + MOD) % MOD;
			fw[state].update(a[i], last_value);
		}
	}
	cout << fw[k].read(n);
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
