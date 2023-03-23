#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct State{
	int v;
	ll w;
	int k;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, ll _w, int _k=0):
		v(_v), w(_w), k(_k) {}
};

const int MxN = 50050;
const int MxK = 22;
vector<State> adj[MxN];
ll val[MxN], dist[MxK][MxN];
priority_queue<State> pq;

long long minimum_energy(int N, int M, int K, std::vector<int> A, std::vector<int> L, 
                         std::vector<int> R, std::vector<int> C){
	for(int i=1; i<=N; ++i){
		val[i] = A[i - 1];
		adj[i].emplace_back(i - 1, val[i]);
		adj[i - 1].emplace_back(i, val[i]);

		adj[i].emplace_back(i - 1, 0, 1);
		adj[i - 1].emplace_back(i, 0, 1);
	}
	for(int i=1; i<=N; ++i){
		for(int j=i+1; j<N; ++j){
			ll d = abs(val[i] * val[i] - val[j] * val[j]);
			adj[i].emplace_back(j + 1, d);
			adj[j + 1].emplace_back(i, d);
		}
	}
	for(int i=1; i<=M; ++i){
		adj[L[i - 1]].emplace_back(R[i - 1] + 1, (ll) C[i - 1]);
		adj[R[i - 1] + 1].emplace_back(L[i - 1], (ll) C[i - 1]);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(0, 0, dist[0][0] = 0ll);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		cerr << "D : " << now.v << " " << now.k << "\n";
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.w;
			ll nxt_state = now.k + x.k;
			if(nxt_state <= K && dist[nxt_state][x.v] > nxt){
				pq.emplace(x.v, dist[nxt_state][x.v] = nxt, nxt_state);
			}
		}
	}
	ll res = (ll) 1e18;
	for(int i=0; i<=K; ++i){
		res = min(res, dist[i][N]);
	}
	return res;
}
