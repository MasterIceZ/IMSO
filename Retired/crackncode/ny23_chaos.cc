/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Chaos
 * ALGO		: 
 * DATE		: 31 Dec 2022
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

const int MxN = 200020;
pair<int, int> edge[MxN];
int parent[MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		c[u][v] += 1; c[v][u] += 1;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
	}
//	for(int i=1; i<=m; ++i){
//		cin >> edge[i].first >> edge[i].second;
//		assert(edge[i].first >= 1 && edge[i].second >= 1);
//		assert(edge[i].first <= n && edge[i].second <= n);
//	}
//	stack<int> qry, answers;
//	for(int i=1, x; i<=m; ++i){
//		cin >> x;
//		qry.emplace(x);
//	}
//	for(int i=1; i<=n; ++i){
//		parent[i] = i;
//	}
//	int comp = n;
//	while(!qry.empty()){
//		int now = qry.top(); qry.pop();
//		int ru = find_root(edge[now].first);
//		int rv = find_root(edge[now].second);
//		answers.emplace(comp);
//		if(ru != rv){
//			parent[ru] = rv;
//			comp -= 1;
//		}
//	}
//	while(!answers.empty()){
//		cout << answers.top() << "\n";
//		answers.pop();
//	}
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
