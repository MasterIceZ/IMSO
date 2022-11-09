/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Convex Hull
 * ALGO		: Graham's Scan
 * DATE		: 28 Oct 2022
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

using pt = pair<double, double>;

int orientation(pt a, pt b, pt c){
	double v = a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
	if(v < 0){
		return -1;
	}
	if(v < 0){
		return 1;
	}
	return 0;
}

bool cw(pt a, pt b, pt c){
	int o = orientation(a, b, c);
	return o < 0;
}

vector<pt> graham_scan(vector<pt> a){
	pt p0 = *min_element(a.begin(), a.end(), [] (pt a, pt b) {
		return make_pair(a.second, a.first) < make_pair(b.second, b.first);
	});
	sort(a.begin(), a.end(), [&p0] (const pt& a, const pt& b) {
		int o = orientation(p0, a, b);
		if(o == 0){
			return (p0.first - a.first) * (p0.first - a.first) + (p0.second - a.second) * (p0.second - a.second) < (p0.first - b.first) * (p0.first - b.first) + (p0.second - b.second) * (p0.second - b.second);
		}
		return o < 0;
	});
	vector<pt> st;
	for(int i=0; i<(int) a.size(); ++i){
		while(st.size() > 1 && !cw(st[st.size() - 2], st.back(), a[i])){
			st.pop_back();
		}
		st.emplace_back(a[i]);
	}
	return st;
}

inline void solution(){
	int n;
	cin >> n;
	if(n == 0){
		exit(0);
	}
	vector<pt> points;
	double x, y;
	for(int i=1; i<=n; ++i){
		cin >> x >> y;
		points.emplace_back(x, y);
	}
	vector<pt> convex_hull = graham_scan(points);
	sort(convex_hull.begin(), convex_hull.end());
	convex_hull.resize(unique(convex_hull.begin(), convex_hull.end()) - convex_hull.begin());
	cout << convex_hull.size() << "\n";
	for(auto x: convex_hull){
		cout << (int) x.first << " " << (int) x.second << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q){
		solution();
//		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
