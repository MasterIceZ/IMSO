#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;

struct fenwick_tree {
	int t[MxN];
	void update(int idx, int v) {
		for(; idx<MxN; idx+=idx&-idx) {
			t[idx] += v;
		}
	}
	int query(int idx) {
		int res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

string s;
int n, m, mem[MxN];
vector<pair<int, int>> queries[MxN];
fenwick_tree fw;
stack<int> st;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> s >> m;
	n = (int) s.size();
	s = " " + s;
	for(int i=1, l, r; i<=m; ++i) {
		cin >> l >> r;
		queries[r].emplace_back(l, i);
	}
	for(int i=1; i<=n; ++i) {
		if(s[i] == '(') {
			st.emplace(i);
		}
		else if(s[i] == ')' && !st.empty()) {
			int upd_idx = st.top();
			st.pop();
			fw.update(upd_idx, 1);
		}
		for(auto query: queries[i]) {
			mem[query.second] = 2 * (fw.query(i) - fw.query(query.first - 1));
		}
	}
	for(int i=1; i<=m; ++i) {
		cout << mem[i] << "\n";
	}
	return 0;
}
