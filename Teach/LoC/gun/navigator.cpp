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

const int MxN = 550;

int n, m, u, v;
ll w, dist[MxN][MxN];

inline ll getAnswer(int exclude) {
	ll minn = 1e18 + 100, maxx = -1e18 - 100;
	for(int i=1; i<=n; ++i) {
		if(i == exclude) {
			continue;
		}
		minn = min(minn, dist[exclude][i]);
		maxx = max(maxx, dist[exclude][i]);
	}
	return maxx - minn;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=n; ++i) {
		dist[i][i] = 0ll;
	}
	for(int i=1; i<=m; ++i) {
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
	}
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i=1; i<=n; ++i) {
		cout << getAnswer(i) << "\n";
	}
	return 0;
}
