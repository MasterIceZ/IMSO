/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BIG TREE
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

map<vector<pair<int, int>>, int> trees;
vector<pair<int, int>> edges;

vector<pair<int, int>> input_graph(){
	int n;
	edges.clear();
	cin >> n;
	edges.resize(n - 1);
	for(auto &x: edges){
		cin >> x.first >> x.second;
	}
	sort(edges.begin(), edges.end());
	return edges;
}

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		trees[input_graph()]++;
	}
	for(int i=1; i<=q; ++i){
		cout << trees[input_graph()] << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
