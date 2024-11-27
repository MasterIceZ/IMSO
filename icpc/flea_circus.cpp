#include <bits/stdc++.h>

using namespace std;

const int MxN = 5050;
const int LgN = 22;

vector<int> adj[MxN];
int lift[LgN][MxN], level[MxN];

void dfs(int u, int p) {
	level[u] = level[p] + 1;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		lift[0][v] = u;
		dfs(v, u);
	}
}

int get_lca(int u, int v) {
	if(level[u] > level[v]) {
		swap(u, v);
	}
	for(int state=LgN-1; state>=0; --state) {
		if(level[u] >= level[lift[state][v]]) {
			continue;
		}
		v = lift[state][v];
	}	
	if(u == v) {
		return u;
	}
	for(int state=LgN-1; state>=0; --state) {
		if(lift[state][u] == lift[state][v]) {
			continue;
		}
		u = lift[state][u];
		v = lift[state][v];
	}
	return lift[0][u];
}

int get_dist(int u, int v) {
	return level[u] + level[v] - 2 * level[get_lca(u, v)];
}

int get_kth(int u, int d) {
	for(int state=0; state<LgN; ++state) {
		if(d & (1 << state)) {
			u = lift[state][u];
		}
	}
	return u;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) {
			break;
		}
		for(int i=2, u, v; i<=n; ++i) {
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		dfs(1, 1);
		for(int state=1; state<LgN; ++state) {
			for(int i=1; i<=n; ++i) {
				lift[state][i] = lift[state - 1][lift[state - 1][i]]; 
			}
		}
		int q;
		cin >> q;
		while(q--) {
			int u, v;
			cin >> u >> v;
			int lca = get_lca(u, v);
			int dist_1 = get_dist(u, lca), dist_2 = get_dist(v, lca);
			int all_dist = dist_1 + dist_2;
			if(all_dist % 2 == 0) {
				cout << "The fleas meet at " << get_kth(u, all_dist / 2) << ".\n";
			}
			else {
				int new_dist = (all_dist + 1) / 2;
				int a = get_kth(u, new_dist);
				int b = get_kth(v, new_dist - 1);
				if(a > b) {
					swap(a, b);
				}	
				cout << "The fleas jump forever between " << a << " and " << b << ".\n";
			}
		}
		for(int i=1; i<=n; ++i) {
			adj[i].clear();
			for(int state=1; state<LgN; ++state) {
				lift[state][i] = 0;
			}
		}
	}
	return 0;
}
