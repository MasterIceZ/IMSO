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
using pdd = pair<double, double>;

pdd a[5];

double cross(pdd a, pdd b, pdd c){
	double x_1 = (b.first - a.first);
	double y_1 = (b.second - a.second);
	double x_2 = (c.first - a.first);
	double y_2 = (c.second - a.second);
	return (x_1 * y_2 - y_1 * x_2);
}

bool check(){
	double last = 0;
	for(int i=0; i<4; ++i){
		double now = cross(a[i], a[(i + 1) % 4], a[(i + 2) % 4]);
		if(now != 0){
			if(last * now < 0){
				return false;
			}
			else{
				last = now;
			}
		}
	}
	return true;
}

inline void solution(){
	for(int i=0; i<4; ++i){
		cin >> a[i].first >> a[i].second;
	}
	bool ok = check();
	cout << (ok ? "Yes": "No");
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
