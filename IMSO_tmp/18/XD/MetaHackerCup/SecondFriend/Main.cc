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

const int MxN = 110;
char a[MxN][MxN], b[MxN][MxN];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solution(){
	int n, m;
	cin >> n >> m;
	bool have = false;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];	
			have |= (a[i][j] == '^');
		}
	}
	if(!have){
		cout << "Possible\n";
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
	else{
		memset(b, 0, sizeof b);
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				b[i][j] = '^';
			}
		}
		bool ok = true;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				int cnt = 0;
				for(int state=0; state<4; ++state){
					int ii = di[state] + i, jj = dj[state] + j;
					cnt += (b[ii][jj] == '^');
				}
				ok &= (cnt >= 2);
			}
		}
		if(ok){
			cout << "Possible\n";
			for(int i=1; i<=n; ++i){
				for(int j=1; j<=m; ++j){
					cout << "^";
				}
				cout << "\n";
			}
		}
		else{
			cout << "Impossible\n";
		}
	}
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
