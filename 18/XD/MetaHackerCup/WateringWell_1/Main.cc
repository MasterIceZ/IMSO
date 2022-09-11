/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const ll MOD = 1e9 + 7;
const int MxN = 500050;
ll qsx[3][MxN], qsy[3][MxN], x[MxN], y[MxN];

inline void solution(){
	memset(qsx, 0ll, sizeof qsx); memset(qsy, 0ll, sizeof qsy);
	ll n, q;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x[i] >> y[i];
		qsx[1][i] = (qsx[1][i - 1] + x[i]) % MOD;
		qsx[2][i] = (qsx[2][i - 1] + (x[i] * x[i]) % MOD) % MOD;
		qsy[1][i] = (qsy[1][i - 1] + y[i]) % MOD;
		qsy[2][i] = (qsy[2][i - 1] + (y[i] * y[i]) % MOD) % MOD;
	}
	cin >> q;
	ll res = 0ll, x, y, x_2, y_2, to_add;
	for(int i=1; i<=q; ++i){
		cin >> x >> y;
		x_2 = (((x * x) % MOD) * n) % MOD;
		to_add = ((qsx[2][n] - ((2 * (qsx[1][n] * x)) % MOD) + x_2) % MOD + MOD) % MOD;
		res = (res + to_add) % MOD;	
		y_2 = (((y * y) % MOD) * n) % MOD;
		to_add = ((qsy[2][n] - ((2 * (qsy[1][n] * y)) % MOD) + y_2) % MOD + MOD) % MOD;
		res = (res + to_add) % MOD;

	}
	cout << res;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	freopen("output.txt", "w", stdout);
	int q = 1;
	cin >> q;
	for(int tt=1; tt<=q; ++tt){
		cout << "Case #" << tt << ": ";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
