#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int n;
ll max_l, w[MxN], h[MxN], dp[MxN];

struct segment_tree {
	ll tree[MxN << 2];
	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			tree[idx] = h[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
	}
	ll query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return 0ll;
		}
		if(wl <= l && r <= wr) {
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return max(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> max_l;
	for(int i=1; i<=n; ++i) {
		cin >> h[i] >> w[i];
		dp[i] = 1e18 + 100;
		w[i] = w[i - 1] + w[i];
	}
	seg.build(1, n, 1);
	for(int l=1; l<=n; ++l) {
		for(int r=l-1; w[l] - w[r] <= max_l && r >= 0; --r) {
			dp[l] = min(dp[l], dp[r] + seg.query(1, n, r + 1, l, 1));
		}
	}
	cout << dp[n] << "\n";
	return 0;
}

// int main() {
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
//	int q;
//	cin >> q;
//	while(q--) {
//		cin >> n >> max_l;
//		for(int i=1; i<=n; ++i) {
//			cin >> w[i];
//			dp[i] = 1e18 + 100;
//			w[i] = w[i - 1] + w[i];
//		}
//		for(int i=1; i<=n; ++i) {
//			cin >> h[i];
//		}
//		//continue;
//		seg.build(1, n, 1);
//		for(int l=1; l<=n; ++l) {
//			for(int r=l-1; w[l] - w[r] <= max_l && r >= 0; --r) {
//				dp[l] = min(dp[l], dp[r] + seg.query(1, n, r + 1, l, 1));
//			}
//		}
//		cout << dp[n] << "\n";
//	}
//	return 0;
//}
