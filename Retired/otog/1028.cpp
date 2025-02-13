#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const ll MOD = 123456789ll;

struct segment_tree {
	ll t[MxN << 2];
	void build(int l, int r, int idx, ll *arr) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = arr[l] % MOD;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1, arr);
		build(mid + 1, r, idx << 1 | 1, arr);
		t[idx] = (t[idx << 1] * t[idx << 1 | 1]) % MOD;
	}
	void update(int l, int r, int id, ll v, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			t[idx] = v % MOD;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = (t[idx << 1] * t[idx << 1 | 1]) % MOD;
	}
};

segment_tree seg;
ll a[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		a[i] = (a[i] + 
	}
	seg.build(1, n, 1, a);
	return 0;
}
