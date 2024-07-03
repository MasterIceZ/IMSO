#include <bits/stdc++.h>
#include "magic.h"

using namespace std;

const int MxN = 200020;

int w[MxN], dist[MxN];
vector<pair<int, int>> adj[MxN];
vector<int> answer;

void dfs(int u) {
	for(auto [v, i]: adj[u]) {
		if(dist[v] <= dist[u] + w[i]) {
			continue;
		}
		dist[v] = dist[u] + w[i];
		dfs(v);
	}
}

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
	for(int i=0; i<=Q-1; ++i) {
		if(q[i][0] == 0) {
			w[q[i][1]] = 1;
		}
	}	
	for(int i=0; i<=M-1; ++i) {
		adj[V[i]].emplace_back(U[i], i);
	}
	for(int i=0; i<=N; ++i) {
		dist[0] = 11;
	}
	dist[0] = 0;
	dfs(0);

	reverse(q.begin(), q.end());
	for(auto query: q) {
		if(query[0] == 0) {
			answer.emplace_back(-1);
			w[query[1]] = 0;
			if(dist[U[query[1]]] <= dist[V[query[1]]]) {
				continue;
			}
			dist[U[query[1]]] = dist[V[query[1]]];
			dfs(U[query[1]]);
		}
		else {
			answer.emplace_back(dist[query[1]] <= query[2]);
		}
	}
	reverse(answer.begin(), answer.end());

	return answer;
}
