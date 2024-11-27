#include <bits/stdc++.h>

using namespace std;

const double INF = 1e18;
const int MxN = 100010;

struct point_t {
	double x, y, z;
	point_t(double _x=0.0, double _y=0.0, double _z=.0.0):
		x(_x), y(_y), z(_z) {}
};

struct state_t {
	int v;
	double w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, double _w):
		v(_v), w(_w) {}
};

point_t p[MxN];
double dist[MxN];
vector<pair<int, double>> adj[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}

	auto pow2(double v) {
		return v * v;
	};

	auto find_dist(point_t a, point_t b) {
		return sqrt(pow2(a.x - b.x) + pow2(a.y - b.y) + pow2(a.z - b.z));
	};

	for(int i=1; i<=m; ++i) {
		cin >> u >> v;
		double w = find_dist(p[u], p[v]);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i) {
		dist[i] = INF;
	}
	pq.emplace(1, dist[1] = 0.0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto [v, w]: adj[now.v]) {
			double nxt = now.w + w;
			if(dist[v] > nxt) {
				pq.emplace(v, dist[v] = nxt);
			}
		}
	}
	return 0;
}
