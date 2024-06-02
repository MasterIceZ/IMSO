#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MxN = 100010;

int a[MxN], answer[MxN];
vector<int> adj[MxN];
ordered_set<int> st[MxN];

inline void merge(int a, int b) {
	if(st[a].size() < st[b].size()) {
		swap(st[a], st[b]);
	}
	for(auto x: st[b]) {
		st[a].insert(x);
	}
}

void dfs(int u) {
	for(auto x: adj[u]) {
		dfs(x);
		merge(u, x);
	}
	answer[u] = (int) (st[u].size()) - st[u].order_of_key(a[u]);
	st[u].insert(a[u]);
}

signed main(int argc, char *argv[]) {
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=2, p; i<=n; ++i) {
		cin >> p;
		adj[p].emplace_back(i);
	}
	dfs(1);
	for(int i=1; i<=n; ++i) {
		cout << answer[i] << "\n";
	}
	return 0;
}
