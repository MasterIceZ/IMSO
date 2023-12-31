#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

struct state_t {
	int v, w, cur_fuel;
	bool used;
	state_t(int _v, int _w, int _cur_fuel, bool _used):
		v(_v), w(_w), cur_fuel(_cur_fuel), used(_used) {}
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
};

int p[MxN], dist[2][MxN][MxN];
vector<pair<int, int>> adj[MxN];
priority_queue<state_t> pq;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, s, d, f, m;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> p[i];
	}
	cin >> s >> d >> f >> m;
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(s, dist[0][0][s] = 0, 0, false);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		if(now.cur_fuel + 1 <= f && dist[now.used][now.cur_fuel + 1][now.v] > now.w + p[now.v]) {
			pq.emplace(now.v, dist[now.used][now.cur_fuel + 1][now.v] = now.w + p[now.v], now.cur_fuel + 1, now.used);
		}
		if(now.used == false && dist[true][f][now.v] > now.w) {
			pq.emplace(now.v, dist[true][f][now.v] = now.w, f, true);
		}
		for(auto x: adj[now.v]) {
			int next_fuel = now.cur_fuel - x.second;
			if(next_fuel >= 0 && dist[now.used][next_fuel][x.first] > now.w) {
				pq.emplace(x.first, dist[now.used][next_fuel][x.first] = now.w, next_fuel, now.used);
			}
		}
	}
	cout << dist[true][f][d] << "\n";
	return 0;
}
