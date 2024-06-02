#include <bits/stdc++.h>
#include "lightcolors.h"

using namespace std;

const int MxN = 100010;

int n, color[MxN], deg[MxN];
vector<int> adj[MxN];
queue<int> q;
bitset<MxN> visited;

bool dfs_bipartite(int u, int p, int c) {
	if(color[u] != 0) {
		return (color[u] == c);
	}
	color[u] = c;
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		if(dfs_bipartite(x, u, 3 - c) == false) {
			return false;
		}
	}
	return true;
}

vector<int> make_answer(int *color) {
	vector<int> res;
	for(int i=1; i<=n; ++i) {
		res.emplace_back(color[i]);
	}
	return res;
}

std::vector<int> lightcolors(int N, int M, std::vector<int> A, std::vector<int> B) {
	n = N;
	for(int i=0; i<=M-1; ++i) {
		int u = A[i] + 1, v = B[i] + 1;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);

		deg[u]++, deg[v]++;
	}
	
	if(dfs_bipartite(1, 0, 1)) {
		return make_answer(color);
	}

	for(int i=1; i<=N; ++i) {
		if(deg[i] <= 2) {
			q.emplace(i);
			visited[i] = true;
		}
	}
	vector<int> topo_order;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		topo_order.emplace_back(now);
		for(auto x: adj[now]) {
			if(!visited[x] && --deg[x] <= 2) {
				q.emplace(x);
				visited[x] = true;
			}
		}
	}
	memset(color, 0, sizeof color);
	for(auto u: topo_order) {
		bitset<4> blocked;
		for(auto x: adj[u]) {
			blocked[color[x]] = true;
		}
		if(blocked[1] == false) {
			color[u] = 1;
		}
		else if(blocked[2] == false) {
			color[u] = 2;
		}
		else {
			color[u] = 3;
		}
	}

	return make_answer(color);
}
