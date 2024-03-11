#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

using namespace std;
using ll = long long;

const int MxN = 40040;
const int MxS = 1110;

struct state_t {
	int v;
	ll w;
	int mask;
	bool operator < (const state_t& o) const {
		if(w != o.w) {
			return w > o.w;
		}
		return mask < o.mask;
	}
	state_t(int _v, ll _w, int _mask):
		v(_v), w(_w), mask(_mask) {}
};

vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;
vector<int> c[MxN];
ll nxt, answer = 1e18 + 100ll, w, dist[MxS][MxN], cnt_bit[MxS];
bitset<MxN> visited[MxS];
bool can;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q, l, nxt_mask;
	cin >> n >> m >> l >> q;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	for(int i=0, x; i<l; ++i) {
		cin >> x;
		c[x].emplace_back(i);
	}
	int max_mask = (1 << l);
	for(int j=0; j<max_mask; ++j) {
		for(int i=1; i<=n; ++i) {
			dist[j][i] = 1e18 + 100ll;
		}
	}
	for(int i=0; i<max_mask; ++i) {
		cnt_bit[i] = __builtin_popcountll(i);
	}
	if(c[1].size() != 0 && q != 0) {
		pq.emplace(1, dist[1 << c[1][0]][1] = 0, 1 << c[1][0]);
	}
	pq.emplace(1, dist[0][1] = 0, 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		if(now.w != dist[now.mask][now.v] || visited[now.mask][now.v]) {
			continue;
		}
		visited[now.mask][now.v] = true;
		can = false;
		for(auto &b: c[now.v]) {
			if(!(now.mask & (1 << b))) {
				can = true;
				nxt_mask = (now.mask | (1 << b));
			}
		}
		for(auto &x: adj[now.v]) {
			nxt = now.w + x.second / (1ll << cnt_bit[now.mask]);
			if(dist[now.mask][x.first] > nxt) {
				pq.emplace(x.first, dist[now.mask][x.first] = nxt, now.mask);
			}
			if(!can || c[x.first].empty() || cnt_bit[now.mask] == q) {
				continue;
			}
			if(cnt_bit[nxt_mask] <= q && dist[nxt_mask][x.first] > nxt) {
				pq.emplace(x.first, dist[nxt_mask][x.first] = nxt, nxt_mask);
			}
		}
	}
	for(int i=0; i<max_mask; ++i) {
		if(cnt_bit[i] > q) {
			continue;
		}
		answer = min(answer, dist[i][n]);
	}
	cout << answer << "\n";
	return 0;
}
