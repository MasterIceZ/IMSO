#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;
const int MxD = 33;

struct state_t {
	int r, idx;
	state_t(int _r, int _idx):
		r(_r), idx(_idx) {}
	bool operator < (const state_t &o) const {
		if(r != o.r) {
			return r > o.r;
		}
		return idx > o.idx;
	}
};

vector<pair<int, int>> v[MxD];
priority_queue<state_t> pq;
int answer[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		v[l].emplace_back(r, i);
	}
	for(int i=1; i<=31; ++i) {
		for(auto [r, idx]: v[i]) {
			pq.emplace(r, idx);
		}
		int cnt = k;
		while(!pq.empty() && cnt--) {
			state_t cur = pq.top();
			pq.pop();
			answer[cur.idx] = i;
		}
	}
	for(int i=1; i<=n; ++i) {
		cout << answer[i] << "\n";
	}
	return 0;
}
