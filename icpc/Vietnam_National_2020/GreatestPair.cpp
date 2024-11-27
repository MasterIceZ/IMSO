#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const int MxV = 500050;
const int LG = 22;

int n, timer, parent[MxN], tin[MxN], tout[MxN], it, a[MxN], rev_a[MxN], level[MxN], lg[MxN];
int rmq[LG][MxN];
ll w, dist[MxN];
vector<int> divide_able[MxV], dividing[MxV];
vector<pair<int, ll>> adj[MxN];

void dfs(int u, int p) {
	tin[u] = ++timer;
	parent[u] = p;
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		dist[v] = dist[u] + w;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
	tout[u] = ++timer;
	++it;
	a[it] = u;
	rev_a[u] = it;
}

int get_lca(int u, int v) {
	if(tout[u] > tout[v]) {
		swap(u, v);
	}
	if(tin[v] <= tin[u] && tout[u] <= tout[v]) {
		return v;
	}
	int lvl = lg[rev_a[v] - rev_a[u] + 1];
	int l_p = rev_a[u];
	int r_p = rev_a[v] - (1 << lvl) + 1;
	int dist_1 = level[rmq[lvl][l_p]];
	int dist_2 = level[rmq[lvl][r_p]];

	if(dist_1 < dist_2) {
		return parent[rmq[lvl][l_p]];
	}
	return parent[rmq[lvl][r_p]];
}

ll get_dist(int u, int v) {
	int lca = get_lca(u, v);
	return dist[u] + dist[v] - 2ll * dist[lca];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	for(int i=1; i<MxV; ++i) {
		for(int j=i; j<MxV; j+=i) {
			divide_able[j].emplace_back(i);
		}
	}

	while(true) {
		cin >> n;
		if(n == 0) {
			break;
		}
		
		lg[0] = lg[1] = 0;
		for(int i=2; i<=n; ++i) {
			lg[i] = lg[i / 2] + 1;
		}
		for(int i=0; i<=n; ++i) {
			adj[i].clear();
		}

		set<int> st;
		for(int i=1, v; i<=n; ++i) {
			cin >> v;
			for(auto x: divide_able[v]) {
				dividing[x].emplace_back(i);
				st.emplace(x);
			}
		}
		for(int i=2, u, v; i<=n; ++i) {
			cin >> u >> v >> w;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}

		timer = it = 0;
		dfs(1, 1);
		for(int i=1; i<=n; ++i) {
			rmq[0][i] = a[i];
		}
		for(int state=1; state<LG; ++state) {
			int last_sz = (1 << (state - 1));
			for(int i=1; i<=n; ++i) {
				rmq[state][i] = rmq[state - 1][i];
				if(i + last_sz <= n && level[rmq[state - 1][i + last_sz]] < level[rmq[state - 1][i]]) {
					rmq[state][i] = rmq[state - 1][i + last_sz];
				}
			}
		}
		ll answer = 1ll;
		for(auto v: st) {
			if((int) dividing[v].size() < 2) {
				continue;
			}
			ll diameter = 0;
			int k = dividing[v][1];
			for(auto x: dividing[v]) {
				ll cur_dist = get_dist(dividing[v][0], x);
				if(cur_dist > diameter) {
					k = x;
					diameter = cur_dist;
				}
			}
			if(k == -1) {
				continue;
			}
			for(auto x: dividing[v]) {
				diameter = max(diameter, get_dist(x, k));
			}
			answer = max(answer, (ll) (((ll) (v)) * diameter));
		}
		cout << answer << "\n";
		for(auto v: st) {
			dividing[v].clear();
		}
	}
	return 0;
}
