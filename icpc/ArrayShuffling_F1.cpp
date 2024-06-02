#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

pair<int, int> a[MxN];
int b[MxN];

inline void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	int rot = 0;
	for(int l=1, r=1; l<=n; l=r, r=l) {
		while(r <= n && a[l].first == a[r].first) {
			++r;
		}
		rot = max(rot, r - l);
	}
	for(int i=1; i<=n; ++i) {
		int from_pos = (i + rot - 1) % n + 1;
		b[a[i].second] = a[from_pos].first;
	}
	for(int i=1; i<=n; ++i) {
		cout << b[i] << " ";
	}
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
