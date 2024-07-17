#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;

struct fenwick_tree {
	double t[MxN];
	void update(int idx, double v) {
		for(; idx<MxN; idx+=idx&-idx) {
			t[idx] += v;
		}
	}
	double query(int idx) {
		double res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

fenwick_tree fw;
vector<int> adj[MxN];
int tin[MxN], tout[MxN], timer;
double v[MxN];

void dfs(int u, int p) {
	tin[u] = ++timer;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
	}
	tout[u] = timer;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x;
			double y;
			cin >> x >> y;
			fw.update(tin[x], (double) log(y) - v[x]);
			v[x] = log(y);
		}
		else {
			int x, y;
			cin >> x >> y;
			double x_val = fw.query(tout[x]) - fw.query(tin[x] - 1);
			double y_val = fw.query(tout[y]) - fw.query(tin[y] - 1);
			double res = min(log(1e9), x_val - y_val);
			cout << fixed << setprecision(10) << exp(res) << "\n";
		}
	}
	return 0;
}
