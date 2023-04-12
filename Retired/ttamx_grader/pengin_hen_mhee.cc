/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 1000010;
vector<int> adj[MxN];
queue<pair<int, int>> q;
int dist[MxN];

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u - 1].emplace_back(v);
		adj[v].emplace_back(u - 1);
	}
	for(int i=1; i<=n; ++i){
		adj[i].emplace_back(i - 1);
		adj[i - 1].emplace_back(i);
	}
	memset(dist, -1, sizeof dist);
	q.emplace(0, dist[0] = 0);
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		if(now.first == n){
			cout << dist[n];
			return ;
		}
		for(auto x: adj[now.first]){
			int nxt = dist[now.first] + 1;
			if(dist[x] == -1){
				q.emplace(x, dist[x] = nxt);
			}
		}
	}
	cout << dist[n];
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
