#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int parent[MxN], sz[MxN], last_change[MxN];

int find_root(int u, int ver) {
	if(parent[u] == u || last_change[u] > ver) {
		return u;
	}
	return find_root(parent[u], ver);
}

void unite(int u, int v, int ver) {
	int ru = find_root(u, ver);
	int rv = find_root(v, ver);
	if(ru == rv) {
		return ;
	}
	if(sz[ru] > sz[rv]) {
		swap(ru, rv);
	}
	sz[rv] += sz[ru];
	parent[ru] = rv;
	last_change[ru] = ver;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i=1; i<=n; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}

	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		unite(u, v, i);
	}


	while(q--) {
		int u, v, l = 0, r = m;
		cin >> u >> v;

		auto check = [&](int mid) {
			return find_root(u, mid) == find_root(v, mid);
		};

		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(mid)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		cout << (check(l) ? l: -1) << "\n";
	}

	return 0;
}
