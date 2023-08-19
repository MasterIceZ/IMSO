#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct state_t {
	int v;
	ll w;
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
	state_t(int _v, ll _w):
		v(_v), w(_w) {}
};

const int MxN = 10010;

int n, m, q, stp, x;
ll w, dist[MxN];
vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m >> q >> stp;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(stp, dist[stp] = 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now.v]) {
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	while(q--) {
		cin >> x;
		cout << dist[x] << "\n";
	}
	return 0;
}
