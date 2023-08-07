/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Rudolf and CodeVid-23
 * ALGO		: Dijkstra
 * DATE		: 2 Aug 2023
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

struct state_t {
	int v, w;
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
	state_t(int _v, int _w):
		v(_v), w(_w) {}
};

const int MxM = 1010;
const int MxN = 1 << 11;

int n, m, cost[MxM], cure[MxM], symptom[MxM], dist[MxN];
string s;
vector<pair<int, int>> adj[MxN];
priority_queue<state_t> pq;

inline int processString() {
	cin >> s;
	int res = 0;
	for(auto x: s) {
		res <<= 1;
		res += (x - '0');
	}
	return res;
}

inline void solution(){
	cin >> n >> m;
	int start = processString();
	for(int i=1; i<=m; ++i) {
		cin >> cost[i];
		cure[i] = ~processString();
		symptom[i] = processString();
	}
	int max_state = (1 << n);
	for(int u=0; u<max_state; ++u) {
		for(int i=1; i<=m; ++i) {
			int v = (u & cure[i]) | symptom[i];
			adj[u].emplace_back(v, cost[i]);
		}
		dist[u] = 1e9 + 100;
	}
	pq.emplace(start, dist[start] = 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now.v]) {
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	cout << ((dist[0] >= 1e9 + 100) ? -1: dist[0]);
	for(int i=0; i<max_state; ++i) {
		adj[i].clear();
	}
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
