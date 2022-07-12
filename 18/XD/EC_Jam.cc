/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Jam
 * ALGO		: Brute Force, Adhoc
 * DATE		: 11 Jul 2022
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

const int MxN = 1010;
char a[MxN][MxN];
int l[MxN], r[MxN];

inline void solution(){
	int n, m, pos = -1;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		l[i] = m + 1, r[i] = 0;
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				if(pos == -1){
					pos = i;
				}
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}
		}
	}
	l[n] = 1;
	r[n] = max(1, r[n]);
	l[pos - 1] = l[pos];
	r[pos - 1] = r[pos];
	for(int i=pos+1; i<=n; ++i){
		if(l[i] == m + 1){
			l[i] = l[i - 1];
		}
		if(r[i] == 0){
			r[i] = r[i - 1];
		}
	}
	int cnt = n - pos, now = 1;
	for(int i=n; i>=pos; --i){
		if((i & 1) ^ (n & 1)){
			// go left
			cnt += now - min(l[i], l[i - 1]);
			now = min(l[i], l[i - 1]);
		}
		else{
			// go right
			cnt += max(r[i], r[i - 1]) - now;
			now = max(r[i], r[i - 1]);
		}
	}
	cout << cnt;
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
