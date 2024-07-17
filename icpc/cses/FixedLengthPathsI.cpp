#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int k, sz[MxN];
ll answer, cnt[MxN];
vector<int> adj[MxN], pth;
bitset<MxN> used;

int find_size(int u, int p) {
	sz[u] = 1;
	for(auto v: adj[u]) {
		if(v == p || used[v]) {
			continue;
		}
		sz[u] += find_size(v, u);
	}
	return sz[u];
}

int find_centroid(int u, int p, int tot) {
	for(auto v: adj[u]) {
		if(v == p || used[v]) {
			continue;
		}
		if(sz[v] * 2 > tot) {
			return find_centroid(v, u, tot);
		}
	}
	return u;
}

void dfs(int u, int p, int d) {
	pth.emplace_back(d);
	for(auto v: adj[u]) {
		if(v == p || used[v]) {
			continue;
		}
		dfs(v, u, d + 1);
	}
}

void decom(int u) {
	u = find_centroid(u, 0, find_size(u, 0));
	used[u] = true;
	cnt[0] = 1;
	vector<int> all_path;
	for(auto v: adj[u]) {
		if(used[v]) {
			continue;
		}
		dfs(v, u, 1);
		for(auto x: pth) {
			if(k - x < 0) {
				continue;
			}
			answer += cnt[k - x];
		}
		for(auto x: pth) {
			if(x > k) {
				continue;
			}
			cnt[x]++;
		}
		for(auto x: pth) {
			all_path.emplace_back(x);
		}
		pth.clear();
	}
	for(auto x: all_path) {
		cnt[x]--;
	}
	for(auto v: adj[u]) {
		if(used[v]) {
			continue;
		}
		decom(v);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n >> k;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	decom(1);
	cout << answer << "\n";
	return 0;
}
