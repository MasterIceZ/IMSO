#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> factors[MxN];
vector<long long> pos[MxN];
long long a[MxN];

inline void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; ++i) {
		scanf("%lld", &a[i]);
		pos[a[i]].emplace_back(i);
	}
	while(q--) {
		long long k, l, r, res = 0ll;
		scanf("%lld %lld %lld", &k, &l, &r);
		r += 1ll;
		while(l < r) {
			long long np = r;
			for(auto factor: factors[k]) {
				auto it = lower_bound(pos[factor].begin(), pos[factor].end(), (int) l);
				if(it == pos[factor].end()) {
					continue;
				}
				np = min(np, (long long) *it);
			}
			res += k * (np - l);
			l = np;
			if(l < r) {
				while(k % a[l] == 0ll) {
					k /= a[l];
				}
			}
		}
		printf("%lld\n", res);
	}
	for(int i=1; i<MxN; ++i) {
		pos[a[i]].clear();
	}
	return ;
}

signed main(int argc, char *argv[]) {
	for(int i=2; i<MxN; ++i) {
		for(int j=i; j<MxN; j+=i) {
			factors[j].emplace_back(i);
		}
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}
