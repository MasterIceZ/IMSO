/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Graph Path II 
 * ALGO		: Floyd Warshall
 * DATE		: 11 Apr 2023
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

const int MxN = 110;

int n, m, k;

struct Matrix{
	ll mtx[MxN][MxN];
	inline void init(){
		for(int i=0; i<MxN; ++i){
			for(int j=0; j<MxN; ++j){
				mtx[i][j] = 1e18 + 100;
			}
		}
		for(int i=0; i<MxN; ++i){
			mtx[i][i] = 0ll;
		}
	}
};

Matrix operator * (const Matrix A, const Matrix B){
	Matrix C;
	C.init();
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			for(int k=1; k<=n; ++k){
				if(A.mtx[i][k] >= 1e18 + 100 || B.mtx[k][j] >= 1e18 + 100){
					continue;
				}
				C.mtx[i][j] = min(C.mtx[i][j], A.mtx[i][k] + B.mtx[k][j]);
			}
		}
	}
	return C;
}

Matrix answer, lift[33];
ll w;

inline void solution(){
	cin >> n >> m >> k;
	lift[0].init();
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		lift[0].mtx[u][v] = min(lift[0].mtx[u][v], w);
	}
	answer.init();
	for(int i=1; i<=30; ++i){
		lift[i] = lift[i - 1] * lift[i - 1];
	}
	for(int i=30; i>=0; --i){
		if(k & (1 << i)){
			answer = answer * lift[i];
		}
	}
	cout << (answer.mtx[1][n] >= 1e18 + 100 ? -1: answer.mtx[1][n]);
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
