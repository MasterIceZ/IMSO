#include <vector>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int sz[MxN], heavy[MxN], head[MxN], parent[MxN], level[MxN], disc[MxN], timer;

void dfs_sz(int u, int p) {
	sz[u] = 1;
	level[u] = level[p] + 1;
	parent[u] = p;
	int cur_heavy = 0, cur_max = 0;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs_sz(v, u);
		sz[u] += sz[v];
		if(cur_max < sz[v]) {
			cur_max = sz[v];
			cur_heavy = v;
		}
	}
	heavy[u] = cur_heavy;
}

void dfs_hld(int u, int p) {
	if(head[u] == 0) {
		head[u] = u;
	}
	disc[u] = ++timer;
	if(heavy[u] != 0) {
		head[heavy[u]] = head[u];
		dfs_hld(heavy[u], u);
	}
	for(auto v: adj[u]) {
		if(v == p || v == heavy[u]) {
			continue;
		}
		dfs_hld(v, u);
	}
}

int lca(int u, int v) {

}
