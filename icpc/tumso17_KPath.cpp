#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<pair<int, int>> adj[MxN];
int k, answer = 1e9 + 100, sz[MxN];
multiset<int> st;
bool used[MxN];
vector<int> pth;

int find_size(int u, int p) {
	sz[u] = 1;
	for(auto [v, w]: adj[u]) {
		if(v == p || used[v]) {
			continue;
		}
		sz[u] = find_size(v, u);
	}
	return sz[u];
}

int find_centroid(int u, int p, int tot) {
	for(auto [v, w]: adj[u]) {
		if(v == p || used[v]) {
			continue;
		}
		if(sz[v] * 2 > tot) {
			return find_centroid(v, u, tot);
		}
	}
	return u;
}

void dfs(int u, int p, int cur_w) {
	pth.emplace_back(cur_w);
	for(auto [v, w]: adj[u]) {
		if(v == p || used[v] || cur_w + w > k) {
			continue;
		}
		dfs(v, u, cur_w + w);
	}
}

void decom(int u) {
	u = find_centroid(u, 0, find_size(u, 0));
	used[u] = true;
	st.emplace(0);	
	for(auto [v, w]: adj[u]) {
		if(w <= k) {
			dfs(v, u, w);
		}
		for(auto x: pth) {
			auto it = st.lower_bound(k - x);
			if(it != st.end()) {
				answer = min(answer, *it - (k - x));
			}
			if(it != st.begin()) {
				answer = min(answer, (k - x) - *(--it));
			}
		}
		for(auto x: pth) {
			st.emplace(x);
		}
		pth.clear();
	}
	st.clear();
	for(auto [v, w]: adj[u]) {
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
	for(int i=2, u, v, w; i<=n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	decom(1);
	cout << answer << "\n";
	return 0;
}
