#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;
const int INF = 1e9 + 100;

int a[MxN], cnt[MxN], idx[MxN];

inline void solve() {
	int n, k;
	cin >> n >> k;
	for(int i=0; i<k; ++i) {
		cnt[i] = 0;
		idx[i] = INF;
	}
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		cnt[a[i] % k]++;
		idx[a[i] % k] = min(idx[a[i] % k], i);
	}
	bool ok = false;
	for(int i=0; i<k; ++i) {
		if(cnt[i] == 1) {
			ok = true;
			cout << "YES\n" << idx[i] << "\n";
			break;
		}
	}
	if(!ok) {
		cout << "NO\n";
	}
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
