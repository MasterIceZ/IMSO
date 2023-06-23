#include <bits/stdc++.h>
#include "updown.h"

using namespace std;

const int MxN = 1000010;

vector<int> adj[MxN << 1];
bitset<MxN << 1> visited;
int sz[MxN << 1], root[MxN << 1];
map<pair<int, int>, int> overlap;

void dfs(int u, int current_root) {
	visited[u] = true;
	sz[u] = 1;
	root[u] = current_root;
	for(auto v: adj[u]) {
		if(visited[v]) {
			continue;
		}
		dfs(v, current_root);
		sz[u] += sz[v];
	}
}

std::vector<int> updown(int N, int M, std::vector<int> U, std::vector<int> V) {
	for(int i=0; i<=M-1; ++i) {
		int u = min(U[i], V[i]) + N;
		int v = max(U[i], V[i]);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i=0; i<=2*N-1; ++i) {
		if(visited[i]) {
			continue;
		}
		dfs(i, i);
	}
	for(int i=0; i<N; ++i) {
		int u = root[i], v = root[i + N];
		if(u == v) {
			sz[u]--;
		}
		else{
			int U = min(u, v);
			int V = max(u, v);
			overlap[{U, V}]++;
		}
	}
	vector<int> answer(N);
	for(int i=0; i<N; ++i) {
		int u = root[i], v = root[i + N];
		if(u == v) {
			answer[i] = sz[u] - 1;
		}
		else {
			int U = min(u, v);
			int V = max(u, v);
			answer[i] = sz[root[i]] + sz[root[i + N]] - overlap[{U, V}] - 1;
		}
	}
	return answer;
}
