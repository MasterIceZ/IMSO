/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Eerie
 * ALGO		: Floyd Warshall 
 * DATE		: 22 Feb 2023
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

struct Edges{
	int u, v, w;
	Edges(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

const int MxN = 220;
int dist[MxN][MxN];
vector<Edges> edges;

inline void solution(){
	int n, m, u, v, w;
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	edges.clear();
	for(int i=1; i<=n; ++i){
		dist[i][i] = 0;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[v][u], w);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	bool ok;
	for(int i=1; i<n; ++i){
		for(int j=i+1; j<=n; ++j){
			ok = true;
			for(auto x: edges){
				int stp = x.u, edp = x.v;
				if(min({dist[stp][edp], dist[stp][i] + dist[j][edp], dist[stp][j] + dist[i][edp]}) != x.w){
					ok = false;
					break;		
				}
			}
			if(ok){
				cout << i << " " << j << "\n";
				break;
			}
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
