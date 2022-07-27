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

inline void solution(){
	vector<set<string>> v(10);
	vector<string> vs;
	string s;
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> s;
		vs.emplace_back(s);
		v[s.size()].emplace(s);
	}
	for(auto x: vs){
		bool ok = false;
		string t = "";
		for(int j=0; j<x.size()-1; ++j){
			t = t + x[j];
//			dbg(t, x.substr(j + 1, x.size() - j), v[j + 1].count(t), v[x.size() - j - 1].count(x.substr(j + 1, x.size() - j)));
			if(v[j + 1].count(t) && v[x.size() - j - 1].count(x.substr(j + 1, x.size() - j))){
				ok = true;
				break;
			}
		}
		cout << ok;
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
