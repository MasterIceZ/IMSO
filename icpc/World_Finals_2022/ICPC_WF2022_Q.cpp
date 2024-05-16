#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;

struct fenwick_tree {
	ll t[MxN];

	void build(int N) {
		for(int idx = 0; idx<=N; ++idx) {
			t[idx] += 1ll;
			int nxt = idx + (idx & -idx);
			if(nxt < MxN) {
				t[nxt] += t[idx];
			}
		}
	}

	void update(int idx, ll v) {
		for(; idx<MxN; idx+=idx&-idx) {
			t[idx] += v;
		}
	}

	ll query(int idx) {
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
} fw;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	fw.build(n);
	ll answer = 2ll * n, x;
	for(int i=1, last = n + 1; i<=n; ++i) {
		cin >> x;
		fw.update(x, -1);
		answer += fw.query(n) - fw.query(min((int) x, last));
		last = x;
	}
	cout << fixed << setprecision(4) << ((double) answer) / 2.00 << "\n";
	return 0;
}
