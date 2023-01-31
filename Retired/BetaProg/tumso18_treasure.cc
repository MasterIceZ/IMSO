/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso18_treasure
 * ALGO		: Matrix Expo
 * DATE		: 4 Jan 2022
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

const ll MOD = 98765431;
const int LG = 65;

struct matrix_t{
	ll **a;
	unsigned int n;
	matrix_t(int sz): n(sz){
		a = (ll **) calloc(n + 1, sizeof(ll *));
		for(int i=1; i<=n; ++i){
			a[i] = (ll *) calloc(n + 1, sizeof (ll));
		}
	}
};

matrix_t operator * (const matrix_t A, const matrix_t B){
	matrix_t response;
	ll tmp;
	for(int i=1; i<=A.n; ++i){
		for(int j=1; j<=B.n; ++j){
			for(int k=1; k<A.n; ++k){
				tmp = (A.a[i][k] * B.a[k][j]) % MOD;
				response.a[i][j] = (response.a[i][j] + tmp) % MOD;
			}
		}
	}
	return response;
}

inline void solution(){
	
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
