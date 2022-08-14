/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Reunion
 * ALGO		: Implementation
 * DATE		: 9 Aug 2022
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

struct Circle{
	double x, y, r;
	Circle(): x(0), y(0), r(0) {}
};

const int MxM = 110;
pair<double, double> v[MxM];
double x, y, r;

double dist(pair<double, double> a, pair<double, double> b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

inline void solution(){
	int m, n, answer = 0;
	cin >> m >> n;
	for(int i=1; i<=m; ++i){
		cin >> v[i].first >> v[i].second;
	}
	for(int i=1; i<=n; ++i){
		cin >> x >> y >> r;
		int cnt = 0;
		for(int j=1; j<=m; ++j){
			cnt += (dist(v[j], make_pair(x, y)) < r * r);
		}
		answer += (cnt > 0 && cnt < m);
	}
	cout << answer;
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
