#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int parent[MxN], cnt[MxN];
set<int> st[MxN];
stack<pair<int, int>> oprs;
vector<int> answer;

void merge(int u, int v) {
	if(st[u].size() < st[v].size()) {
		swap(st[u], st[v]);
	}
	for(auto x: st[v]) {
		st[u].emplace(x);
	}
}

int find_root(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void unite(int u, int v) {
	int ru = find_root(u), rv = find_root(v);
	if(ru == rv) {
		return ;
	}
	parent[ru] = rv;
	merge(ru, rv);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	for(int i=1, c; i<=n; ++i) {
		cin >> c;
		st[i].emplace(c);
		parent[i] = i;
	}

	for(int i=1, opr, x; i<=q; ++i) {
		cin >> opr >> x;
		oprs.emplace(opr, x);
		if(opr == 1) {
			cnt[x]++;
		}
	}

	for(int i=1; i<n; ++i) {
		if(cnt[i] != 0) {
			continue;
		}
		unite(i, i + 1);
	}

	while(!oprs.empty()) {
		pair<int, int> cur_opr = oprs.top();
		oprs.pop();

		if(cur_opr.first == 1) {
			if(--cnt[cur_opr.second] != 0) {
				continue;
			}
			unite(cur_opr.second, cur_opr.second + 1);
		}
		else {
			answer.emplace_back((int) st[find_root(cur_opr.second)].size());
		}
	}
	reverse(answer.begin(), answer.end());

	for(auto x: answer) {
		cout << x << "\n";
	}

	return 0;
}
