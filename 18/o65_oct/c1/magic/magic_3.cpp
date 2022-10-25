#include "magic.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _v, int _w):
		v(_v), w(_w) {}
};

const int MxN = 200020;
vector<pair<int, int>> edge;
vector<int> adj[MxN];
map<pair<int, int>, int> mat;
priority_queue<Node> pq;
int dist[MxN];

int bfs(int u){
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(u, dist[u] = 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + mat[{x, now.v}];
			if(dist[x] > nxt){
				pq.emplace(x, dist[x] = nxt);
			}
		}
	}
	return dist[0];
}

vector<int> magic(int N, int M, int Q, vector<int> U, vector<int> V, vector<vector<int>> q){
	if(N > 3000){
		return {};
	}
	edge.resize(M);
	for(int i=0; i<M; ++i){
		adj[U[i]].emplace_back(V[i]);
		adj[V[i]].emplace_back(U[i]);
		edge[i] = make_pair(U[i], V[i]);
	}
	vector<int> res;
	for(auto query: q){
		if(query[0] == 0){
			int a = edge[query[1]].first;
			int b = edge[query[1]].second;
			mat[{a, b}] = mat[{b, a}] = 1;
			res.emplace_back(-1);
		}
		else{
			int r = bfs(query[1]);
			res.emplace_back(r <= query[2]);
		}
	}
	assert((int) res.size() == Q);
	return res;
}
