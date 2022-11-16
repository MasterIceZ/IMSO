/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: newyearlights
 * ALGO		: Topological Sort
 * DATE		: 12 Nov 2022
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
int deg[MxN];
vector<pair<int, int>> adj[MxN];
vector<int> tt;
bitset<MxN> visited;

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1, x, t; i<=m; ++i){
		cin >> t;
		deg[i] = t;
		tt.resize(t);
		for(auto &x: tt){
			cin >> x;
		}
		cin >> x;
		for(auto a: tt){
			adj[a].emplace_back(x, i);
		}
	}
	queue<int> q;
	q.emplace(1);
	visited[1] = true;
	while(!q.empty()){
		dbg(q);
		int now = q.front(); q.pop();
		for(auto x: adj[now]){
			if(--deg[x.second] == 0 && !visited[x.first]){
				q.emplace(x.first);
				visited[x.first] = true;
			}
		}
	}
	cout << visited.count();
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
