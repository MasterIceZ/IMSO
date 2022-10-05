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

const int MxN = 50050;
vector<int> adj[MxN];
bool is_u[MxN], is_v[MxN];
string u[MxN], v[MxN];
map<string, string> mp;

inline bool check(string s){
	return ('0' <= s[0] && s[0] <= '9');
}

inline void solution(){
	int n, it = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> u[i];
		is_u[i] = check(u[i]);
	}
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		is_v[i] = check(v[i]);
	}
	vector<string> compress;
	for(int i=1; i<=n; ++i){
		if(is_u[i] && is_v[i] && u[i] != v[i]){
			cout << "NE";
			return ;
		}
		if(!is_u[i]){
			compress.emplace_back(u[i]);
		}
		if(!is_v[i]){
			compress.emplace_back(v[i]);
		}
	}
	sort(compress.begin(), compress.end());
	compress.resize(unqiue(compress.begin(), compress.end()) - compress.begin());
	auto get_idx = [&](const string s){
		return upper_bound(compress.begin(), compress.end()) - compress.begin();
	};
	for(int i=1; i<=n; ++i){
		if(is_u[i] && is_v[i]){
			continue;
		}
		
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
