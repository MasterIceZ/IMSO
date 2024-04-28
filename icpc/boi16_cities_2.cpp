#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxK = 7;
const int MxN = 100010;

struct state_t {
	int v;
	ll w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, ll _w):
		v(_v), w(_w) {}
};

int a[MxK];
vector<pair<int, ll>> adj[MxN];
ll dist[1 << MxK][MxN], w;
priority_queue<state_t> pq;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> k >> m;
	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<k; ++i) {
		cin >> a[i];
		dist[1 << i][a[i]] = 0;
	}
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	int max_mask = (1 << k) - 1;
	for(int mask=1; mask<=max_mask; ++mask) {
		for(int i=0; i<k; ++i) {
			int this_mask = (1 << i);
			if(!(mask & this_mask)) {
				continue;
			}
			int without_this = (mask ^ this_mask);
			for(int t=1; t<=n; ++t) {
				dist[mask][t] = min(dist[mask][t], dist[this_mask][t] + dist[without_this][t]);
			}
		}
		for(int i=1; i<=n; ++i) {
			pq.emplace(i, dist[mask][i]);
		}
		while(!pq.empty()) {
			state_t now = pq.top(); pq.pop();
			for(auto x: adj[now.v]) {
				ll nxt = x.second + now.w;
				if(dist[mask][x.first] > nxt) {
					pq.emplace(x.first, dist[mask][x.first] = nxt);
				}
			}
		}
	}
	cout << *min_element(dist[max_mask] + 1, dist[max_mask] + n + 1) << "\n";
	return 0;
}
