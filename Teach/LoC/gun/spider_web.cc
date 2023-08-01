#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MxN = 100010;
const int LgN = 20;

int n, q, level[MxN], u, v;
vector<pair<int, ll>> adj[MxN];
int lift[LgN][MxN];
ll dist[MxN], w, answer;

void dfs(int u, int p) {
    level[u] = level[p] + 1;
    lift[0][u] = p;
    for(auto x: adj[u]) {
        if(x.first == p || level[x.first]) {
            continue;
        }
		dist[x.first] = dist[u] + x.second;
        dfs(x.first, u);
    }
}

int getLCA(int u, int v) {
	if(level[u] > level[v]) {
	    swap(u, v);
	}
	for(int state=LgN-1; state>=0; --state) {
	    if(level[u] > level[lift[state][v]]) {
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=2; i<=n; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
	dfs(1, 0);
    for(int state=1; state<LgN; ++state) {
        for(int i=1; i<=n; ++i) {
            lift[state][i] = lift[state - 1][lift[state - 1][i]];
        }
    }
    while(q--) {
        cin >> u >> v;
		cout << dist[u] + dist[v] - 2 * dist[getLCA(u, v)] << "\n";
    }
    return 0;
}
