/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fixed Prefix Permutations
 * ALGO		:
 * DATE		: 24 Feb 2023
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

const int MxN = 50050;
const int MxM = 11;
int answer, a[MxN][MxM], pos[MxM];
string s;
map<string, int> c[MxM];

inline void solution(){
	int n, m;
	cin >> n >> m;	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			pos[a[i][j]] = j;
		}
		s = "";
		for(int j=1; j<=m; ++j){
			s += to_string(pos[j]);
			c[j][s]++;
		}
	}
	for(int i=1; i<=n; ++i){
		s = "";
		answer = m;
		for(int j=1; j<=m; ++j){
			s += to_string(a[i][j]);
			if(c[j][s]){
				continue;
			}
			answer = j - 1;
			break;
		}
		cout << answer << " ";
	}
	for(int i=0; i<MxM; ++i){
		c[i].clear();
	}
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
