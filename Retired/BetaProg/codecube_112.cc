/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Golden Rectangle
 * ALGO		: Implementation
 * DATE		: 19 Nov 2022
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

inline void solution(){
	vector<vector<int>> v = {{1}};
	int n;
	cin >> n;
	for(int i=2; i<=n; ++i){
		if(i % 4 == 2){
			int l = v.size();
			for(int j=1; j<=l; ++j){
				for(auto &x: v){
					x.emplace_back(i);
				}
			}
		}
		else if(i % 4 == 3){
			int l = v[0].size();
			vector<int> t(l, i);
			for(int j=1; j<=l; ++j){
				v.emplace_back(t);
			}
		}
		else if(i % 4 == 0){
			int l = v.size();
			vector<int> t(l, i);
			for(int j=0; j<l; ++j){
				vector<int> tt = v[j];
				v[j] = t;
				for(auto x: tt){
					v[j].emplace_back(x);
				}
			}
		}
		else{
			int l = v[0].size();
			vector<vector<int>> r, t;
			vector<int> tt(l, i);
			for(int j=1; j<=l; ++j){
				r.emplace_back(tt);
			}
			t = r;
			for(auto x: v){
				t.emplace_back(x);
			}
			v = t;
		}
	}
	for(auto x: v){
		for(auto y: x){
			cout << (char) (y + 'A' - 1);
		}
		cout << "\n";
	}
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
