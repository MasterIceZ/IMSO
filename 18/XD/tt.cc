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

struct Point{
	double x, y;

	// constructor
	Point(double _x=-1, double _y=-1){
		x = _x;
		y = _y;
	}
};

pair<double, double> x;

inline void solution(){
//	vector<Point> v;
//	v.emplace_back(0, -1);
//	Point a;
//	cout << a.x;
//	for(auto x: v){
//		cout << "(" << x.x << ", " << x.y << ")\n";
//	}
	vector<pair<double, double>> v;
	v.emplace_back(0, -1);
	for(auto x: v){
		cout << "(" << x.first << ", " << x.second << ")\n";
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
