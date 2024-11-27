#include <bits/stdc++.h>

using namespace std;
using node_t = array<int, 2>;

const int MxN = 200020;

struct trie_t {
	vector<node_t> t = {node_t()};
	vector<int> cnt = {0};
	int cnt_nodes = 0;

	int get_bit(int b, int i) {
		return (b & (1 << i)) ? 1: 0;
	}

	void insert(int v, int d) {
		int cur = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(!t[cur][bit]) {
				t[cur][bit] = ++cnt_nodes;
				t.emplace_back(node_t());
				cnt.emplace_back(0);
			}
			cnt[t[cur][bit]] += d;
			cur = t[cur][bit];
		}
	}
	
	int get_max(int v) {
		int cur = 0, res = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(t[cur][!bit] && cnt[t[cur][!bit]]) {
				res |= (1 << i);
				cur = t[cur][!bit];
			}
			else {
				cur = t[cur][bit];
			}
		}
		return res;
	}
};

vector<pair<int, int>> adj[MxN];
int dist[MxN], even[MxN];

void dfs(int u, int p) {
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		dist[v] = dist[u] ^ w;
		even[v] = even[u] ^ 1;
		dfs(v, u);
	}
}

inline void solve() {
	int n, q;
	cin >> n >> q;
	for(int i=2, u, v, w; i<=n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs(1, 0);
	trie_t t_1, t_2;
	for(int i=1; i<=n; ++i) {
		if(even[i] == false) {
			t_1.insert(dist[i], 1);
		}
		else {
			t_2.insert(dist[i], 1);
		}
	}
	int sum_xor = 0;
	while(q--) {
		char opr;
		cin >> opr;
		if(opr == '^') {
			int x;
			cin >> x;
			sum_xor ^= x;
		}
		else {
			int v, x, same, diff;
			cin >> v >> x;
			if(!even[v]) {
				t_1.insert(dist[v], -1);
				same = t_1.get_max(dist[v] ^ x);
				diff = t_2.get_max(dist[v] ^ x ^ sum_xor);
				t_1.insert(dist[v], 1);
			}
			else {
				t_2.insert(dist[v], -1);
				diff = t_1.get_max(dist[v] ^ x ^ sum_xor);
				same = t_2.get_max(dist[v] ^ x);
				t_2.insert(dist[v], 1);
			}
			cout << max(same, diff) << " ";
		}
	}
	cout << "\n";
	for(int i=1; i<=n; ++i) {
		adj[i].clear();
	}
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
