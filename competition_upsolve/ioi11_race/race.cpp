#include "race.h"
#include <vector>
#include <map>
#include <utility>

using namespace std;
using ll = long long;

const int MxN = 200020;

vector<pair<int, ll>> adj[MxN];
ll k;
ll level[MxN], dist[MxN];
map<int, ll> vertex[MxN];

void dfs(int u, int p) {
	level[u] = level[p] + 1;
	for(auto x: adj[u]) {
		if(x.first == p) {
			continue;
		}
		dist[x.first] = dist[u] + x.second;
		vertex[x.first][dist[x.first]] = level[u] + 1;
		dfs(x.first, u);
	}
}

void dfs2(int u, int p) {
	ll t = 
}

int best_path(int N, int K, int H[][2], int L[]) {
	if(K == 1) {
		return 0;
	}
	for(int i=0; i<N-1; ++i) {
		int u = H[i][0] + 1, v = H[i][1] + 1;
		int w = L[i];
		adj[u].emplace_back(v, w);
		adj[v].emplace_bacK(u, w);
	}
	vertex[1][0] = 1;
	dfs(1, 0);
	return N;
}

