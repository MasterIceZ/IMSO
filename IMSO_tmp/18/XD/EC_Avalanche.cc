/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Avalanche
 * ALGO		: Dijkstra
 * DATE		: 11 Jul 2022
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

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const pair<int, int> dir[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int MxN = 2e6 + 10;

map<pair<int, int>, int> pos;
unordered_map<int, pair<int, int>> num;
priority_queue<Node> pq;
vector<int> adj[MxN];
int dist[MxN];

pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b){
	return make_pair(a.first + b.first, a.second + b.second);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	pair<int, int> now = make_pair(0, 0);
	int state = 3;
	for(int i=1; i<=2 * n; ++i){
		pos[now] = i;
		num[i] = now;
		pair<int, int> nxt_state = now + dir[(state + 1) % 4];
		if(pos[nxt_state] == 0){
			now = nxt_state;
			state = (state + 1) % 4;
		}
		else{
			now = now + dir[state];
		}
	}
	for(int i=1, x; i<=m; ++i){
		cin >> x;
		for(int k=0; k<4; ++k){
			int v = pos[num[x] + dir[k]];
			adj[x].emplace_back(v);
			adj[v].emplace_back(x);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, 0);
	dist[1] = 0;
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		if(now.v - 1 > 0 && dist[now.v - 1] > now.w + 1){
			pq.emplace(now.v - 1, dist[now.v - 1] = now.w + 1);
		}
		if(dist[now.v + 1] > now.w + 1){
			pq.emplace(now.v + 1, dist[now.v + 1] = now.w + 1);
		}
		for(auto x: adj[now.v]){
			if(dist[x] > now.w + 1){
				pq.emplace(x, dist[x] = now.w + 1);
			}
		}
	}
	dbg(dist[1], dist[4], dist[15], dist[14], dist[13], dist[30], dist[31]);
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
