#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
unordered_map<int, vector<int>> pos;
int a[MxN];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q, l, r, c;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back(i);
	}
	while(q--) {
		cin >> l >> r >> c;
		cout << upper_bound(pos[c].begin(), pos[c].end(), r) - lower_bound(pos[c].begin(), pos[c].end(), l) << "\n";
	}
	return 0;
}
