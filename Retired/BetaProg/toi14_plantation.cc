/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PLANTATION
 * ALGO		: Divide and Conquer
 * DATE		: 1 Feb 2023
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

const int MxN = 100010;
pair<double, double> a[MxN];

double dist(pair<double, double> a, pair<double, double> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double divide(int l, int r){
	if(r - l + 1 <= 3){
		double res = 2e10;
		for(int i=l; i<=r; ++i){
			for(int j=i+1; j<=r; ++j){
				res = min(res, dist(a[i], a[j]));
			}
		}
		return res;
	}
	int mid = (l + r) >> 1;
	double res = min(divide(l, mid), divide(mid + 1, r));
	vector<pair<double, double>> strip;
	for(int i=l; i<=r; ++i){
		if(abs(a[i].first - a[mid].first) >= res){
			continue;
		}
		strip.emplace_back(a[i]);
	}
	sort(strip.begin(), strip.end(), 
		[] (pair<double, double> a, pair<double, double> b){
			if(a.second != b.second){
				return a.second < b.second;
			}
			return a.first < b.first;
		}
	);
	for(int i=0; i<(int) strip.size(); ++i){
		for(int j=i+1; j<(int) strip.size() && strip[j].second - strip[i].second < res; ++j){
			res = min(res, dist(strip[i], strip[j]));
		}
	}
	return res;
}

inline void solution(){
	int n;
	double r, d;
	cin >> n >> r >> d;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}	
	sort(a + 1, a + n + 1);
	cout << ((divide(1, n) >= 2 * r + d) ? "Y": "N");
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
