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
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> a(n + 1);
	bool same = true;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == 1){
			have_1 = true;
		}
		if(i != 1){
			same &= (a[i] == a[i - 1]);
		}
		pq.emplace(a[i]);
	}
	if(same){
		cout << 0;
		return ;
	}
	if(have_1){
		cout << -1;
	}
	bool ok = [&](vector<int> k){
		for(int i=2; i<=n; ++i){
			if(k[i] != k[i - 1]){
				return false;
			}	
		}
	};
	while(!pq.empty()){
		
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
