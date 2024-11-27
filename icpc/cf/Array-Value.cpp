#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using node_t = array<int, 2>;

const int MxB = (1 << 30) - 1;
const int MxN = 200020;

struct trie_t {
	vector<node_t> t = {node_t()};
	vector<int> cnt = {0};
	int cnt_nodes = 0;

	int get_bit(int b, int i) {
		return (b & (1 << i)) ? 1: 0;
	}

	void remove(int v) {
		int cur = 0;
		cnt[0]--;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			cnt[t[cur][bit]]--;
			cur = t[cur][bit];
		}
		cnt[cur]--;
	}

	void insert(int v) {
		int cur = 0;
		cnt[0]++;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(!t[cur][bit]) {
				t[cur][bit] = ++cnt_nodes;
				t.emplace_back(node_t());
				cnt.emplace_back(0);
			}
			cnt[t[cur][bit]]++;
			cur = t[cur][bit];
		}
		cnt[cur]++;
	}
	
	int get_min(int v) {
		int cur = 0, res = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(t[cur][bit] && cnt[t[cur][bit]]) {
				cur = t[cur][bit];
			}
			else {
				res |= (1 << i);
				cur = t[cur][!bit];
			}
		}
		return res;
	}
};

int n, a[MxN];
ll k;

inline bool ok(ll mid) {
	trie_t trie;
	ll cur = 0ll;
	for(int l=1, r=1; r<=n; ++r) {
#ifdef ICY
		if(r <= 4) {
			cerr << "D: " << trie.cnt[0] << "\n";
		}
#endif
		while(trie.cnt[0] > 0 && trie.get_min(a[r]) <= mid) {
			trie.remove(a[l++]);
		}
		cur += (ll) l - 1ll;
		trie.insert(a[r]);
	}
	return cur >= k;
}

inline void solve() {
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	ll l = 0, r = (ll) MxB;
	while(l < r) {
		ll mid = (l + r) >> 1ll;
		if(ok(mid)) {
			r = mid;
		}
		else {
			l = mid + 1ll;
		}
	}
	cout << l << "\n";
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
