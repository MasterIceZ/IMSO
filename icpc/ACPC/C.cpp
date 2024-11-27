#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct node_t {
	ll val;
	int cnt;
	node_t(ll _val=0ll, int _cnt=0):
		val(_val), cnt(_cnt) {}
	friend node_t operator + (const node_t lhs, const node_t rhs) {
		return node_t(lhs.val + rhs.val, lhs.cnt + rhs.cnt);
	}
};

struct segment_tree {
	node_t t[MxN << 2];
	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = node_t();
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
	}
	void update(int l, int r, int id, node_t v, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			t[idx] = t[idx] + v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
	}
	int find(int l, int r, ll x, int idx) {
		if(l == r) {
			if(x >= t[idx].val) {
				return t[idx].cnt;
			}
			return 0;
		}
		int mid = (l + r) >> 1;
		if(x < t[idx << 1].val) {
			return find(l, mid, x, idx << 1);
		}
		else {
			return t[idx << 1].cnt + find(mid + 1, r, x - t[idx << 1].val, idx << 1 | 1);
		}
	}
};

pair<int, int> a[MxN], b[MxN];
segment_tree seg;

inline void solve() {
	int n, d;
	cin >> n >> d;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].first;
	}
	for(int i=1; i<=n; ++i) {
		cin >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i) {
		b[i] = make_pair(a[i].second, i);
	}
	sort(b + 1, b + n + 1);
	vector<int> ps(n + 1);
	for(int i=1; i<=n; ++i) {
		ps[b[i].second] = i;
	}
	int answer = 0;
	seg.build(1, n, 1);
	for(int i=1, last=0; i<=n; ++i) {
		d -= a[i].first - last;
		last = a[i].first;
		if(d < 0) {
			break;
		}
		seg.update(1, n, ps[i], node_t(a[i].second, 1), 1);
		answer = max(answer, seg.find(1, n, d, 1));
	}
	cout << answer << "\n";
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
