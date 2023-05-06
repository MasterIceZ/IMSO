/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Go sleep Na
 * ALGO		: Burnside's Lemma
 * DATE		: 12 Apr 2023
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

// https://en.wikipedia.org/wiki/Burnside%27s_lemma

const ll MOD = 1e9 + 7;

ll mop(ll a, ll b){
	if(b == 0ll){
		return 1ll;
	}
	if(b == 1ll){
		return a;
	}
	ll t = mop(a, b >> 1);
	ll r = (t * t) % MOD;
	if(b & 1){
		r = (r * a) % MOD;
	}
	return r;
}

ll inv_24 = mop(24ll, MOD - 2ll);

inline void solution(){
	ll a, b, _a, _b, _c, _d, _e;
	cin >> a >> b;	
	ll answer = 0ll, f = mop(b, a * a);
	if(a & 1){
		_a = mop(f, 6ll);
		_b = (6ll * f) % MOD;
		_b = (_b * mop(mop(b, (a * a - 1ll) / 4ll + 1ll), 2ll)) % MOD;
		_c = (3ll * mop(f, 2ll)) % MOD;
		_c = (_c * mop(mop(b, (a * a - 1ll) / 2ll + 1ll), 2ll)) % MOD;
		_d = (8ll * mop(f, 2ll)) % MOD;
		_e = (6ll * mop(f, 3ll)) % MOD;
	}
	else{
		_a = mop(f, 6ll);
		_b = (6ll * f) % MOD;
		_b = (_b * mop(b, a * a / 2ll)) % MOD;
		_c = (3ll * mop(f, 3ll)) % MOD;
		_d = (8ll * mop(f, 2ll)) % MOD;
		_e = (6ll * mop(f, 3ll)) % MOD;
	}
	answer = (_a + _b) % MOD;
	answer = (answer + _c) % MOD;
	answer = (answer + _d) % MOD;
	answer = (answer + _e) % MOD;
	cout << (answer * inv_24) % MOD;
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
