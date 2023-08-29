#include "crocodile.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct state_t {
	int v;
	ll w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, ll _w):
		v(_v), w(_w) {}
};

vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;
ll dist[MxN][2]; // [0] = best, [1] = secondary
bitset<MxN> visited;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
	for(int i=0; i<M; ++i) {
		adj[R[i][0]].emplace_back(R[i][1], L[i]);
		adj[R[i][1]].emplace_back(R[i][0], L[i]);
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<K; ++i) {
		pq.emplace(P[i], dist[P[i]][0] = 0ll);
	}
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		if(visited[now.v]) {
			continue;
		}
		visited[now.v] = true;
		for(auto x: adj[now.v]) {
			ll nxt = now.w + x.second;
			if(dist[x.first][1] > nxt) {
				dist[x.first][1] = nxt;
				if(dist[x.first][1] < dist[x.first][0]) {
					swap(dist[x.first][1], dist[x.first][0]);
				}
				if(dist[x.first][1] <= 1e9 + 100) {
					pq.emplace(x.first, dist[x.first][1]);
				}
			}
		}
	}
	return dist[0][1];
}
