/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Trip planner
 * ALGO		:
 * DATE		: 15 Mar 2023
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

struct State{
	int v, w, fuel;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, int _w, int _fuel):
		v(_v), w(_w), fuel(_fuel) {}
};

const int MxN = 1010;
const int MxP = 110;

vector<pair<int, int>> adj[MxN];
int p[MxN], dist[MxP][MxN];
priority_queue<State> pq;

inline void solution(){
	int n, m, u, v, w, q;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> p[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> u >> v >> w;
		u++, v++;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	cin >> q;
	while(q--){
		int c, s, e;
		cin >> c >> s >> e;
		s++, e++;
		memset(dist, 0x3f, sizeof dist);
		pq.emplace(s, dist[0][s] = 0, 0);
		while(!pq.empty()){
			State now = pq.top(); pq.pop();
			if(now.v == e){
				break;
			}
			int nxt = now.w + p[now.v];
			if(now.fuel + 1 <= c && dist[now.fuel + 1][now.v] > nxt){
				pq.emplace(now.v, dist[now.fuel + 1][now.v] = nxt, now.fuel + 1);
			}
			for(auto x: adj[now.v]){
				nxt = now.w;
				if(now.fuel - x.second >= 0 && dist[now.fuel - x.second][x.first] > nxt){
					pq.emplace(x.first, dist[now.fuel - x.second][x.first] = nxt, now.fuel - x.second);
				}
			}
		}
		int answer = 1e9 + 100;
		for(int i=0; i<=c; ++i){
			answer = min(answer, dist[i][e]);
		}
		cout << (answer >= 1e9 + 100 ? "impossible": to_string(answer)) << "\n";
		while(!pq.empty()){
			pq.pop();
		}
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
