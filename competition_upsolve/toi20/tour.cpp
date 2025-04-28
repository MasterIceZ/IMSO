#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;
const ll INF = 1e18 + 100ll;

struct state_t {
	int v;
	ll a, b;
	state_t(int _v, ll _a, ll _b):
		v(_v), a(_a), b(_b) {}
};

struct vertex_t {
	int v, state;
	ll w;
	vertex_t(int _v, int _state, int _w):
		v(_v), state(_state), w(_w) {}
};

int n, m, l, num_points;
vector<vertex_t> adj[MxN];
vector<pair<ll, ll>> points, strip;
ll a;
queue<state_t> q;

inline void make_points() {
	q.emplace(1, 0, 0);
	while(!q.empty()) {
		auto [u, a, b] = q.front();
		q.pop();
		if(u == n) {
			points.emplace_back(a, b);
			continue;
		}		
		for(auto [v, state, w]: adj[u]) {
			if(state == 1) {
				q.emplace(v, a + w, b);
			}
			else {
				q.emplace(v, a, b + w);
			}
		}
	}
}

inline ll get_dist(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

ll closest_pair(int l, int r) {
	if(r - l + 1 <= 3) {
		ll res = INF;
		for(int i=l; i<=r; ++i) {
			for(int j=i+1; j<=r; ++j) {
				res = min(res, get_dist(points[i], points[j]));
			}
		}
		return res;
	}
	int mid = (l + r) >> 1;
	ll d = min(closest_pair(l, mid), closest_pair(mid + 1, r));
	strip.clear();
	for(int i=l; i<=r; ++i) {
		if(abs(points[i].first - points[mid].first) >= d) {
			continue;
		}
		strip.emplace_back(points[i]);
	}
	sort(strip.begin(), strip.end(), [&] (const pair<ll, ll> &a, const pair<ll, ll> &b) {
		if(a.second != b.second) {
			return a.second < b.second;
		}
		return a.first < b.first;
	});
	for(int i=0; i<(int) strip.size(); ++i) {
		for(int j=i+1; j<(int) strip.size() && strip[j].second - strip[j].second < d; ++j) {
		   d = min(d, get_dist(strip[i], strip[j]));
		}	   
	}
	return d;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m >> l;
	for(int i=1, _; i<=l; ++i) {
		cin >> _;
	}
	for(int i=1, u, v, s; i<=m; ++i) {
		cin >> u >> v >> s >> a;
		adj[u].emplace_back(v, s, a);
	}
	make_points();
	sort(points.begin(), points.end());
	num_points = (int) points.size();
	cout << closest_pair(0, num_points - 1);
	return 0;
}
