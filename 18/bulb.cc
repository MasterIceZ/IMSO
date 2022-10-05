/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Bulb
 * ALGO		: Dijkstra
 * DATE		: 1 Oct 2022
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
	int bit, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _bit, int _w): 
		bit(_bit), w(_w) {}
};

const int MxN = 1 << 20;
priority_queue<Node> pq;
int dist[MxN];

inline void solution(){
	int n, state, before = 0;
	cin >> n;
	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<n; ++i){
		cin >> state;
		if(state){
			before = before | (1 << i);
		}
	}
	pq.emplace(before, dist[before] = 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		int nxt_dist = now.w + 1;
		for(int i=0; i<n; ++i){
			int nxt_bit = now.bit;
			if(i != 0){
				nxt_bit = nxt_bit ^ (1 << (i - 1));
			}
			if(i != n - 1){
				nxt_bit = nxt_bit ^ (1 << (i + 1));
			}
			nxt_bit = nxt_bit ^ (1 << i);
			if(dist[nxt_bit] > nxt_dist){
				pq.emplace(nxt_bit, dist[nxt_bit] = nxt_dist);
			}
		}
	}
	cout << (dist[0] >= 1e9 + 100 ? -1: dist[0]);
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
