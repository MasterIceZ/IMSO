/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: pengin hen mhee
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

const int MxN = 1000010;
vector<int> adj[MxN], c;

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1, l, r; i<=m; ++i){
		cin >> l >> r;
		adj[l - 1].emplace_back(r);
		adj[r].emplace_back(l - 1);
		c.emplace_back(l); c.emplace_back(r);
	}
	c.emplace_back(0);
	c.emplace_back(n);
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	int N = c.size();
	vector<vector<int>> dist(N + 10, vector<int> (N + 10, 1e9 + 100));
	for(int i=1; i<=n; ++i){
		int ui = upper_bound(c.begin(), c.end(), i) - c.begin();
		for(auto x: adj[i]){
			int ux = upper_bound(c.begin(), c.end(), x) - c.begin();
			dist[ui][ux] = 1;
		}
	}
	for(int i=1; i<N; ++i){
		dist[i][i + 1] = min(dist[i][i + 1], abs(c[i] - c[i + 1]));
		dist[i + 1][i] = min(dist[i + 1][i], abs(c[i] - c[i + 1]));
	}
	for(int k=1; k<=N; ++k){
		for(int i=1; i<=N; ++i){
			for(int j=1; j<=N; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	dbg(c);
	cout << dist[1][N];
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
